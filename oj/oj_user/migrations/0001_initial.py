# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='UserInfo',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('number', models.CharField(max_length=8)),
                ('pwd', models.CharField(max_length=40)),
                ('name', models.CharField(max_length=20)),
                ('department', models.CharField(max_length=20)),
                ('major', models.CharField(max_length=20)),
                ('grade', models.IntegerField()),
                ('user_class', models.CharField(max_length=4)),
                ('mobile', models.CharField(max_length=11)),
                ('topic_process', models.TextField()),
                ('passing_topic_count', models.IntegerField(default=0)),
                ('created_time', models.DateTimeField(auto_now_add=True)),
                ('last_updated_time', models.DateTimeField(auto_now=True)),
                ('isDelete', models.BooleanField(default=False)),
            ],
        ),
    ]
