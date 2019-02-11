N = int(input())
l = [int(x) for x in input().split(" ")]
matrix = []

for _ in range(N):
    matrix.append([])

for index, i in enumerate(l):
    for _ in range(i):
        matrix[index].append(1)
    while len(matrix[index]) != max(l):
        matrix[index].append(0)

def trans(A:list) -> list:
    ans = []
    for col in range(len(A[0])):
        l = []
        for line in range(len(A)):
            l.append(A[line][col])
        ans.append(l)
    return ans    

ll = trans(matrix)
count = 0
for line in reversed(ll):
    mark = False
    for index, i in enumerate(line):
        if i == 1 and mark == False:
            count += 1
            line[index] = 0
            mark = True
        
        elif i == 1 and mark == True:
            line[index] = 0

        elif i == 0:
            mark = False
print(count)

