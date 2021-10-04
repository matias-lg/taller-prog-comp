import sys
import math
def get_ints(): return map(int, sys.stdin.readline().strip().split())


N, S = get_ints()

slices = 0
vals = []
for i in range(N):
    s, a, b = get_ints()
    slices += s
    vals.append([a-b, s, a, b])
dummy = S*(math.ceil(slices/S))-slices
if slices <= S:
    dummy = 0
vals.append([0, dummy, 0, 0])
vals.sort(reverse=True)
print(vals)


def h(n1, n2):
    ret = 0
    cnt1 = n1
    cnt2 = n2
    i = 0
    while(cnt1 > 0):
        if cnt1 - vals[i][1] > 0:
            ret += vals[i][1]*vals[i][2]
            cnt1 -= vals[i][1]
        else:
            ret += cnt1*vals[i][2]
            cnt1 = 0
        # print(ret)
        i += 1
    #i = len(vals)-1
    while(cnt2 > 0 and i < len(vals)):
        if cnt2 - vals[i][1] > 0:
            ret += vals[i][1]*vals[i][3]
            cnt2 -= vals[i][1]
        else:
            ret += cnt2*vals[i][3]
            cnt2 = 0
        i += 1
        print(ret)
    return ret


p = math.ceil(slices/S)
res = 0
l = 0
r = S*p
# print(r)


def h1(n):
    return h(n, (S*p)-n)


# filtrar por numero dde tortas
posible = []
for i in range(0, S*p+1):
    print(h1(i))
    if (math.ceil(i/S) + math.ceil((slices - i)/S)) <= p:
        posible.append(i)
# posible.sort(reverse=True)
r = len(posible)-1
print(r)
while(l <= r):
    mid = int((l+r)/2)
    ch = h1(posible[mid])
    res = max(res, ch)
    if l == r:
        break
    if ch - h1(posible[mid + 1]) < 0:
        l = mid+1
    else:
        r = mid

print(res)
