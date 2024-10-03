#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll a,b,c;
		ll x,y,z;
		cin>>a>>b>>c;
		cin>>x>>y>>z;
		vector<pair<ll,ll>> v;
		v.push_back({a,x});
		v.push_back({b,y});
		v.push_back({c,z});
		ll ans=0;
		for(ll i=0;i<3;++i){
			ans+=min(v[i].second,v[i].first);
			ll tmp=v[i].first;
			v[i].first-=min(v[i].second,v[i].first);
			v[i].second-=min(v[i].second,tmp);
		}
		// cout<<ans<<endl;
		for(ll i=0;i<3;++i){
			if(i==0){
				ll fst_num=min(v[1].first, v[0].second/3);
				ans+=fst_num;
				v[1].first-=fst_num;
				v[0].second-=fst_num*3;
				ll sed_num=min(v[2].first, v[0].second/9);
				ans+=sed_num;
				v[2].first-=sed_num;
				v[0].second-=sed_num*9;
			}else if(i==1){
				ll fst_num=min(v[2].first, v[1].second/3);
				ans+=fst_num;
				v[2].first-=fst_num;
				v[1].second-=fst_num*3;
				// cout<<v[1].second<<"\n";
				ll sed_num=min(v[0].first, v[1].second/9);
				ans+=sed_num;
				v[0].first-=sed_num;
				v[1].second-=sed_num*9;
				// cout<<v[1].second<<endl;
			}else{
				ll fst_num=min(v[0].first, v[2].second/3);
				ans+=fst_num;
				v[0].first-=fst_num;
				v[2].second-=fst_num*3;
				ll sed_num=min(v[1].first, v[2].second/9);
				ans+=sed_num;
				v[1].first-=sed_num;
				v[2].second-=sed_num*9;
			}
		}
		cout<<ans;
	}
	return 0;
}