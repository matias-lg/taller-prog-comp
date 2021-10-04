def posible(n, numvacas, stalls):
    vacas = 1
    s = stalls[0]
    i = 1
    while(i < len(stalls)):
        if stalls[i] - s >= n:
            s = stalls[i]
            vacas += 1
            if vacas == numvacas:
                return True
        i += 1
    return False


t = int(input())
i = 0
while i < t:
    n, c = list(map(int, input().split()))
    cnt = 0
    stalls = []
    while cnt < n:
        stalls.append(int(input()))
        cnt += 1
    stalls.sort()
    # ANSWER
    m = 0
    l = 0
    r = n - 1
    while(l < r):
        mid = int((l+r)/2)
        if(posible(mid, c, stalls)):
            if mid > m:
                m = mid
            l = mid + 1
        else:
            r = mid
    print(m)
    i += 1
