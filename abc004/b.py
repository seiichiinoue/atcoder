ban = [input().split() for _ in range(4)]
def trans(l):
    new_l = [[0] * len(l[0]) for _ in range(len(l))]
    for i in range(len(l)):
        for j in range(len(l[0])):
            new_l[i][j] = l[3-i][3-j]
    return new_l
if __name__ == "__main__":
    for line in trans(ban):
        print(" ".join(line))