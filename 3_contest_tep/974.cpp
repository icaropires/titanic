#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main(){

	ios::sync_with_stdio(false);
	int n;

	cin >> n;
	int size = n;
	while(n--){
		ll a,b;
		cout << "case #" << size-n << endl;
		cin >> a >> b;
		bool vdd = false;
		for(int i=a; i<=b; ++i){
		
			int number = i*i;
			int part1= number%10;
			int part2 = number/10;
			int x=10;
	
			if( part1>0 and part2>0 and (part1 + part2)==i){
				 vdd=true;

				cout << i << endl;
			}else {
				while(part2!=0){
					part1=x*(part2%10) + part1;
					part2/=10;
					x*=10;
					if(part1>0 and part2>0 and (part1 + part2)==i){
						vdd=true;
						cout << i << endl;
						break;
					}
				}
			}
		}
				if(!vdd)cout << "no kaprekar numbers" << endl;
			if(n!=0)cout << endl;
		
	}

 return 0;
}
