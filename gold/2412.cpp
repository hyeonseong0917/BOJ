#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long

ll n,T;
map<pair<ll,ll>,ll> check,dist;
ll x,y;

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>T;	
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			++check[{a,b}];
		}
		x=0, y=0;
		queue<pair<ll,ll>> q;
		q.push({x,y});
		ll ans=2023101800;
		while(!q.empty()){
			ll cx=q.front().first;
			ll cy=q.front().second;
			ll cd=dist[{cx,cy}];
			// cout<<cx<<" "<<cy<<" "<<cd<<endl;
			if(cy==T){
				ans=min(ans,cd);
			}
			q.pop();
			for(ll i=max(0ll,cx-2);i<=cx+2;++i){
				for(ll j=max(0ll,cy-2);j<=min(cy+2,T);++j){
					if(check[{i,j}]){
						if(!dist[{i,j}]){
							dist[{i,j}]=cd+1;
							q.push({i,j});
						}else{
							if(dist[{i,j}]>cd+1){
								dist[{i,j}]=cd+1;
								q.push({i,j});
							}
						}
					}
				}
			}
		}
		if(ans==2023101800){
			ans=-1;
		}
		cout<<ans;

	}
	return 0;
}