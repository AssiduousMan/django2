from django.conf.urls import url
import views

urlpatterns = [
    url(r'^register/$', views.register),
    url(r'^register_handle/$', views.register_handle),
    url(r'^login/$', views.user_login),
    url(r'^login_handle/$', views.login_handle),
    url(r'^checknumber_(\d+)/$', views.checkNumber),
    url(r'^toEditUser_(\d+)/$', views.toEditUser),
    url(r'^submitEditUserInfo/$', views.submitEditUserInfo),


    # url(r'^register_exist/$', views.register_exist),
    # url(r'^order/$', views.order),
    # url(r'^site/$', views.site),
    url(r'^logout/$', views.logout)
]