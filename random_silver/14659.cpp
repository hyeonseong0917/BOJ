#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;	
	// cin>>t;
	while(t--){	
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll ans=0;
		ll cnt=0;
		ll cur_num=v[0];
		for(ll i=1;i<n;++i){
			if(cur_num<v[i]){
				ans=max(ans,cnt);
				cnt=0;
				cur_num=v[i];
			}else{
				++cnt;
			}
		}
		ans=max(ans,cnt);
		cout<<ans;
	}
	return 0;
}