input()
a = list(map(int, input().split()))
def f(i):
    if (i % 3 == 0 or i % 3 == 1) and i % 2 == 1:
        return i
    return f(i - 1)
ans = 0
for i in a:
    origin = i
    ans += origin - f(i)
    
print(ans)