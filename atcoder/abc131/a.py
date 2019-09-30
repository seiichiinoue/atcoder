pre = 0
for i in list(input()):
    if i == pre:
        print("Bad")
        exit()
    pre = i
print("Good")