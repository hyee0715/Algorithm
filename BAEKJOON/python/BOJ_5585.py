n = int(input())
m = 1000 - n # 잔돈 금액
count = 0 # 잔돈의 개수
coins = [500, 100, 50, 10, 5, 1]

for coin in coins:
    count += (m // coin)
    m %= coin

print(count)