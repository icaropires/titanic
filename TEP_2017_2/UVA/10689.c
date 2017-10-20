#include <stdio.h>

int dp[15000];

int main(){
	int cases = 0;		
	int a, b, n, m;

	int exps[] = {0, 10, 100, 1000, 10000};

	scanf("%d", &cases);

	for(int i = 0; i < cases; ++i){
		scanf("%d %d %d %d", &a, &b, &n, &m);	

		if(!n) {
			printf("%d\n", a);
			continue;
		} else if(n == 1) {
			printf("%d\n", b);
			continue;
		}

		for(int j = 1; j < 15000; ++j){
			int tmp = a + b;	
			a = b;
			b = tmp % exps[m];

			dp[j - 1] = b;
		}

		printf("%d\n", dp[n % 15000 - 2]);
	}

	return 0;
}
