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
	ll o=1;
	while(o--){
		ll g;
		cin>>g;
		vector<ll> ans;
		vector<pair<ll,ll>> v;
		for(ll i=1;i<=sqrt(g);++i){
			if(g%i==0){
				if(i!=g/i){
					v.push_back({i,g/i});
				}
			}
		}
		if(v.empty()){
			cout<<-1;
		}else{
			for(ll i=0;i<v.size();++i){
				ll fst_num=v[i].first;
				ll sed_num=v[i].second;
				if((fst_num+sed_num)%2==1) continue;
				ans.push_back((fst_num+sed_num)/2);
			}
			if(ans.empty()){
				cout<<-1;
			}else{
				sort(ans.begin(),ans.end());
				for(ll i=0;i<ans.size();++i){
					cout<<ans[i]<<"\n";
				}
			}

		}

	}
	return 0;
}