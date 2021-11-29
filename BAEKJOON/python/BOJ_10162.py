n = int(input())
a = b = c = 0

a = n // 300
n = n % 300

b = n // 60
n = n % 60

c = n // 10
n = n % 10

if n != 0:
    print(-1)
else:
    print(a, b, c)