#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll dist[100+1][100+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v[n+1];
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=n;++j){
				if(i==j){
					dist[i][j]=0;
					continue;
				}
				dist[i][j]=2023101800;
			}
		}
		for(ll i=1;i<=n;++i){
			// i에서 출발
			queue<ll> q;
			q.push(i);
			vector<ll> tmp_dist(n+1,2023101800);
			tmp_dist[i]=0;
			while(!q.empty()){
				ll cur_num=q.front();
				q.pop();
				for(ll j=0;j<v[cur_num].size();++j){
					ll next_num=v[cur_num][j];
					if(tmp_dist[next_num]>tmp_dist[cur_num]+1){
						tmp_dist[next_num]=tmp_dist[cur_num]+1;
						q.push(next_num);
					}
				}
			}
			for(ll j=1;j<=n;++j){
				dist[i][j]=tmp_dist[j];
				// cout<<i<<" "<<j<<" "<<dist[i][j]<<endl;
			}
		}
		ll a,b,c=2023101800;
		for(ll i=1;i<=n;++i){
			for(ll j=i+1;j<=n;++j){
				// i랑 j에 치킨집 차림
				ll sum=0;
				for(ll k=1;k<=n;++k){
					if(k==i || k==j) continue;
					// k에서 i까지

					// k에서 j까지

					// 최솟값을 채용
					sum+=min(dist[k][i]+dist[i][k],dist[k][j]+dist[j][k]);
				}
				// cout<<i<<" "<<j<<" "<<sum<<endl;
				if(sum<c){
					c=sum;
					a=i;
					b=j;
				}
			}
		}
		cout<<a<<" "<<b<<" "<<c;
	}
	return 0;
}