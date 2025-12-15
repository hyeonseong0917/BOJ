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
	ll o=1;	
	while(o--){
		// 0129
		ll n,k;
		cin>>n>>k;
		vector<ll> fst_v, sed_v;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			if(a==0) continue;
			if(a>0){
				fst_v.push_back(a);
			}else{
				sed_v.push_back(a*-1);
			}
		}
		sort(fst_v.rbegin(),fst_v.rend());
		sort(sed_v.rbegin(),sed_v.rend());
		ll ans=0;
		ll fst_idx=0;
		ll fs=fst_v.size();
		while(fst_idx<fs){
			ll cnt=k;
			ans+=fst_v[fst_idx]*2;
			fst_idx+=k;
		}
		ll sed_idx=0;
		ll ss=sed_v.size();
		while(sed_idx<ss){
			ll cnt=k;
			ans+=sed_v[sed_idx]*2;
			sed_idx+=k;
		}
		cout<<ans;
	} 
	return 0;
}