#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
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
		ll ans=0;
		ll cur_pos=0;
		vector<ll> tmp;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a;
			if(a==1){
				cin>>b;
				tmp.push_back(b);
			}else{
				// 쓰레기 다 수거해야함
				// 현재 위치 기준으로 가장 가까운 곳부터?
				if(tmp.empty()) continue;
				sort(tmp.begin(),tmp.end());
				ll idx=0;
				ll diff=2023101800;
				for(ll j=0;j<tmp.size();++j){
					ll c=(ll)abs(tmp[j]-cur_pos);
					if(c<diff){
						diff=c;
						idx=j;
					}
				}
				// idx에서 시작
				ans+=abs(cur_pos-tmp[idx]);
				cur_pos=tmp[idx];
				ll L=idx-1;
				ll R=idx+1;
				ll ts=tmp.size();
				while(L>=0 || R<ts){
					if(L<0){
						ans+=abs(cur_pos-tmp[R]);
						cur_pos=tmp[R];
						++R;
					}else if(R>=ts){
						ans+=abs(cur_pos-tmp[L]);
						cur_pos=tmp[L];
						--L;
					}else{
						ll fst_diff=abs(cur_pos-tmp[L]);
						ll sed_diff=abs(cur_pos-tmp[R]);
						if(fst_diff<=sed_diff){
							ans+=abs(cur_pos-tmp[L]);
							cur_pos=tmp[L];
							--L;
						}else{
							ans+=abs(cur_pos-tmp[R]);
							cur_pos=tmp[R];
							++R;
						}
					}
				}

				tmp.clear();
			}
		}
		cout<<ans;
	}
	return 0;
}