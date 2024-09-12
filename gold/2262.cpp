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
		ll n;
		cin>>n;
		vector<ll> v;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			v.push_back(a);
		}
		ll ans=0;
		while(v.size()!=1){
			vector<ll> tmp;
			ll max_idx=-1;
			ll max_num=-1;
			for(ll i=0;i<v.size();++i){
				if(max_num<v[i]){
					max_num=v[i];
					max_idx=i;
				}
				tmp.push_back(v[i]);
			}
			ll next_idx=-1;
			ll fst_diff=122232421, sed_diff=122232421;
			if(max_idx-1>=0){
				fst_diff=abs(v[max_idx]-v[max_idx-1]);
			}
			if(max_idx+1<v.size()){
				sed_diff=abs(v[max_idx]-v[max_idx+1]);
			}
			if(fst_diff<sed_diff){
				next_idx=max_idx-1;
				v.clear();
				for(ll i=0;i<tmp.size();++i){
					if(i==max_idx) continue;
					if(i==next_idx){
						v.push_back(min(tmp[i],tmp[i+1]));
						ans+=abs(tmp[i]-tmp[i+1]);
					}else{
						v.push_back(tmp[i]);
					}
				}
			}else{
				next_idx=max_idx+1;
				v.clear();
				for(ll i=0;i<tmp.size();++i){
					if(i==next_idx) continue;
					if(i==max_idx){
						v.push_back(min(tmp[i],tmp[i+1]));
						ans+=abs(tmp[i]-tmp[i+1]);
					}else{
						v.push_back(tmp[i]);
					}
				}
			}
			
		}
		cout<<ans;
	}
	return 0;
}