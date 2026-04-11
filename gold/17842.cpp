#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> g[n];
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(g[i].size()==1){
				++ans;
			}
		}
		cout<<(ans+1)/2;
	}
	return 0;
}