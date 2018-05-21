# coding=utf-8  
from ctypes import *
import filecmp
import sys
import time
from threading import Thread
import os

if __name__ == '__main__':  

    flag = 0
    def connect():  # 要执行的函数  
	global flag
	#time.sleep(4)
	path = sys.argv[1]
	try:
	    dll = CDLL(path + "/1.so")
	    for i in range(3):
    	        dll.main()
	    flag = 1
	except:
	    flag = 1
	#print("asd")
  
    def timer_cal():
	count = 0
	global flag
	while True:
	    time.sleep(1)
	    #print(flag)
	    count += 1
	    #print(os.getpid())
            if flag == 1:
		return ""
	    if count == 3:
		print("timeout")
		with open(sys.argv[1] + '/student', 'w') as f:
		    f.write("timeout")
		os.system('kill -9 ' + str(os.getpid()))  # kill process
		#sys.exit()
		
    t = Thread(target=connect)
    t.start()
    tt = Thread(target=timer_cal)
    tt.start()    
#connect()
    

