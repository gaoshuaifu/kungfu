def one_edit_distance(s1, s2):
    s, l = s1, s2
    if len(s) > len(l):
        s, l = l, s

    if len(l) - len(s) > 1:
        return False

    i, j = 0, 0
    while i < len(s) and j < len(l):
        if s[i] != l[j]:
            break
        i += 1
        j += 1

    j += 1
    if len(s) == len(l):
        i += 1

    while i < len(s) and j < len(l):
        if s[i] != l[j]:
            break
        i += 1
        j += 1

    return i == len(s) and j == len(l)

def main():
    print one_edit_distance("1230", "1240")
    print one_edit_distance("1230", "130")
    print one_edit_distance("1230", "12340")
    print one_edit_distance("1230", "12450")
    print one_edit_distance("1230", "3120")

main()
