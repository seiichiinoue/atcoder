a, b, c = map(str, input().split())
print("".join(list(map(lambda x: x[0].upper(), [a, b, c]))))