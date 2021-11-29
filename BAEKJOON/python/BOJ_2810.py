n = int(input())
data = input()

cupCount = n + 1
numL = 0

for d in data:
    if d == 'L': # L의 개수 세기
        numL += 1

numL = numL // 2
result = cupCount - numL

if result > n: # 컵 홀더의 수가 사람 수 보다 많은 경우 사람 수 출력
    print(n)
else:
    print(result) # 컵 홀더의 수가 사람 수 보다 적은 경우 컵 홀더의 개수 출력