#include <bits/stdc++.h>

using namespace std;

int main(){
	string s, vogaisS = "aeiou";
	
	cin >> s;

	vector<int> vogais(s.size(), 0), consoantes(s.size(), 0);

	int n;

	cin >> n;

	if(vogaisS.find(vogais[0] != string::npos)){
		vogais[0] = 1;
		consoantes[0] = 0;
	}
	else{
		vogais[0] = 0;
		consoantes[0] = 1;
	}

	for(int i = 1; i <s.size(); ++i){
		if(vogaisS.find(tolower(s[i])) != string::npos){
			vogais[i] = vogais[i-1] + 1;
			consoantes[i] = consoantes[i-1];
		}
		else{
			consoantes[i] = consoantes[i-1] + 1;
			vogais[i] = vogais[i-1];
		}
	}

	for(int j = 0; j<n; ++j){
		int a, b;

		cin >> a >> b;

		a--;
		b--;

		string ans;

		int diffV = vogais[b] - vogais[a - 1]; 
 		int diffC = consoantes[b] - consoantes[a - 1];

		if(diffV == diffC or !diffC or !diffV)
			ans = "sim";
		else 
			ans = "nao";

		printf("Query %d: %s\n", j + 1, ans.c_str());
	}

	return 0;
}
