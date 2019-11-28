import filecmp
import os

if os.path.exists("temp"):
    os.system("rm -rf ./temp")
os.makedirs("temp")
score = 0
for i in range(54):
    inst = "./python_interpreter testData/test" + str(i) + ".in > temp/test" + str(i) + ".out 2> /dev/null"
    print(inst)
    os.system(inst)
    if not filecmp.cmp("testData/test" + str(i) + ".out", "temp/test" + str(i) + ".out"):
        f = open("testData/test" + str(i) + ".in", mode='r')
        title = f.readline()[1:]
        print("test", i, "wrong:", title)
    else:
        score += 1
print("total score:", score, "/", 54)
