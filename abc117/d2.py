N, K = map(int, input().split(" "))
l = [bin(int(n)) for n in input().split(" ")]

def encode(l):
	l = [list(b) for b in l]
	for line in l:
		line.pop(0)
		line.pop(0)

	max_len = max([len(n) for n in l])

	for line in l:
		while len(line) != max_len:
			line.insert(0, '0')

	return l

l = encode(l)
K = encode([bin(n) for n in range(K + 1) if n != 0])

def find(l, s):
	yes = []
	for line in l:
		if line[0] == str(s):
			yes.append(line)

	return yes

better_int = 0
print(find(K, better_int))