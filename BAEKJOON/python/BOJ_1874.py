import sys
n = int(sys.stdin.readline())
stack = []
data = []
result = ""
flag = True
count = 1

for _ in range(n):
    data = int(sys.stdin.readline())

    while count <= data: # 첫번째 숫자까지 스택에 먼저 넣기
        result += "+"
        stack.append(count)
        count += 1

    if stack[-1] == data:
        result += "-"
        stack.pop()

    else:
        flag = False
        break

if flag == False:
    print("NO")
else:
    for i in range(len(result)):
        print(result[i])