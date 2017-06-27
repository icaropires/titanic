#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int st[MAX][MAX];
int lp_dp(const string& s, int i , int j){
	if(i>j)return 0;
	if(i==j)return 1;
	if(st[i][j]!=-1)return st[i][j];
	int res = max(lp_dp(s,i+1,j),lp_dp(s,i,j-1));
	if(s[i]==s[j])res = max(res, lp_dp(s,i+1,j-1)+2);
	st[i][j]=res;
	return res;
}


int lps(const string& s){
	int n = s.size();
	for(int i =0; i<n; ++i)
		for(int j =0; j<n; ++j)
			st[i][j]=-1;
	return lp_dp(s,0,n-1);
}

int main(){

	int n ;
	string input;
	cin >> n; 
	for(int i=0; i<n; ++i){
		cin >> input;
		cout <<"Caso " << i+1 << ": "<< (input.size()-lps(input)) << endl;
	}
	

 return 0;
}

