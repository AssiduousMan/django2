# coding=utf-8
from django.shortcuts import render,redirect
from django.db import transaction
from django.db import transaction
from models import *
from datetime import *
from decimal import Decimal
import sys
sys.path.append('../')
from df_user.models import *
from df_cart.models import *


# Create your views here.
def order(request):
    user_id = request.session.get('user_id')
    userinfo = UserInfo.objects.filter(id=user_id)[0]
    # print(userinfo.uname)
    cart_ids = request.GET.getlist('cart_id')
    cartinfolist = []
    for cart_id in cart_ids:
        cartinfo = CartInfo.objects.get(id=int(cart_id))
        cartinfolist.append(cartinfo)
        # print(cartinfo.id)

    context = {
        'title': '提交订单',
        'page_name': 1,
        'userinfo': userinfo,
        'cartinfolist': cartinfolist
    }

    return render(request, 'df_order/order.html', context)
    # print(cart_ids)

@transaction .atomic()
def order_handle(request):
    # 储存当前的点，方便数据回滚时使用
    tran_id = transaction.savepoint()
    cart_ids = request.POST.getlist('cart_id')
    try:
        # 创建订单对象
        order = OrderInfo()
        now = datetime.now()
        uid = request.session['user_id']
        order.oid = "%s%d" % (now.strftime('%Y%m%d%H%M%S'), uid)
        order.user_id = uid
        order.odate = now
        order.ototal = Decimal(request.POST.get('total'))
        order.save()

        for cart_id in cart_ids:
            # 创建详情订单对象
            detail = OrderDetailInfo()
            detail.order = order
            # 查询购物车信息
            cart = CartInfo.objects.get(id=cart_id)
            goods = cart.goods
            if goods.gkucun >= cart.count:
                # 减少商品库存
                goods.gkucun = cart.goods.gkucun - cart.count
                goods.save()
                # 完善详情信息
                detail.goods_id = goods.id
                detail.price = goods.gprice
                detail.count = cart.count
                detail.save()
                # 删除购物车数据
                cart.delete()
            else:  # 如果库存不够了
                transaction.savepoint_rollback(tran_id)
                return redirect('/cart/')
    except Exception as e:
        print('==============%s' % e)
        transaction.savepoint_rollback(transaction)
    return redirect('/user/order/')
        # pass
    # print(cart_ids)


