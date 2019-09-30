l = [int(input()), int(input()), int(input())]
ll = sorted(l, reverse=True)
for i in l:
    print(ll.index(i) + 1)