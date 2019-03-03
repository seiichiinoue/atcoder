A, B, K = map(int, input().split())

def get(num):
    yakusuu_array = []
    for i in range(1,num + 1):
        if num % i == 0:
            yakusuu_array.append(i)
    return yakusuu_array

a = list(set(get(A)) & set(get(B)))
a.sort(reverse=True)


print(a[(K-1)])

