s = input()
k = int(input())
if len(s) < k: print(0)
else:
    l = []
    for i in range(len(s) - k + 1):
        l.append(s[i:i+k])
    print(len(set(l)))