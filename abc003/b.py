S = list(input())
T = list(input())
u = 'atcoder@'
for s,t in zip(S,T):
    if s == t or (s == '@' and t in u) or (t == '@' and s in u):
        continue
    else:
        print('You will lose')
        exit()
print('You can win')