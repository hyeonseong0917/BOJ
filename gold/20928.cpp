#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> p(n,0);
		vector<ll> x(n,0);
		for(ll i=0;i<n;++i){
			cin>>p[i];
		}
		for(ll i=0;i<n;++i){
			cin>>x[i];
		}
		ll ans=0;
		ll max_range=p[0]+x[0];
		ll tmp_range=max_range;
		ll idx=1;
		bool flag=0;
		while(idx<n){
			if(max_range>=m) break;
			if(max_range<p[idx]){
				max_range=tmp_range;
				if(max_range<p[idx]){
					flag=1;
					break;
				}
				++ans;
			}else{
				tmp_range=max(tmp_range,p[idx]+x[idx]);
				++idx;
			}
		}
		if(max_range<m){
			max_range=tmp_range;
			if(max_range<m){
				flag=1;
			}
			++ans;
		}
		if(flag){
			cout<<-1;
		}else{
			cout<<ans;
		}

	}
		

	return 0;
}