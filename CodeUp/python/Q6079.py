n = int(input())
sum = 0

for i in range(1, n + 1):
    if sum < n:
        sum = sum + i
        last = i
    else:
        break

print(last)