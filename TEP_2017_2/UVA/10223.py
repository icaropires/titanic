from math import factorial 
from sys import stdin 

def catalan(n):
    return factorial(2*n)//(factorial(n+1)*factorial(n))

vet = ['gambiarra']
vet += [catalan(i) for i in range(1, 50)]

for line in stdin:
    n = int(line.strip())

    result = vet.index(n) 
    print(result)
