#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(const string &s){
	int n = s.size();

	vector<int> z(n, 0);
	int L = 0, R = 0;

	for(int i = 1; i < n; i++){
		if(i<=R){
			z[i] = min(z[i - L], R - i + 1);
		}
		while(z[i]+i < n and s[z[i]+i] == s[z[i]]){
			z[i]++;
		}

		if(R < i + z[i] - 1){
			L = i, R = i+ z[i] - 1;
		}
	}

	return z;
}


int main(){

	int t;

	cin >> t;

	for(int k = 0; k < t; k ++){
		string a, b;

		cin >> a >> b;
		int bsize = b.size();
		b += "#" + a;

		vector<int> v = z_function(b);

		int cont = 0;
		int h = 0, l = 0;
		
		vector<vector<int>> positions;

		for(int x = 0; x < v.size(); x++){
			if(v[x] == bsize){
				cont++;
				std::vector<int> v2;
				int o = 0;

				v2.push_back(h - (bsize + 1));
				v2.push_back(h + (bsize - 1) - (bsize + 1));

				positions.push_back(v2);
			}
			h++;
		}

		cout << "Caso " << k + 1 << ": " << cont << endl;
		int g = 0, q = 0;
		if(cont){
			for(auto pos : positions){
					cout << pos[0] << " " << pos[pos.size() - 1];
					if(q != positions.size() - 1)
						cout << " ";
					q++;

			}
		}
		else{
			cout << "VEM DE ZAP!!";
		}

		cout << endl;
	}
	return 0;
}
