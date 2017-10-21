from sys import stdin 

dp= [1,1]
for i in range(300):
  dp.append(dp[-2]*2 + dp[-1])

for n in stdin:
  n = int(n)

  print(dp[n])
