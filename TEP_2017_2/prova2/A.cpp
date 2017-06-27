#include <bits/stdc++.h>

using namespace std;

vector<string> fiba(100, "");

void fib(int n){
	
	if(fiba[n] != "")
		return;
	
	for(int i = 3; i <= n; i++){
		fiba[i] = fiba[i - 1] + fiba[i - 2];
	}

}

int main(){

	int t;

	cin >> t;
	
	for(int i = 0; i < 25; i++)
		fiba[i] = "";

	fiba[1] = "b";
	fiba[2] = "a";

	fib(25);

	for(int i = 0; i < t; i++){
		int n;
		cin >> n;

		cout << "Caso " << i + 1 << ": " << fiba[n] << endl;
	}

	return 0;
}
