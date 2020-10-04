def swap(s, x, y):
    s[x], s[y] = s[y], s[x]
    return(s)


def perm(s, l, r):
    if l == r:
        print(s)
    else:
        for i in range(l, r+1):
            s = swap(s, l, i)  # swapping the new left of an instance
            perm(s, l+1, r)
            s = swap(s, l, i)  # backtrack


if __name__ == "__main__":
    s = input("enter string\n")
    s = list(s)
    n = len(s)
    perm(s, 0, n-1)
