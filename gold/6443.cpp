#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

vector<string> ans;
vector<ll> visited(20+1,0);
map<string,ll> check;

void dfs(string cur_str, string fin_str){
	// cout<<cur_str<<endl;
	ll cs=cur_str.size();
	ll fs=fin_str.size();
	if(cs==fs){
		ans.push_back(cur_str);
		return;
	}
	for(ll i=0;i<fs;++i){
		if(!visited[i]){
			visited[i]=1;
			cur_str+=fin_str[i];
			if(!check[cur_str]){
				++check[cur_str];
				dfs(cur_str,fin_str);
			}
			cur_str=cur_str.substr(0,cs);
			visited[i]=0;
			
		}
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1246
		ll n;
		cin>>n;
		vector<string> v;
		map<string,ll> m;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			v.push_back(s);
			sort(s.begin(),s.end());
			if(!m[s]){
				++m[s];
				check.clear();
				for(ll j=0;j<20;++j){
					visited[j]=0;
				}
				dfs("",s);
			}
		}
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<"\n";
		}

	}
	return 0;
}