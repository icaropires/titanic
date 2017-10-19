from math import pow
import sys

dp = [[0]*11 for i in range(200)]


def solve(k,n):

    for j in range(k+1):
        dp[1][j] = 1;

    for i in range(2, n + 1):
        for j in range(k + 1):
            if(j==0):
                dp[i][j] = dp[i-1][j] + dp[i-1][j+1]
            elif(j==k):
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
            else:
                dp[i][j] = dp[i-1][j] + dp[i-1][j+1] + dp[i-1][j-1]

    result = 0.0
    
    for j in range(k + 1):
        result += dp[n][j]

    return (result*100)/pow(k + 1, n)
            
for line in sys.stdin:
    line = line.strip()

    a, b = [int(i) for i in line.split()]

    print('{0:.5f}'.format(solve(a, b)))
