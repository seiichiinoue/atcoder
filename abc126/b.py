s = input()
a, b = s[:2], s[2:]
def check(s1, s2):
    if 0 < int(s1) <= 12 and 0 < int(s2) <= 12:
        return 'AMBIGUOUS'
    elif 0 < int(s1) <= 12:
        return 'MMYY'
    elif 0 < int(s2) <= 12:
        return 'YYMM'
    else:
        return 'NA'
print(check(a, b))
