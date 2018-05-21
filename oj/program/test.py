from ctypes import *
import filecmp
import sys
import time
path = sys.argv[1]
dll = CDLL(path + "/1.so")
for i in range(3):
    # call main function
    time.sleep(20)
    res_int = dll.main()

