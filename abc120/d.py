class UnionFind:
    def __init__(self, n):
        self.parent = [-1 for _ in range(n)]

    def root(self, x):
        """要素xの根の番号を返す"""
        if self.parent[x] < 0:
            return x
        self.parent[x] = self.root(self.parent[x])
        return self.parent[x]

    def size(self, x):
        """所属するグループの頂点数を調べる"""
        return -self.parent[self.root(x)]

    def marge(self, x, y):
        """xとyを結合する"""
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return False
        if self.size(x) < self.size(y):
            x, y = y, x
        self.parent[x] += self.parent[y]
        self.parent[y] = x  # 親を更新
        return True

n, m = map(int, input().split())
bridges = []
for i in range(m):
    bridges.append([int(s) - 1 for s in input().split()])

ans = [n * (n-1) // 2]
uf = UnionFind(n)
for i in range(m-1, 0, -1):
    a, b = bridges[i]
    if uf.root(a) == uf.root(b):
        ans.append(ans[-1])
    else:
        size_a = uf.size(a)
        size_b = uf.size(b)
        ans.append(ans[-1] - size_a * size_b)
        uf.marge(a, b)
ans.reverse()
print('\n'.join(map(str, ans)))
