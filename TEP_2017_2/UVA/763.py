import sys

input_set = sys.stdin.read()

input_set = input_set.split('\n')

fib = [1, 2]

for i in range(2, 115):
    fib += [fib[i-1] + fib[i-2]]


def from_fibinary(x):
    y = x[::-1]
    res = 0
    index = 0
    for i in range(len(y)):
        res += (ord(y[i]) - ord('0')) * fib[index]
        index+=1

    return res


def to_fibinary(n, maximo):
    x = []
    soma = 0

    if(n > 0):
        for i in range(maximo, -1, -1):
            soma += fib[i]
            if soma <= n:
                x.append(1)
            else:
                soma -= fib[i]
                x.append(0)
    else:
        x.append(0)

    return x

check = False
for index in range(0, len(input_set), 3):
    if(check):
        print('')
    check = True
    a = input_set[index]
    b = input_set[index + 1]

    if a == "0" and b == "0":
        print(0)
        continue
    
    res = from_fibinary(a) + from_fibinary(b)
    
    i = 114
    while fib[i] > res:
        i -= 1

    ans = to_fibinary(res, i)
    
    for k in range(len(ans)):
        print(ans[k], end='')
    print()

