path=$1
python $(pwd)/${path}/test.py ${path} < $(pwd)/${path}/input > $(pwd)/${path}/student
python $(pwd)/${path}/judge.py ${path} > $(pwd)/${path}/judge
