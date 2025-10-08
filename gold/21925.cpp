#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n%2==1){
			cout<<-1;
		}else{
			vector<ll> tmp;
			ll ans=0;
			for(ll i=0;i<n;++i){
				if(tmp.empty()){
					tmp.push_back(v[i]);
				}else{
					// tmp 길이 짝수이면서 팰린드롬인지?
					ll ts=tmp.size();
					if(ts%2==0){
						// 팰린드롬인지?
						vector<ll> fst_v, sed_v;
						for(ll i=0;i<ts/2;++i){
							fst_v.push_back(tmp[i]);
						}
						for(ll i=ts/2;i<ts;++i){
							sed_v.push_back(tmp[i]);
						}
						reverse(sed_v.begin(),sed_v.end());
						bool flag=0;
						for(ll i=0;i<ts/2;++i){
							if(fst_v[i]!=sed_v[i]){
								flag=1;
								break;
							}
						}
						if(!flag){
							tmp.clear();
							++ans;
						}
						tmp.push_back(v[i]);
					}else{
						tmp.push_back(v[i]);
					}
				}
			}
			ll ts=tmp.size();
			if(tmp.empty()){
				cout<<ans;
			}else{
				vector<ll> fst_v, sed_v;
				ll ts=tmp.size();
				for(ll i=0;i<ts/2;++i){
					fst_v.push_back(tmp[i]);
				}
				for(ll i=ts/2;i<ts;++i){
					sed_v.push_back(tmp[i]);
				}
				reverse(sed_v.begin(),sed_v.end());
				bool flag=0;
				for(ll i=0;i<ts/2;++i){
					if(fst_v[i]!=sed_v[i]){
						flag=1;
						break;
					}
				}
				if(!flag){
					tmp.clear();
					++ans;
					cout<<ans;
				}else{
					cout<<-1;
				}
			}
		}
	}
	return 0;
}