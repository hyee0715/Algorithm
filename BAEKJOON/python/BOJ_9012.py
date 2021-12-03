import sys

n = int(sys.stdin.readline())
data = [] * n
stack = []

for _ in range(n):
    data.append(sys.stdin.readline().strip())

for i in range(len(data)):
    stack.clear()

    for j in range(len(data[i])):
        if data[i][j] == "(":
            if j == (len(data[i]) - 1):
                stack.append("(")
                break
            stack.append("(")
        else:
            if len(stack) == 0: # 이미 스택이 비워져 있다면 바로 종료
                stack.append(")")
                break
            stack.pop()

    if len(stack) == 0:
        print("YES")
    else:
        print("NO")
