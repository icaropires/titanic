import sys
from math import factorial

lines = sys.stdin.readlines()

dp = [0, 0, 0, 0]
naodp = [0, 0, 0, 1]

def bi3(n):
    # 3 posições n varas
    # 2 posições n - 1 varas
    # 1 posições n - 2 varas
    return (n * (n - 1) * (n - 2)) // 6

for i in range(4, 1000001):
    dp += [naodp[i-1]]
    naodp += [bi3(i) - dp[i]]

for line in lines:
    n = int(line.strip())
    if n < 3:
        break

    print(dp[n])
