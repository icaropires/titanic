# TLE

from sys import stdin

dp = [0] * 15000

count = 0
for line in stdin:
    line = line.strip()

    if count:
        a, b, n, m = [int(i) for i in line.split()]

        if not n:
            print(a)
            continue
        elif n == 1:
            print(b)
            continue
        
        for i in range(1, 15000):
            tmp = a + b
            a = b
            b = tmp%10**m
            dp[i - 1] = b

        print(dp[n % 15000 - 2])

    else:
        cases = line
        count += 1
