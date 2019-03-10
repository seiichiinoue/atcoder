n = int(input()) % 30

def f(s, n):
    for i in range(0, n):
        s[i % 5], s[i % 5 + 1] = s[i % 5 + 1], s[i % 5]
    return "".join(s)

print(f(list('123456'), n))
