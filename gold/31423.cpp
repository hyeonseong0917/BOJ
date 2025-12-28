#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

vector<ll> g[500000+1];
vector<string> v;
void dfs(ll cur_num){
	cout<<v[cur_num];
	for(ll i=0;i<g[cur_num].size();++i){
		ll next_num=g[cur_num][i];
		dfs(next_num);
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			v.push_back(s);
		}
		vector<ll> check(n,0);
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			g[a].push_back(b);
			++check[b];
		}
		ll root_num=-1;
		for(ll i=0;i<n;++i){
			if(!check[i]){
				root_num=i;
			}
		}
		dfs(root_num);

	}
	return 0;
}