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
// x번째 게임에서 y번째 웨폰을 선택
ll cache[500+1][500+1];
vector<vector<ll>> v;
ll dp(ll x, ll y){
	if(x==n-1){
		// cout<<x<<" "<<y<<endl;
		return 0;
	}
	if(x!=0 && cache[x][y]!=2023101800){
		return cache[x][y];
	}
	ll ret=2023101800;
	for(ll i=0;i<m;++i){
		if(i==y) continue;
		ret=min(ret,dp(x+1,i)+v[x+1][i]);
	}
	ll c=0;
	if(x==0){
		c=cache[x][y];
	}
	return cache[x][y]=ret+c;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		
		cin>>n>>m;
		
		for(ll i=0;i<n;++i){
			vector<ll> tmp;
			vector<ll> d;
			for(ll j=0;j<m;++j){
				ll a;
				cin>>a;
				tmp.push_back(a);
				d.push_back(2023101800);
				cache[i][j]=2023101800;
			}
			v.push_back(tmp);
			// dp.push_back(d);
		}
		for(ll i=0;i<m;++i){
			cache[0][i]=v[0][i];
		}
		ll ans=2023101800;
		for(ll i=0;i<m;++i){
			ans=min(ans,dp(0,i));
		}
		cout<<ans;		
	}
	return 0;
}