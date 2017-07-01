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
	int bigger = 0, n;
	cin >> n;

	for(int i = 1; i <= n; ++i){
		string str, pat;
		cin >> str;

		reverse(str.begin(), str.end());
		vector<int> z = z_function(str);

		bigger = *max_element(z.begin(), z.end());

		if(bigger){
			pat = str.substr(0, bigger);
			str = str.substr(bigger, str.size()-1);

			while(true){
				z = z_function(pat + "#" + str);
				bigger = *max_element(z.begin(), z.end());

				if(bigger == pat.size())
					break;

				str.insert(0, 1, pat[pat.size() - 1]);
				pat.pop_back();

			}
		}
			reverse(str.begin(), str.end());
			printf("Caso %d: %s\n", i, str.c_str());
	}

	return 0;
}
