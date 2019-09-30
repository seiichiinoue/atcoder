
N = int(input())
A = list(input())
B = list(input())
C = list(input())

if A == B and B == C:
    print(0)
else:
    counter = 0
    for j, k, l in zip(A,B,C):
        if j == k and k == l:
            pass
        elif j == k or k == l or j == l:
            counter += 1
        else:
            counter += 2

    print(counter)