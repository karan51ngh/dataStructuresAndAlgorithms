def maxprod(arr):
    a = max(arr)
    if a in arr:
        arr.remove(a)
    b = max(arr)
    return a*b


i = int(input())
arr1 = input()
arr = list(map(int, arr1.split()))

print(maxprod(arr))
