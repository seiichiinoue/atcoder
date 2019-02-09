N, K = map(int, input().split(" "))
l = [int(n) for n in input().split(" ")]

ans_list = []
for n in range(K + 1):
	ans = 0
	for i in range(len(l)):
		ans += l[i] ^ n
	ans_list.append(ans)

print(max(ans_list))


a = [bin(n) for n in range(K + 1)]

