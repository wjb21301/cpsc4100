import sys
lines = sys.stdin.readlines()
for line in lines:
    x = line.split()
    a= int(x[0])
    b = int(x[1])
    print(abs((a-b)))