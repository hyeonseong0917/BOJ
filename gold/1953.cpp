#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


ll n;
vector<ll> g[101];
ll visited[101];
void Input(){
	cin>>n;
	for(ll i=1;i<=n;++i){
		ll a;
		cin>>a;
		while(a--){
			ll b;
			cin>>b;
			g[i].push_back(b);
		}
		visited[i]=0;
	}
}
vector<ll> fst_vec, sed_vec;

void dfs(ll cur_num, ll cur_cnt){
	// cout<<cur_num<<" "<<cur_cnt<<endl;
	if((cur_cnt%2)==0){
		fst_vec.push_back(cur_num);
	}else{
		sed_vec.push_back(cur_num);
	}
	for(ll i=0;i<g[cur_num].size();++i){
		ll next_num=g[cur_num][i];
		if(!visited[next_num]){
			visited[next_num]=1;
			dfs(next_num,cur_cnt+1);
		}
	}
}
void solve(){
	for(ll i=1;i<=n;++i){
		if(!visited[i]){
			visited[i]=1;
			dfs(i,0);
		}
	}
	sort(fst_vec.begin(),fst_vec.end());
	sort(sed_vec.begin(),sed_vec.end());
	ll fs=fst_vec.size();
	cout<<fs<<"\n";
	for(ll i=0;i<fs;++i){
		cout<<fst_vec[i];
		if(i!=fs-1){
			cout<<" ";
		}
	}cout<<"\n";

	ll ss=sed_vec.size();
	cout<<ss<<"\n";
	for(ll i=0;i<ss;++i){
		cout<<sed_vec[i];
		if(i!=ss-1){
			cout<<" ";
		}
	}cout<<"\n";
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		Input();
		solve();
	}

	return 0;
}