n = int(input())
d = dict()
name_list = []
for j in range(n):
    s, i = input().split()
    if s not in d.keys():
        d[s] = []
    d[s].append([int(i), j])
    name_list.append(s)
name_list = list(set(name_list))
name_list.sort()
for t in name_list:
    tar = sorted(d[t], reverse=True)
    for ans in tar:
        print(ans[1] + 1)
