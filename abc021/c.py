"""
n = int(input())
a, b = map(int, input().split())
a -= 1
b -= 1
m = int(input())
routes = [list(map(int, input().split())) for _ in range(m)]

from collections import defaultdict
from heapq import heappush, heappop

class Graph(object):

    def __init__(self):
        self.graph = defaultdict(list)
    
    def __len__(self):
        return len(self.graph)
    
    def add_edge(self, src, dst, weight=1):
        self.graph[src].append((dst, weight))
    
    def get_nodes(self):
        return self.graph.keys()
    
class Dijkstra(object):

    def __init__(self, graph, start):
        # グラフ
        self.g = graph.graph
        # startノードからの最短距離
        self.dist = defaultdict(lambda: float('inf'))
        self.dist[start] = 0
        # 最短経路での1つ前のノード
        self.prev = defaultdict(lambda: None)
        # startノードをQに入れる
        self.Q = []
        heappush(self.Q, (self.dist[start], start))

        while self.Q:
            dist_u, u = heappop(self.Q)
            if self.dist[u] < dist_u:
                continue
            for v, weight in self.g[u]:
                alt = dist_u + weight
                if self.dist[v] > alt:
                    self.dist[v] = alt
                    self.prev[v] = u
                    heappush(self.Q, (alt, v))
    
    def shortest_dist(self, goal):
        return self.dist[goal]

    def shortest_path(self, goal):
        path = []
        node = goal
        while node is not None:
            path.append(node)
            node = self.prev[node]
        return path[::-1]

def make_shortest_path_dag():
    g = Graph()
    for src, dst in routes:
        g.add_edge(src - 1, dst - 1, 1)
        g.add_edge(dst - 1, src - 1, 1)
    d = Dijkstra(g, a)
    rel = set()
    for i in range(7):
        if i == a:
            continue
        sp = d.shortest_path(i)
        for j in range(len(sp) - 1):
            rel.add((sp[j], sp[j + 1]))
    new_g = Graph()
    for src, dst in list(rel):
        new_g.add_edge(src, dst, 1)
        new_g.add_edge(dst, src, 1)
    return new_g
"""

n = int(input())
a, b = map(int, input().split())
m = int(input())
a -= 1
b -= 1
INF = float('inf')
mat = [[INF] * n for _ in range(n)]  # dp table

for i in range(n):
    mat[i][i] = 0
for _ in range(m):
    x, y = map(int, input().split())
    mat[x - 1][y - 1] = 1
    mat[y - 1][x - 1] = 1

for i in range(n):
    for j in range(n):
        for k in range(n):
            mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k])

mod = 10 ** 9 + 7
num = [0] * n
num[a] = 1

for i in range(n):
    for j in range(n):
        if mat[a][j] != i:
            continue
        for k in range(n):
            if mat[a][k] == i + 1 and mat[j][k] == 1:
                num[k] += num[j]
                num[k] %= mod
print(num[b])
