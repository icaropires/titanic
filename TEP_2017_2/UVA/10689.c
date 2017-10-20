#include <stdio.h>

int dp[15000];

int main(){
	int cases = 0;		
	int a, b, n, m;

	int exps[] = {1, 10, 100, 1000, 10000};

	scanf("%d", &cases);

	int i;
	for(i = 0; i < cases; ++i){
		scanf("%d %d %d %d", &a, &b, &n, &m);	

		dp[0] = a % exps[m];
		dp[1] = b % exps[m];

		int j;
		for(j = 2; j < 15000; ++j){
			int tmp = a + b;	
			a = b;
			b = tmp % exps[m];

			dp[j] = b;
		}

		printf("%d\n", dp[n % 15000]);
	}

	return 0;
}
