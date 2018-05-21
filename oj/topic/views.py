# coding=utf-8
from django.shortcuts import render, redirect
from models import *
import sys
sys.path.append('../')
from oj_user.user_decorator import login
from oj_user.models import *
from django.http import HttpResponse
import os
import time
from threading import Thread

# Create your views here.
def index(request):
    # return HttpResponse("index")
    context = {
        'title': '首页',
    }
    return render(request, 'topic/index.html', context)

@login
def toTopicList(request):
    topicList = TopicInfo.objects.all()
    number = request.session['user_number']
    userInfo = UserInfo.objects.filter(number=number)[0]
    topic_process = userInfo.topic_process
    context = {
        'topicList': topicList,
        'topic_process': topic_process,
    }

    return render(request, 'topic/topiclist.html', context)


# @user_decorator.login
@login
def toShowSelectTopic(request, id):
    topic = TopicInfo.objects.filter(id=int(id))[0]
    context={
        'topic': topic,
    }
    # def list(request, tid, pindex, sort):
    #     typeinfo = TypeInfo.objects.filter(id=int(tid))[0]
    #     news = typeinfo.goodsinfo_set.order_by('-id')[0:2]
    #     if sort == '1':  # 默认， 最新
    #         goods_list = typeinfo.goodsinfo_set.order_by('-id')
    #     elif sort == '2':  # 价格
    #         goods_list = typeinfo.goodsinfo_set.order_by('-gprice')
    #     elif sort == '3':  # 人气， 点击量
    #         goods_list = typeinfo.goodsinfo_set.order_by('-gclick')
    #     paginator = Paginator(goods_list, 10)
    #     page = paginator.page(int(pindex))
    #     context = {
    #         'title': typeinfo.ttitle, 'guest_cart': 1,
    #         'page': page,
    #         'paginator': paginator,
    #         'typeinfo': typeinfo,
    #         'sort': sort,
    #         'news': news
    #     }
    return render(request, 'topic/showselecttopic.html', context)

waitJudgeQueue = []

allTopicQueue = []


def judgeProgram():

    while len(waitJudgeQueue):
        global waitJudgeQueue
        global allTopicQueue
        temp = waitJudgeQueue[0].split('|')
        id = temp[0]  # 题号
        name = temp[1]  # 姓名   11111111111_1_15110103.c
        name_split_point = name.split(".")
        if(name_split_point[-1] == "cpp"):  # 说明是c++文件
            os.system("g++ -o program/" + id + "/1.so -shared -fPIC program/" + id + "/" + name);
        else:
            os.system("gcc -o program/" + id + "/1.so -shared -fPIC program/" + id + "/" + name);
        # time.sleep(0.1)
        test = os.popen("program/" + id + "/run.sh program/" + id)
        time.sleep(5)
        flag = 0
        with open("program/" + id + "/student", "r") as f1:
            first_line = f1.read()
            if(first_line == "timeout"):
                allTopicQueue.append(waitJudgeQueue[0] + "_TimeOut")
                waitJudgeQueue.pop(0)
                flag = 1
                # return ""
        if flag == 0:
            #     with open('program/' + id + "/timeout") as ff:
            #         ff.write("123")
            #     if first_line == "timeout":
            #         allTopicQueue.append(waitJudgeQueue[0] + "_TimeOut")
            #         waitJudgeQueue.pop(0)
            #         return ""

            with open("program/" + id + "/judge", "r") as f2:
                result = f2.read()
                if result == "True\n":
                    allTopicQueue.append(waitJudgeQueue[0] + "_True")

                    # 改变题目通过次数
                    topicInfo = TopicInfo.objects.filter(id=int(id))[0]
                    topicInfo.passing_people_count += 1
                    topicInfo.passing_rate = int(topicInfo.passing_people_count * 100 / topicInfo.trying_people_count)
                    topicInfo.save()

                    userInfo = UserInfo.objects.filter(number=name_split_point[0].split("_")[-1])[0]  # 取出学号,根据学号查询用户
                    topic_process = userInfo.topic_process# += (id + ",")  # 将做题情况上传到数据库
                    if (id + ",") in topic_process:  # 说明之前做对过这道题
                        pass
                    else:
                        userInfo.topic_process += (id + ",")
                        userInfo.passing_topic_count += 1
                    userInfo.save()
                    # with open("program/" + id + "/success", "w+") as f:
                    #     f.write(id + " " + name_split_point[0].split("_")[-1] + " " + name_split_point[-1])
                else:
                    allTopicQueue.append(waitJudgeQueue[0] + "_False")
                    # with open("program/" + id + "/fail", "w+") as f:
                    #     f.write("fail")
            os.popen("program/" + id + "/delete.sh program/" + id)
            # os.system("g++ -o program/1.so -shared -fPIC program/");
            with open("program/" + id + "/tt", "a+") as f3:
                f3.write("1  ")

            waitJudgeQueue.pop(0)




def submitProgram(request):
    global waitJudgeQueue
    post = request.POST
    time_chuo = str(int(round(time.time() * 1000)));  # shi jian chuo
    id = post.get("id")
    number = request.session['user_number']
    program = post.get("program")
    language = post.get("language")

    # 改变题目测试次数
    topicInfo = TopicInfo.objects.filter(id=int(id))[0]
    topicInfo.trying_people_count += 1
    topicInfo.passing_rate = int(topicInfo.passing_people_count * 100 / topicInfo.trying_people_count)
    topicInfo.save()

    if language == 'c++':
        language = 'cpp'
    name = time_chuo + "_" + id + "_" + str(number) + "." + language
    with open("program/" + id + "/" + name, "w") as f:
        f.write(program)

    if len(waitJudgeQueue):
        waitJudgeQueue.append(id + "|" + name)
        with open("program/t2", "a+") as f:
            f.write("没有开启新的线程" + str(len(waitJudgeQueue)))
    else:
        waitJudgeQueue.append(id + "|" + name)
        t = Thread(target=judgeProgram)
        t.start()


    # os.system("g++ -o 1.so -shared -fPIC 1.cpp" + id + )

    context = {}

    return redirect('/toShowTopicStatus')


def toShowTopicStatus(request):
    global allTopicQueue
    # context = {}
    if len(allTopicQueue) == 0:
        context = {}
        return render(request, 'topic/showtopicstatus.html', context)
    else:
        topicStatusList = []
        context = {}
        for topicStatus in reversed(allTopicQueue):
            global topicStatusList
            language = topicStatus.split('.')[-1].split("_")[0]
            name = topicStatus.split('.')[0].split('_')
            id = name[1]
            number = name[2]
            status = topicStatus.split('.')[-1].split("_")[1]
            topicInfo = TopicInfo.objects.filter(id=int(id))[0]
            temp = {
                'language': language,
                'number': number,
                'result': status,
                'topicInfo': topicInfo,
            }
            topicStatusList.append(temp)

        context['topicStatusList'] = topicStatusList

        return render(request, 'topic/showtopicstatus.html', context)

@login
def toShowUserRanking(request):
    userList = UserInfo.objects.all().order_by('-passing_topic_count')
    context = {'userList': userList}
    # for userInfo in userList:
    return render(request, 'topic/showuserranking.html', context)