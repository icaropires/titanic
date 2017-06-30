#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	for(int j = 1; j <= n; ++j){
		string s;	
		int counta = 1, countd = 1;
		int maiora = 1, maiord = 1, maior = 1;
		cin >> s;

		for(int i = 1; i < s.size(); ++i){
			if(s.size() == 1)
				break;
			//decrescente
			//dcba
			if(s[i] == s[i-1]-1 or (s[i-1] == 'a' and s[i] == 'z')){
				countd++;
				maiora = max(maiora, counta);
				counta = 1;
			}
			//crescente
			//abcd
			else if(s[i] == s[i-1]+1 or (s[i-1] == 'z' and s[i] == 'a')){
				counta++;
				maiord = max(maiord, countd);
				countd = 1;
			}
			else{
				maiora = max(counta, maiora);
				maiord = max(countd, maiord);
				counta = 1;	
				countd = 1;	
			}
			maiora = max(counta, maiora);
			maiord = max(countd, maiord);
			maior = max(maiora, maiord);
		}
		printf("Caso %d: %d\n", j, maior);
	}
	return 0;
}
