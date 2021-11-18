m = 10**9 + 7
z = 127
def prefix_hash(s):
    v = [0]*len(s)
    v[-1] = ord(s[-1])
    i = len(s) - 2
    while(i >= 0):
        v[i] = (v[i+1]*z + ord(s[i]))%m
        i -= 1
    return v

def hash_lr(v, l, r):
    return (v[l] - v[l+r] * (z**(r)))%m;

s = input()
n = len(s)
h = prefix_hash(s)
hr = prefix_hash(s[::-1])
i = 2
l = 0
r = n-1
pal = True
while(i <= r-l+1):
    if hash_lr(h, l, int(i/2)) == hash_lr(hr, n-l-i, int(i/2)):
        l += int(i/2)
        i = 2
        continue
    i += 2
i = 2
while(i <= r-l+1):
    if hash_lr(h, r-i+1, int(i/2)) == hash_lr(hr,n-r-1, int(i/2)):
        r -= int(i/2)
        i = 2
        continue
    i += 2

print(r-l+1)