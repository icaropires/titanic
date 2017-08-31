#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long ;
int main(){
	ll c1, c2;

	while(cin >> c1 >> c2, !cin.eof()){
			cout << ((((1LL << (c2+1))-1) >= c1) ? "yes" : "no") << endl;
	
	}
 return 0;
}
