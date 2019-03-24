s = list(input())
l = ['A', 'T', 'C', 'G']
max_cnt = 0
cnt = 0
for i in range(len(s)):
    if s[i] in l:
        cnt += 1
    elif s[i] not in l:
        cnt = 0
    if max_cnt <= cnt:
        max_cnt = cnt
print(max_cnt)