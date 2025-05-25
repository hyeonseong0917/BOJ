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

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,b;
		cin>>n>>b;
		vector<pair<ll,pair<ll,ll>>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a+b,{a,b}});
		}
		sort(v.begin(),v.end());
		// 물건가격 절반으로 할 수 있는 쿠폰 1개 보유중
		ll ans=0;
		for(ll i=0;i<n;++i){
			// i번째 물건 가격 절반으로
			ll sum=v[i].second.first/2+v[i].second.second;
			ll cnt=0;
			if(sum<=b){
				++cnt;
			}
			for(ll j=0;j<n;++j){
				if(i==j) continue;
				sum+=v[j].first;
				if(sum<=b){
					++cnt;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	} 
	return 0;
}