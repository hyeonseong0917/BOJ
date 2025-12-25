#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll n;
vector<ll> v[100000+1];
vector<ll> visited(100000+1);
vector<ll> check(100000+1);
string color;
ll cnt=0;
vector<ll> tmp;
void dfs(ll cur_num){
	++cnt;
	for(ll i=0;i<v[cur_num].size();++i){
		ll next_num=v[cur_num][i];
		if(visited[next_num]) continue;
		if(color[next_num-1]=='B') continue;
		visited[next_num]=1;
		tmp.push_back(next_num);
		dfs(next_num);
	}
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		cin>>color;
		ll ans=0;
		for(ll i=1;i<=n;++i){
			if(visited[i]) continue;
			if(color[i-1]=='B') continue;
			// dfs한 번 돌려서 전체 노드 개수를 구한다
			// 해당 노드 개수를 현재 단계에서 체크된 숫자들에 대해 마킹함
			// 필요한 것: 현재 탐색한 노드들 + 전체 노드 개수
			cnt=0;
			tmp.clear();
			tmp.push_back(i);
			visited[i]=1;
			dfs(i);
			for(ll j=0;j<tmp.size();++j){
				check[tmp[j]]=cnt;
			}
		}
		for(ll i=1;i<=n;++i){
			if(color[i-1]=='B'){
				for(ll j=0;j<v[i].size();++j){
					if(color[v[i][j]-1]=='B') continue;
					ans+=check[v[i][j]];
				}
			}
		}
		cout<<ans;
	}
	return 0;
}