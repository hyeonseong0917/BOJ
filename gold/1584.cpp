#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};

ll n,m;
ll dist[500+1][500+1];
ll check[500+1][500+1];
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<=500 && x<=500);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		for(ll i=0;i<=500;++i){
			for(ll j=0;j<=500;++j){
				check[i][j]=0;
			}
		}
		cin>>n;
		for(ll i=0;i<n;++i){
			ll a1, b1, a2, b2;
			cin >> a1 >> b1 >> a2 >> b2;
			ll a = min(a1, a2);
			ll b = min(b1, b2);
			ll c = max(a1, a2);
			ll d = max(b1, b2);
			for(ll j=a;j<=c;++j){
				for(ll k=b;k<=d;++k){
					check[j][k]=1;
				}
			}
		}
		cin>>m;
		for(ll i=0;i<m;++i){
			ll a1, b1, a2, b2;
			cin >> a1 >> b1 >> a2 >> b2;
			ll a = min(a1, a2);
			ll b = min(b1, b2);
			ll c = max(a1, a2);
			ll d = max(b1, b2);
			for(ll j=a;j<=c;++j){
				for(ll k=b;k<=d;++k){
					check[j][k]=2;
				}
			}
		}
		for(ll i=0;i<=500;++i){
			for(ll j=0;j<=500;++j){
				dist[i][j]=2023101800;
			}
		}
		if(check[500][500]==2){
			cout<<-1;
			break;
		}
		dist[0][0]=0;
		priority_queue<pair<ll,pair<ll,ll>>> pq;
		pq.push({0,{0,0}});
		while(!pq.empty()){
			ll cur_dist=pq.top().first*-1;
			ll y=pq.top().second.first;
			ll x=pq.top().second.second;
			if(dist[y][x]<cur_dist) continue;
			// cout<<y<<" "<<x<<endl;
			pq.pop();
			for(ll i=0;i<4;++i){
				ll ny=y+dy[i];
				ll nx=x+dx[i];
				if(!isRange(ny,nx)) continue;
				if(check[ny][nx]==2) continue;
				if(dist[ny][nx]>dist[y][x]+check[ny][nx]){
					dist[ny][nx]=dist[y][x]+check[ny][nx];
					pq.push({dist[ny][nx]*-1,{ny,nx}});
				}
				// 아니라면

			}

		}
		if(dist[500][500]==2023101800){
			cout<<-1;
		}else{
			cout<<dist[500][500];
		}
		
	}

	return 0;
}