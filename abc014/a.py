a, b = int(input()), int(input())
original_a = a
while a % b != 0:
  a += 1
print(a - original_a)