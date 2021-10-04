import sys
from math import ceil
def get_ints(): return map(int, sys.stdin.readline().strip().split())


N, S = get_ints()
vals = []
ts = 0
for i in range(N):
    s, a, b = get_ints()
    ts += s
    vals.append([a-b, s, a, b])
p = ceil(ts/S)
dummy = S*p-ts
# trozos sobrantes - mas de 1 pizza
if ts > S:
    vals.append([0, dummy, 0, 0])
# ordenar de a-b mayor a menor
vals.sort(reverse=True)


def h(n1):
    cnt1 = n1
    cnt2 = p*S-n1
    res = 0
    # comer n1 hasta que se acabe
    i = 0
    while(cnt1 > 0):
       # print(i)
       # print(cnt1)
        if cnt1 - vals[i][1] >= 0:
            res += vals[i][1]*vals[i][2]
           # print(res)
            cnt1 -= vals[i][1]
        else:
            # termino de comer lo que me queda de n1
            res += cnt1*vals[i][2]
           # print("termino de comer n1")
           # print(res)
            # el resto vals[i][1] como de n2
           # print("el resto como n2")
            res += (vals[i][1]-cnt1)*vals[i][3]
           # print(res)
            cnt2 -= (vals[i][1]-cnt1)
            cnt1 = 0
        i += 1
    while(cnt2 > 0):
        # print(cnt2)
        res += vals[i][1]*vals[i][3]
        cnt2 -= vals[i][1]
        i += 1
       # print(res)
    return res


# filtrar por numero de tortas
l = 0
r = p
while l < r:
    mid = int((l+r)/2)
    ch = h(mid*S)
    nh = h((mid+1)*S)
    if nh - ch > 0:
        l = mid + 1
    else:
        r = mid
print(h(l*S))
