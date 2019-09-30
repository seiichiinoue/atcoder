l, s = map(int, input().split())
# 12時から何度進んでいるかで考える
ll = (l % 12) * 30 + (s * 0.5)
ss = s * 6
print(min(abs(ll - ss), 360 - abs(ll - ss)))