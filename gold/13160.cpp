#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
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
		vector<pair<ll,ll>> v;
		map<ll,ll> check;
		vector<ll> tmp;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
			if(!check[a]){
				++check[a];
				tmp.push_back(a);
			}
			if(!check[b]){
				++check[b];
				tmp.push_back(b);
			}
		}
		sort(tmp.begin(),tmp.end());
		ll cnt=1;
		map<ll,ll> order;
		for(ll i=0;i<tmp.size();++i){
			order[tmp[i]]=cnt++;
		}
		for(ll i=0;i<n;++i){
			ll a=v[i].first;
			ll b=v[i].second;
			v[i].first=order[a];
			v[i].second=order[b];
		}
		vector<ll> diff(2*n+2,0);
		diff[0]=0;
		for(ll i=0;i<n;++i){
			ll a=v[i].first;
			ll b=v[i].second;
			++diff[a];
			--diff[b+1];
		}
		vector<ll> result(2*n+1,0);
		ll max_num=0;
		ll max_pos=-1;
		for(ll i=1;i<=2*n;++i){
			result[i]=result[i-1]+diff[i];
			if(result[i]>max_num){
				max_num=result[i];
				max_pos=i;
			}
		}
		// cout<<max_num;
		vector<ll> ans;
		for(ll i=0;i<n;++i){
			ll a=v[i].first;
			ll b=v[i].second;
			if(a<=max_pos && max_pos<=b){
				ans.push_back(i+1);
			}
		}
		cout<<max_num<<"\n";
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}