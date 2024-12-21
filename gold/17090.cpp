#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll n,m;
char board[500+1][500+1];
ll d[500+1][500+1];
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
ll dp(ll y, ll x){
	// cout<<y<<" "<<x<<" "<<d[y][x]<<endl;
	if(d[y][x]) return d[y][x];
	// y,x로 갈 수 있는 경로가 없다면 return 1
	ll sum=0;
	if(isRange(y-1,x) && board[y-1][x]=='D'){
		sum+=dp(y-1,x)+1;
	}
	if(isRange(y+1,x) && board[y+1][x]=='U'){
		sum+=dp(y+1,x)+1;
	}
	if(isRange(y,x+1) && board[y][x+1]=='L'){
		sum+=dp(y,x+1)+1;
	}
	if(isRange(y,x-1) && board[y][x-1]=='R'){
		sum+=dp(y,x-1)+1;
	}
	
	return d[y][x]=sum;

}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m;
		ll ans=0;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
				d[i][j]=0;
				if(board[i][j]=='U'){
					if(!isRange(i-1,j)){
						v.push_back({i,j});
					}
				}
				if(board[i][j]=='D'){
					if(!isRange(i+1,j)){
						v.push_back({i,j});
					}
				}
				if(board[i][j]=='L'){
					if(!isRange(i,j-1)){
						v.push_back({i,j});
					}
				}
				if(board[i][j]=='R'){
					if(!isRange(i,j+1)){
						v.push_back({i,j});
					}
				}
			}
		}
		// cout<<dp(2,0)<<endl;
		// ans+=v.size();
		for(ll i=0;i<v.size();++i){
			ll y=v[i].first;
			ll x=v[i].second;
			ans+=dp(y,x)+1;
		}
		cout<<ans;

	}
	return 0;
}