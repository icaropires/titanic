from sys import stdin 
from math import log10

def binom(n,k):
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in range(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0

for line in stdin:
    line = line.strip()

    n, k = [int(i) for i in line.split()]
    print(int(log10(binom(n,k))) + 1)
