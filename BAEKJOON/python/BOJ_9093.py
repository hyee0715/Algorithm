import sys
n = int(sys.stdin.readline())
data = [] * n
stack = []
result = ""
for _ in range(n):
    data.append(sys.stdin.readline().strip())

for i in range(n):
    array = data[i].split(' ')

    for j in range(len(array)):
        for k in range(len(array[j])):
            stack.append(array[j][k])

        while len(stack) != 0:
            result += stack.pop()
        result += " "
    result += "\n"

print(result)