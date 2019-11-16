n = int(input())
s = input()
tmp = ""
for i in range(n):
    tmp += s[i]
    if s.count(tmp) >= 2:
        print("Yes")
        exit(0);
print("No")