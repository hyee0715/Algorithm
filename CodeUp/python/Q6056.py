a, b = map(int, input().split())
print((bool(a) and not bool(b)) or (bool(b) and not bool(a)))