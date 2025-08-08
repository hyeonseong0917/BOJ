#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>t;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		
		ll ans=0;
		ll max_num=2000000000000+1;
		for(ll i=1;i<n;++i){
			if(abs(v[i]-v[i-1])>=m) continue;
			v[i]=max_num;
			++ans;
		}
		cout<<ans;
	} 
	return 0;
}