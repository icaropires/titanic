#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	char input[101];
	double n;
	int time,i;

	scanf("%d", &time);
		for(i=0; i<time; ++i){
			scanf("%lf", &n);
			int e = (int)floor(-n*log10(2));		
			printf("2^%d = %.3lfE%d\n", (int)-n,pow(10,-n*log10(2)-e ),e);
		}



 return 0;
}
