s = input()
l = []
for a in s:
    l.append(a)
if len(set(l)) == 2:
    print("Yes")
else:
    print("No")
