n, a, b, c, d, e = [int(input()) for _ in range(6)]
n -= 1
print(max([n // a , n // b, n // c, n // d, n // e]) + 5)