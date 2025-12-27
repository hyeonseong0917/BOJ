#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


ll n;
vector<ll> v[1000+1];
ll check[1000+1];
vector<ll> visited(1000+1,0);
bool flag=0;
vector<ll> tmp;
void dfs(ll cur_num, ll fin_num){
	// cout<<"fd"<<cur_num<<" "<<fin_num<<endl;
	if(flag) return;
	if(cur_num==fin_num){
		flag=1;
		return;
	}
	for(ll i=0;i<v[cur_num].size();++i){
		ll next_num=v[cur_num][i];
		if(visited[next_num]) continue;
		visited[next_num]=1;
		tmp.push_back(next_num);

		dfs(next_num,fin_num);
		if(flag) return;
		tmp.pop_back();
		visited[next_num]=0;
	}
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		for(ll i=0;i<=1000;++i){
			check[i]=0;
		}
		cin>>n;
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		ll q;
		cin>>q;
		while(q--){
			ll a;
			cin>>a;
			if(a==1){
				// b에서 c까지 배달함
				ll b,c;
				cin>>b>>c;
				// i번째 방에 i개의 우유를 제공함
				for(ll i=1;i<=n;++i){
					visited[i]=0;
				}
				visited[b]=1;
				flag=0;
				tmp.clear();
				tmp.push_back(b);

				dfs(b,c);
				for(ll i=0;i<tmp.size();++i){
					check[tmp[i]]+=i;
					// cout<<b<<" "<<c<<" "<<i<<" "<<tmp[i]<<"\n";
				}
			}else{
				// 지금까지 b번방에 전달한 우유의 개수
				ll b;
				cin>>b;
				cout<<check[b]<<"\n";
			}
		}
	}
	return 0;
}