#include <bits/stdc++.h>

#define MAX 10000

using namespace std;

int st[MAX][MAX];

int cs=9999999,cr=1,ci=1;

int edit(vector<int> s, vector<int> t){

    int m = s.size();
    int n = t.size();

    for (int i = 0; i <= m; ++i)
        st[i][0] = i*cr;

    for (int j = 1; j <= n; ++j)
        st[0][j] = j*ci;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int insertion = st[i][j - 1] + ci;
            int deletion = st[i - 1][j] + cr;
            int change = st[i - 1][j - 1] + cs * (s[i - 1] == t[j - 1] ? 0 : 1);
            st[i][j] = min(insertion, deletion);
            st[i][j] = min(st[i][j], change);
        }

	return st[m][n];
}

int main(){

	int t;

	cin >> t;

	for(int i = 1; i <= t; i++){
		int cenas, custo;

		cin >> cenas >> custo;
		
		string aux = "";
		std::vector<int> aux2;
		int segundos = 0;
		for(int j = 0; j < cenas; j++){
			cin >> aux;
			if(aux != "x")
				aux2.push_back(stoi(aux));
			else
				segundos += custo;
		}
		
		std::vector<int> tmp = aux2;
		
		sort(tmp.begin(), tmp.end());
		//ci = cr = cs = custo;
		int diff = edit(aux2, tmp);


		segundos += custo * (diff);

		int min = segundos / 60;
		segundos -= min*60;

		int hour = min / 60;
		min -= hour*60;

		cout << "Caso " << i << ": " << hour << " hora(s), " 
		     << min << " minuto(s), " << segundos << " segundo(s)"<< endl;
	}

	return 0;

}
