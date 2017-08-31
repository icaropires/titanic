#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline ll soma(ll n){
	return (n*(n+1))/2;
}

inline ll sum(ll n){
	return soma(n)*soma(n);
}

int main(){
	ll n;
	while(cin>> n, !cin.eof())
		cout << sum(n) << endl;
		

 return 0;
}
