n, m = map(int, input().split(" "))
relations = [tuple(map(int, input().split(" "))) for _ in range(m)]

def chk_relation(member):
    return all((members[i], members[j]) in relations for i in range(len(member)) for j in range(i+1, len(member)))

mx = 0
for i in range(1<<n):
    members = []
    for j in range(n):
        if i&(1<<j) != 0:
            members.append(j+1)
    if chk_relation(members) and len(members)>mx:
        mx = len(members)

print(mx)