a, b, c = map(int, input().split())
if a+b+2*(a*b)**(1/2)<c: print("Yes")
else: print("No")