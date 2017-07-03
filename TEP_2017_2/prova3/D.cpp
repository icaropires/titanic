#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(const string &s) {
	int n = s.size();
	vector<int> z(n, 0);
	int L = 0, R = 0;
	for(int i = 1; i < n; i++) {
		if(i <= R) {
			z[i] = min(z[i - L], R - i + 1);
		}
		while(z[i] + i < n && s[z[i] + i] == s[z[i]]) {
			z[i]++;
		}
		if(R < i + z[i] - 1) {
			L = i, R = i + z[i] - 1;
		}
	}
	return z;
}

int main(){
	int n;
	cin >> n;

	for(int j = 1; j <= n; ++j){
		string str_orig;
		cin >> str_orig;

		string str = str_orig;
		reverse(str.begin(), str.end());

		vector<int> z = z_function(str);

		int position = 0;
		for(int i = 0; i < z.size(); ++i){
			if(z[i] >= i){
				position = i;
			}
		}

		str_orig = str_orig.substr(0, str_orig.size() - position);
		printf("Caso %d: %s\n", j, str_orig.c_str());
	}
	return 0;
}
