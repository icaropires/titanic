#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

typedef long long ll;

int main(){

	ll u[MAX];
	ll l[MAX];

	u[1]=l[1]=1;
	u[2]=l[2]=2;

	for(int i=3; i<MAX; ++i){
		u[i]=l[i-1]+l[i-2];
		l[i]=l[i-1]+u[i-1];
	}


	int n=2;
	
	while(cin >> n, n!=0)
		cout << ((1<< n) - u[n] -l[n]) << endl;

 return 0;
}
