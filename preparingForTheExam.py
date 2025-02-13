for _ in range(int(input())):
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    q = list(map(int, input().split()))
    used = [False for i in range(n + 1)]
    for i in q:
        used[i] = True
    l = len(q)
    for i in range(m):
        if l == n or (l == n-1 and not used[a[i]]):
            print(1, end='')
        else:
            print(0, end='')
    print()