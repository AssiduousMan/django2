# encoding:utf-8
from django.shortcuts import render, redirect
from models import *
from django.http import HttpResponse, JsonResponse, HttpResponseRedirect
# Create your views here.
import user_decorator

# @user_decorator.login
def register(request):
    context = {}
    return render(request, 'oj_user/register.html', context)

def register_handle(request):
    post = request.POST
    number = post.get('number')
    name = post.get('name')
    pwd = post.get('password')
    pwd2 = post.get('password2')
    # uemail = post.get('email')
    department = post.get('department')
    major = post.get('major')
    user_class = post.get("user_class")
    mobile = post.get('mobile')

    if pwd != pwd2:
        return redirect('/user/register/')
    # pwd jia mi
    # s1 = sha1()
    # s1.update(upwd)
    # upwd3 = s1.hexdigest()

    # chuan jian dui xiang
    user = UserInfo()
    user.number = number
    user.name = name
    user.pwd = pwd
    user.department = department
    user.major = major
    user.grade = 15
    user.user_class = user_class
    user.mobile = mobile
    # user.upwd = upwd3
    # user.uemail = uemail
    user.save()
    # deng lu jie mian
    return redirect('/user/login/')

def user_login(request):
    # uname = request.COOKIES.get('uname', '')
    # context = {'title': '用户登录-天天生鲜', 'error_name': 0, 'error_pwd': 0, 'uname': uname}
    context = {}
    return render(request, 'oj_user/login.html', context)

def login_handle(request):
    post = request.POST
    number = post.get('number')
    pwd2 = post.get('password')
    # jizhu = post.get('jizhu', 0)

    # jia mi
    # s1 = sha1()
    # s1.update(pwd)
    # pwd2 = s1.hexdigest()

    userinfo = UserInfo.objects.filter(number=number)
    if len(userinfo) > 0:
        userinfo = userinfo[0]
        if userinfo.pwd == pwd2:
            # 这个时候需要或取一下当前用户是从那个界面跳转过来的
            url = request.COOKIES.get('url', '/')
            red = HttpResponseRedirect('/')
            # if jizhu != 0:
            #     记录一下用户信息

            red.set_cookie('number', number)
            # else:
            #     red.set_cookie('uname', '', max_age=-1)
            request.session.set_expiry(0)
            request.session['user_id'] = userinfo.id
            request.session['user_number'] = number
            # request.session.set_expiry(0)
            return red
        else:
            context = {}
            return render(request, 'oj_user/login.html', context)
    else:
        context = {}
        return render(request, 'oj_user/login.html', context)

def logout(request):
    request.session.flush()
    red = HttpResponseRedirect('/')
    red.delete_cookie('number')
    # del request.session['']
    return red

def checkNumber(request, number):
    userInfoList = UserInfo.objects.filter(number=number)
    if len(userInfoList) == 0:
        return JsonResponse({'data': {'result': 'False'}})
    else:
        return JsonResponse({'data': {'result': 'True'}})

@user_decorator.login
def toEditUser(request, number):
    userInfo = UserInfo.objects.filter(number=number)[0]
    context = {'userInfo': userInfo}
    return render(request, 'oj_user/edituser.html', context)

def submitEditUserInfo(request):
    post = request.POST
    number = request.session['user_number']
    name = post.get('name')
    pwd = post.get('password')
    pwd2 = post.get('password2')
    # uemail = post.get('email')
    department = post.get('department')
    major = post.get('major')
    user_class = post.get("user_class")
    mobile = post.get('mobile')

    if pwd != pwd2:
        return redirect('/user/register/')
    # pwd jia mi
    # s1 = sha1()
    # s1.update(upwd)
    # upwd3 = s1.hexdigest()

    # chuan jian dui xiang
    user = UserInfo.objects.filter(number=number)[0]
    # user.number = number
    user.name = name
    user.pwd = pwd
    user.department = department
    user.major = major
    user.grade = 15
    user.user_class = user_class
    user.mobile = mobile
    # user.upwd = upwd3
    # user.uemail = uemail
    user.save()
    # deng lu jie mian
    return redirect('/user/login/')
