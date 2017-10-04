from math import factorial 
def catalan(n):
	return factorial(2*n)//( factorial(n+1)*factorial(n))

n = 0
while 1:
	n = int(input())

	if(n==0):
		break

	print('%d' %(catalan(n)*factorial(n)))

