for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [list(map(int, input().split())) for i in range(n)]
    hasColor = [0] * (n * m)
    hasBad = [0] * (n * m)
    for i in range(n):
        for j in range(m):
            hasColor[a[i][j] - 1] = 1
            if i + 1 < n and a[i][j] == a[i + 1][j]:
                hasBad[a[i][j] - 1] = 1
            if j + 1 < m and a[i][j] == a[i][j + 1]:
                hasBad[a[i][j] - 1] = 1
    print(sum(hasColor) + sum(hasBad) - 1 - max(hasBad))