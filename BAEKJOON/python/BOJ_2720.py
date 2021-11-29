n = int(input())
m = []
for i in range(n):
    m.append(int(input()))

coins = [25, 10, 5, 1]
result = [[0 for j in range(4)] for i in range(n)]

for i in range(n):
    for j in range(len(coins)):
        result[i][j] = (m[i] // coins[j])
        m[i] %= coins[j]

for i in range(len(result)):
    for j in range(len(result[i])):
        print(result[i][j], end=' ')
    print()