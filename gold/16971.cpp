#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll board[1000+1][1000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n,m;
		cin>>n>>m;
		ll ans=0;
		ll sum=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
			}
		}
		for(ll i=0;i<n-1;++i){
			for(ll j=0;j<m-1;++j){
				sum+=board[i][j]+board[i+1][j]+board[i][j+1]+board[i+1][j+1];
			}
		}
		vector<ll> row(n,0), col(m,0);
		// row[x]: x번째 행의 board[x][0]+board[x][m-1]+2*(board[x][1,m-2])
		for(ll i=0;i<n;++i){
			ll cur_sum=board[i][0]+board[i][m-1];
			for(ll j=1;j<m-1;++j){
				cur_sum+=board[i][j]*2;
			}
			row[i]=cur_sum;
		}
		for(ll i=0;i<m;++i){
			ll cur_sum=board[0][i]+board[n-1][i];
			for(ll j=1;j<n-1;++j){
				cur_sum+=board[j][i]*2;
			}
			col[i]=cur_sum;
		}
		// 행 교체
		ll max_diff=0;
		for(ll i=1;i<n-1;++i){
			if(row[i]<row[0]){
				max_diff=max(max_diff,row[0]-row[i]);
			}
		}
		for(ll i=1;i<n-1;++i){
			if(row[i]<row[n-1]){
				max_diff=max(max_diff,row[n-1]-row[i]);
			}
		}
		for(ll i=1;i<m-1;++i){
			if(col[i]<col[0]){
				max_diff=max(max_diff,col[0]-col[i]);
			}
		}
		for(ll i=1;i<m-1;++i){
			if(col[i]<col[m-1]){
				max_diff=max(max_diff,col[m-1]-col[i]);
			}
		}
		cout<<sum+max_diff;
	}
	return 0;
}