import filecmp
import sys
#path = sys.argv[1]
# xiao chu zui hou yi hang kong hang
stand = ""
student = ""
with open('stand', 'r') as f:
    #global stand
    lines = f.readlines()
    #print(lines)
    last_line = lines[-1]
    if last_line == "\n":
        stand = lines[:-1]
    #print(last_line)
with open('student', 'r') as f:
    #global student
    lines = f.readlines()
    #print(lines)
    last_line = lines[-1]
    #print(lines[-1])
    if last_line == "\n":
        student = lines[:-1]
        #print(student)
if stand != "":
    with open('stand', 'w') as f:
        for s in stand:
            f.write(s)
if student != "":
    with open('student', 'w') as f:
        for s in student:
            f.write(s)
print(filecmp.cmp(r'stand', r'student'))
