#include <bits/stdc++.h>

#define MAX 1000010
using namespace std;

map<char,int> trie[MAX];
string vogais ="aeiou";

void build(const string& s){
	for(int i=0; i<MAX; ++i)trie[i].clear();
	int root=0, next=0;
	for(int i=0; i<s.size(); ++i){
		string suffix = s.substr(i);
		if(vogais.find(suffix[0])==string::npos)continue;
		int v=root;
		for(auto c : suffix){
			auto it = trie[v].find(c);
			if(it!=trie[v].end())v=it->second;
			else{
				trie[v][c] = ++next;
				v=next;
			}
		}
	}
}

size_t unique()
{
    queue<int> q;
    q.push(0);
    int count = 0;

    while (not q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto p : trie[u])
        {
            auto c = p.first;
            auto v = p.second;

            if (c != '#')
            {
                ++count;
                q.push(v);
            }
        }
    }    

    return count;
}

int main(){
	ios::sync_with_stdio(false);
	string input;
	int n;

	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> input;
		build(input+'#');
		cout << "Caso " << i+1 << ": " << unique() << endl;
	}
	
 return 0;
}
