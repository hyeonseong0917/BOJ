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
		ll n,m;
		cin>>n>>m;
		ll k=0;
		cin>>k;
		vector<ll> h,w;
		h.push_back(0);
		h.push_back(n);
		w.push_back(0);
		w.push_back(m);
		for(ll i=0;i<k;++i){
			ll a,b;
			cin>>a>>b;
			// 0: 가로점선
			// 1: 세로점선
			if(a==0){
				w.push_back(b);
			}else{
				h.push_back(b);
			}
		}
		sort(w.begin(),w.end());
		sort(h.begin(),h.end());
		vector<ll> h_diff, w_diff;
		for(ll i=1;i<h.size();++i){
			h_diff.push_back(h[i]-h[i-1]);
		}
		for(ll i=1;i<w.size();++i){
			w_diff.push_back(w[i]-w[i-1]);
		}
		ll ans=0;
		for(ll i=0;i<h_diff.size();++i){
			for(ll j=0;j<w_diff.size();++j){
				ans=max(ans,h_diff[i]*w_diff[j]);
			}
		}
		cout<<ans;
	}
	return 0;
}