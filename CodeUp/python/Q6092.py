n = int(input())
numbers = list(map(int, input().split()))
result = [0] * 24

for number in numbers:
    result[number] += 1

for i in range(1, len(result)):
    print(result[i], end=' ')