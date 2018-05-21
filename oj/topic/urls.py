from django.conf.urls import url
import views
from views import *

urlpatterns = [
    url(r'^$', views.index),
    url(r'^toTopicList/$', views.toTopicList),
    url(r'^toShowSelectTopic_(\d+)/$', views.toShowSelectTopic),
    url(r'^submitProgram/$', views.submitProgram),
    url(r'^toShowTopicStatus/$', views.toShowTopicStatus),
    url(r'^toShowUserRanking/$', views.toShowUserRanking),
# submitProgram
    # url(r'^(\d+)/$', views.detail),
    # url(r'^search/', MySearchView())


]