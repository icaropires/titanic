#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 1000002

int sumDigiteS(ll n){
	int soma=n;
	while(n){
		soma+=n%10;
		n/=10;
	}
	return soma;
}


int main(){

vector<int> mapa(N,0);

	for(ll i=1; i<=N; ++i){
		int aux = sumDigiteS(i);
		if(aux<=N)mapa[aux]=1;
		if(mapa[i]!=1)cout << i << endl;
	}

 return 0;
}
