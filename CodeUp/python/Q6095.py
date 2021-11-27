d = [[0 for j in range(20)] for i in range(20)]

n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    d[a][b] = 1

for i in range(1, len(d)):
    for j in range(1, len(d[i])):
        print(d[i][j], end=' ')
    print("")