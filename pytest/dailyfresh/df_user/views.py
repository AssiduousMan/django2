# coding=utf-8
from django.shortcuts import render, redirect
from models import *
from hashlib import sha1
from django.http import HttpResponse, JsonResponse, HttpResponseRedirect
import user_decorator
import sys
sys.path.append('../')
from df_goods.models import *
# Create your views here.


def register(request):
    context = {'title': '用户注册-天天生鲜'}
    return render(request, 'df_user/register.html', context)


def register_handle(request):
    post = request.POST
    uname = post.get('user_name')
    upwd = post.get('pwd')
    upwd2 = post.get('cpwd')
    uemail = post.get('email')

    if upwd != upwd2:
        return redirect('/user/register/')
    # pwd jia mi
    s1 = sha1()
    s1.update(upwd)
    upwd3 = s1.hexdigest()

    # chuan jian dui xiang
    user = UserInfo()
    user.uname = uname
    user.upwd = upwd3
    user.uemail = uemail
    user.save()
    # deng lu jie mian
    return redirect('/user/login/')


def register_exist(request):
    uname = request.GET.get('uname')
    count = UserInfo.objects.filter(uname=uname).count()
    return JsonResponse({'count': count})


def user_login(request):
    uname = request.COOKIES.get('uname', '')
    context = {'title': '用户登录-天天生鲜', 'error_name': 0, 'error_pwd': 0, 'uname': uname}
    return render(request, 'df_user/login.html', context)


def logout(request):
    request.session.flush()
    # del request.session['']
    return redirect('/')


def login_handle(request):
    post = request.POST
    name = post.get('username')
    pwd = post.get('pwd')
    jizhu = post.get('jizhu', 0)

    # jia mi
    s1 = sha1()
    s1.update(pwd)
    pwd2 = s1.hexdigest()

    userinfo = UserInfo.objects.filter(uname=name)
    if len(userinfo) > 0:
        userinfo = userinfo[0]
        if userinfo.upwd == pwd2:
            # 这个时候需要或取一下当前用户是从那个界面跳转过来的
            url = request.COOKIES.get('url', '/')
            red = HttpResponseRedirect(url)
            if jizhu != 0:
                # 记录一下用户信息
                red.set_cookie('uname', name)
            else:
                red.set_cookie('uname', '', max_age=-1)
            request.session['user_id'] = userinfo.id
            request.session['user_name'] = name
            # request.session.set_expiry(0)
            return red
        else:
            context = {'title': '用户登录-天天生鲜', 'error_name': 0, 'error_pwd': 1, 'uname': name, 'upwd': pwd}
            return render(request, 'df_user/login.html', context)
    else:
        context = {'title': '用户登录-天天生鲜', 'error_name': 1, 'error_pwd': 0, 'uname': name, 'upwd': pwd}
        return render(request, 'df_user/login.html', context)


@user_decorator.login
def info(request):
    user_email = UserInfo.objects.get(id=request.session['user_id']).uemail
    # 最近浏览
    goods_ids = request.COOKIES.get('goods_ids', '')
    goods_ids1 = goods_ids.split(',')
    goods_list = []
    for goods_id in goods_ids1:
        goods_list.append(GoodsInfo.objects.get(id=int(goods_id)));

    context = {'title': '用户信息-天天生鲜', 'page_name': 1,
               'user_name': request.session['user_name'],
               'user_email': user_email,
               'goods_list': goods_list
               }
    return render(request, 'df_user/user_center_info.html', context)


@user_decorator.login
def order(request):
    context = {'title': '用户订单-天天生鲜', 'page_name': 1}
    return render(request, 'df_user/user_center_order.html', context)


@user_decorator.login
def site(request):
    user = UserInfo.objects.get(id=request.session['user_id'])
    # 这个是修改的订单地址
    if request.method == 'POST':
        post = request.POST
        user.ushou = post.get('ushou')
        user.uaddress = post.get('uaddress')
        user.uyoubian = post.get('uyoubian')
        user.uphone = post.get('uphone')
        user.save()
    context = {'title': '用户地址-天天生鲜', 'page_name': 1, 'user': user}
    return render(request, 'df_user/user_center_site.html', context)