n, k = map(int, input().split())
v = list(map(int, input().split()))
ans = 0 
# left
for i in range(min(n, k) + 1):
    # right
    for j in range(min(n, k) - i + 1):
        par_seq = sorted(v[:i] + v[-j:] if j != 0 else v[:i])
        par_seq_sum = sum(par_seq)
        if par_seq_sum > ans:
            ans = par_seq_sum
        ope = k - (i + j)
        print(par_seq, par_seq_sum)
        for _ in range(min(ope, len(par_seq))):
            rm = par_seq.pop(0)
            if rm < 0 and sum(par_seq) > ans:
                ans = sum(par_seq)

print(ans)