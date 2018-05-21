from django.db import models

# Create your models here.
class UserInfo(models.Model):
    number = models.CharField(max_length=8)
    pwd = models.CharField(max_length=40)
    name = models.CharField(max_length=20)
    department = models.CharField(max_length=20)
    major = models.CharField(max_length=20)
    grade = models.IntegerField()
    user_class = models.CharField(max_length=4)
    mobile = models.CharField(max_length=11)
    topic_process = models.TextField()
    passing_topic_count = models.IntegerField(default=0)
    created_time = models.DateTimeField(auto_now_add=True)
    last_updated_time = models.DateTimeField(auto_now=True)
    isDelete = models.BooleanField(default=False)
    # upwd = models.CharField(max_length=40)
    # uemail = models.CharField(max_length=30)
    # ushou = models.CharField(max_length=20, default='')
    # uaddress = models.CharField(max_length=100, default='')
    # uyoubian = models.CharField(max_length=6, default='')
    # uphone = models.CharField(max_length=11, default='')