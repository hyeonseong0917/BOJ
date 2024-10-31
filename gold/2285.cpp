#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		ll sum=0;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
			sum+=b;
		}
		sort(v.begin(),v.end());
		
		ll pos=0;
		ll cur_sum=0;
		for(ll i=0;i<n;++i){
			cur_sum+=v[i].second;
			if(cur_sum>=(sum+1)/2){
				pos=v[i].first;
				break;
			}
		}
		cout<<pos;
	}
	return 0;
}