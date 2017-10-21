from sys import stdin

for line in stdin:
    line = line.strip()
    
    n, d = [int(i) for i in line.split()]

    if n == d == 0:
        break

    print(n**d)
