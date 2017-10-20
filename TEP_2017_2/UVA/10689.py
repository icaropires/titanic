# TLE

from sys import stdin

dp = [0] * 15000

count = 0
for line in stdin:
    line = line.strip()

    if count:
        a, b, n, m = [int(i) for i in line.split()]

        dp[0] = a % 10**m
        dp[1] = b % 10**m
        
        for i in range(2, 15000):
            tmp = a + b
            a = b
            b = tmp % 10**m
            dp[i] = b

        print(dp[n % 15000])

    else:
        cases = line
        count += 1
