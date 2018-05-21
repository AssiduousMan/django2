# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='TopicInfo',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('title', models.CharField(max_length=40)),
                ('content', models.TextField()),
                ('input', models.TextField()),
                ('output', models.TextField()),
                ('test_input', models.TextField()),
                ('test_output', models.TextField()),
                ('passing_rate', models.IntegerField()),
                ('passing_people_count', models.IntegerField()),
                ('trying_people_count', models.IntegerField()),
                ('time_limit', models.IntegerField()),
                ('memory_limit', models.IntegerField()),
                ('topic_level', models.IntegerField()),
                ('created_time', models.DateTimeField(auto_now_add=True)),
                ('last_updated_time', models.DateTimeField(auto_now=True)),
                ('isDelete', models.BooleanField(default=False)),
            ],
        ),
    ]
