import sys
from math import factorial

lines = sys.stdin.readlines()

dp = [0, 0, 0, 0]
naodp = [0, 0, 0, 1]

def bi3(n):
    return (n * (n - 1) * (n - 2)) // 6

for i in range(4, 100):
    dp += [naodp[i-1]]
    naodp += [bi3(i) - dp[i]]

for line in lines:
    n = int(line.strip())
    if n < 3:
        break

    print(dp[n])
