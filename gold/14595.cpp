#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

vector<ll> parent(1000000+1,0);
ll FIND(ll a){
	if(a==parent[a]) return a;
	return parent[a]=FIND(parent[a]);
}
void UNION(ll a, ll b){
	a=FIND(a);
	b=FIND(b);
	if(a!=b){
		parent[a]=b;
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		// 1517
		// n개의 방 중 하나
		// 각 방에는 번호가 매겨짐
		// 1 2 3 ... n
		// 각 방 사이에 벽이 존재
		// x<y인 두 방에 대해 x번방과 y번방 사이의 모든 벽 삭제
		// 벽 허물어지면 하나의 방으로
		// 1번방과 n번방의 오른쪽 벽
		ll n,m;
		cin>>n>>m;
		for(ll i=1;i<=n;++i){
			parent[i]=i;
		}
		ll cnt=0;
		// 2 7
		// 3 5
		// 4 10

		// 1 2 3 4 5 6 7 8 9 10
		vector<pair<ll,ll>> v;
		for(ll i=0;i<m;++i){
			ll x,y;
			cin>>x>>y;
			v.push_back({x,y});
			
		}
		if(m==0){
			cout<<n;
			break;
		}
		sort(v.begin(),v.end());
		cnt=v[0].second-v[0].first;
		ll last_num=v[0].second;
		// UNION(v[0].first,v[0].second);
		for(ll i=1;i<m;++i){
			ll x=v[i].first;
			ll y=v[i].second;
			if(x>last_num){
				last_num=max(last_num,y);
				cnt+=y-x;
			}else{
				// x<=last_num
				if(y>last_num){
					cnt+=y-last_num;
					last_num=y;
				}
			}
		}
		// 1 2 3 4 5
		cout<<n-cnt;
		// x번 방과 y번방 사이의 모든 벽을 삭제제
		// 1 3
		// 2 4
		// 5 8
		// 1 2 3 4 5 6 7 8 9 10

	}	
	return 0;
}