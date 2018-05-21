from django.db import models

# Create your models here.

# title varchar(40) not null,
#     content text,
#     input text,
#     output text,
#     test_input text,
#     test_output text,
#     passing_rate int default 0,
#     passing_people_count int default 0,
#     trying_people_count int default 0,
#     time_limit int,
#     memory_limit int,
#     topic_level int,
#     created_time timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
#     last_updated_time timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE

class TopicInfo(models.Model):
    title = models.CharField(max_length=40)
    content = models.TextField()
    input = models.TextField()
    output = models.TextField()
    test_input = models.TextField()
    test_output = models.TextField()
    passing_rate = models.IntegerField()
    passing_people_count = models.IntegerField()
    trying_people_count = models.IntegerField()
    time_limit = models.IntegerField()
    memory_limit = models.IntegerField()
    topic_level = models.IntegerField()
    created_time = models.DateTimeField(auto_now_add=True)
    last_updated_time = models.DateTimeField(auto_now=True)
    isDelete = models.BooleanField(default=False)

    def __str__(self):
        return self.title.encode("utf-8")
    # gtype = models.ForeignKey(TypeInfo)
    # gadv = models.BooleanField(default=False)
    # def __str__(self):
        # return self.gtitle.encode('utf-8')