#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

ll board[1000+1][1000+1];
ll n,m;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
			}
		}
		
		ll ans=0;
		// 4 3
		// 7 5
		bool is_zero=0;
		ll min_num=2023101800;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(!board[i][j]){
					is_zero=1;
				}
				ans+=board[i][j];
				if(board[i][j]){
					min_num=min(min_num,board[i][j]);
				}
			}
		}
		if(!is_zero){
			ans-=min_num;
		}
		cout<<ans;
	} 
	return 0;
}