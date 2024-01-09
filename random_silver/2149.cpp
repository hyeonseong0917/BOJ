#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
//a>b

vector<pair<char,string>> v;
bool visited[100+5];
string ans="";
char board[100+5][100+5];
int main() {
	// your code goes here
	string s,t;
	cin>>s;
	cin>>t;
	string sorted_key=s;
	sort(sorted_key.begin(),sorted_key.end());
	int ks=s.size();
	for(int i=0;i<ks;++i){
		v.push_back({sorted_key[i],t.substr(i*(t.size()/ks),(t.size()/ks))});
		// cout<<t.size()/ks<<endl;
		// cout<<t.substr(i*(t.size()/ks),(t.size()/ks))<<endl;
	}
	for(int i=0;i<s.size();++i){
		for(int j=0;j<v.size();++j){
			if(visited[j]) continue;
			if(s[i]==v[j].first){
				visited[j]=1;
				for(int k=0;k<v[j].second.size();++k){
					board[i][k]=v[j].second[k];
				}
				break;
			}
		}
	}
	for(int i=0;i<t.size()/ks;++i){
		string tmp="";
		for(int j=0;j<ks;++j){
			tmp+=board[j][i];
		}
		ans+=tmp;
	}
	cout<<ans;
	return 0;
}