import sys

# because has no triangles for n < 3
triangulos = [0, 0, 0, 0]
nao_triangulos = [0, 0, 0, 1]

def binom_3(n):
    return (n * (n - 1) * (n - 2)) // 6

for i in range(4, 1000001):
    triangulos += [nao_triangulos[i-1]]
    nao_triangulos += [binom_3(i) - triangulos[i]]

for line in sys.stdin:
    n = int(line.strip())

    if n < 3:
        break

    print(triangulos[n])
