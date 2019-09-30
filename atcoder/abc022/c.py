"""
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

n, m = map(int, input().split())
g = Graph()
for _ in range(m):
    src, dst, weight = map(int, input().split())
    g.add_edge(src - 1, dst - 1, weight)
    g.add_edge(dst - 1, src - 1, weight)
start_node = g.graph.pop(0)  # 始点と接続している辺全てを削除する．
sp = float('inf')
for start, w_s in start_node:
    d = Dijkstra(g, start)
    for dst, w_d in start_node:
        if start == dst:
            continue
        v_d = d.shortest_dist(dst)
        v_d += w_s + w_d
        if sp > v_d:
            sp = v_d
print(sp if sp != float('inf') else -1)
"""

from scipy.sparse.csgraph import floyd_warshall as wf

n, m = map(int, input().split())
uvl = [list(map(int, input().split())) for _ in range(m)]
INF = float('inf')

# initialization
d = [[INF] * n for _ in range(n)]
for i in range(n):
    d[i][i] = 0
for u, v, l in uvl:
    if u != 1 and v != 1:
        d[u - 1][v - 1] = l
        d[v - 1][u - 1] = l
d = wf(d)
start = []
for i in range(m):
    if uvl[i][0] == 1:
        start.append(uvl[i])
ans = INF
for i in start:
    for j in start:
        if i != j and d[i[1] - 1][j[1] - 1] != INF:
            tmp = i[2] + j[2] + d[i[1] - 1][j[1] - 1]
            ans = min(ans, tmp)
print(int(ans) if ans != INF else -1)