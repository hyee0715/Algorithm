n = int(input())
data = list(map(int, input().split()))
count = 0
result = 0
for d in data:
    if d == count:
        result += 1
        count += 1
        if count == 3:
            count = 0

print(result)