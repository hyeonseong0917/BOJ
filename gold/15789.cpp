#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

ll n,m;
ll c,h,k;
vector<vector<ll>> v;
ll visited[100000+1];
ll check[1000000+1];
ll cnt=0;

void dfs(ll cur_pos, ll w){
	for(ll i=0;i<v[cur_pos].size();++i){
		ll next_pos=v[cur_pos][i];
		if(!visited[next_pos]){
			visited[next_pos]=w;
			dfs(next_pos,w);
		}
	}
}
void dfs_check(ll cur_pos){
	for(ll i=0;i<v[cur_pos].size();++i){
		ll next_pos=v[cur_pos][i];
		if(!check[next_pos]){
			++cnt;
			check[next_pos]=1;
			dfs_check(next_pos);
		}
	}
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		cin>>n>>m;
		for(ll i=0;i<=n;++i){
			vector<ll> tmp;
			v.push_back(tmp);
			visited[i]=0;
		}
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		cin>>c>>h>>k;
		visited[h]=1;
		dfs(h,1);
		visited[c]=2;
		dfs(c,2);
		vector<ll> p;
		// cout<<visited[4]<<endl;
		for(ll i=1;i<=n;++i){
			if(!visited[i]){
				p.push_back(i);
			}
		}
		// 여기까지 일단 중립국은 다 찾긴함
		// 이제 어떻게 해야??
		// 
		ll pn=p.size();
		vector<ll> w_save;
		for(ll i=0;i<pn;++i){
			if(check[p[i]]) continue;
			++check[p[i]];
			cnt=1;
			dfs_check(p[i]);
			w_save.push_back(cnt);
		}
		sort(w_save.rbegin(),w_save.rend());
		ll ans=0;
		for(ll i=1;i<=n;++i){
			if(visited[i]==2){
				++ans;
			}
		}
		ll ws=w_save.size();
		// for(ll i=0;i<p.size();++i){
		// 	cout<<p[i]<<" ";
		// }
		for(ll i=0;i<min(ws,k);++i){
			ans+=w_save[i];
		}

		cout<<ans;

		
		
		// 1. 한솔 왕국의 모든 동맹국을 구하기(h에서 시작해서 그래프 탐색)
		// 2. C왕국의 모든 동맹국 구하기(c에서 시작해서 그래프 탐색)
		// 3. 한솔왕국과 c왕국의 동맹국이 아닌 나라들의 번호 get
		// 5. 각 번호 순회하면서 루트가 방문하지 않은 번호라면, 탐색때리고 가중치 저장
		// 6. 가중치 내림차순 정렬하고 k개 가져가기


	}
	return 0;
}