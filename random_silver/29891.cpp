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
		ll n,k;
		cin>>n>>k;
		vector<ll> fst_v, sed_v;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			if(a<0){
				fst_v.push_back(a*-1);
			}else{
				sed_v.push_back(a);
			}
		}
		sort(fst_v.rbegin(),fst_v.rend());
		sort(sed_v.rbegin(),sed_v.rend());
		ll ans=0;
		ll idx=0;
		ll cnt=0;
		while(idx<fst_v.size()){
			if(cnt%k==0){
				ans+=fst_v[idx]*2;
			}
			++idx;
			++cnt;
		}
		cnt=0;
		while(idx<sed_v.size()){
			if(cnt%k==0){
				ans+=sed_v[idx]*2;
			}
			++idx;
			++cnt;
		}
		cout<<ans;
	} 
	return 0;
}