#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll n,m,k;
// k그루만 수확
ll board[1000+1][1000+1];
bool visited[1000+1][1000+1];
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m;	
		priority_queue<pair<ll,pair<ll,ll>>> pq;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
				if(i==0 || j==0 || i==n-1 || j==m-1){
					if(!visited[i][j]){
						visited[i][j]=1;
						pq.push({board[i][j],{i,j}});
					}
				}
			}
		}
		cin>>k;
		for(ll i=0;i<k;++i){
			ll cur_num=pq.top().first;
			ll y=pq.top().second.first;
			ll x=pq.top().second.second;
			pq.pop();
			cout<<y+1<<" "<<x+1<<"\n";
			for(ll j=0;j<4;++j){
				ll ny=y+dy[j];
				ll nx=x+dx[j];
				if(!isRange(ny,nx)) continue;
				if(visited[ny][nx]) continue;
				visited[ny][nx]=1;
				pq.push({board[ny][nx],{ny,nx}});
			}
		}
		
	}	
	return 0;
}