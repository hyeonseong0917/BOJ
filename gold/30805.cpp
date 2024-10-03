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
		ll n;
		cin>>n;
		map<ll,ll> a_map, b_map;
		vector<ll> a_vec,b_vec;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			++a_map[a];
			a_vec.push_back(a);
		}
		ll m;
		cin>>m;
		for(ll i=0;i<m;++i){
			ll a;
			cin>>a;
			++b_map[a];
			b_vec.push_back(a);
		}
		vector<ll> A,B;
		for(ll i=0;i<n;++i){
			if(b_map[a_vec[i]]){
				A.push_back(a_vec[i]);
			}
		}
		for(ll i=0;i<m;++i){
			if(a_map[b_vec[i]]){
				B.push_back(b_vec[i]);
			}
		}
		ll as=A.size();
		ll bs=B.size();
		// cout<<as<<" "<<bs<<endl;
		ll ans=0;
		vector<ll> ans_v;
		for(ll i=0;i<as;++i){
			ll L=i, R=0;
			vector<ll> tmp;
			// 만약 A[L]이 B에 없었다면?
			ll last_R=0;
			while(L<as){
				if(R==bs){
					++L;
					R=last_R;
					continue;
				}
				if(A[L]==B[R]){
					bool flag=0;
					for(ll j=L+1;j<as;++j){
						if(A[L]<A[j]){
							// A[j]를 B에서 찾아보자
							ll idx=-1;
							for(ll k=last_R;k<bs;++k){
								if(B[k]==A[j]){
									idx=k;
								}
							}
							if(idx!=-1){
								flag=1;
								break;
							}
						}
					}
					if(flag){
						++L;
						R=last_R;
					}else{
						tmp.push_back(A[L]);
						++L;
						++R;
						last_R=R;
					}
				}else{
					++R;
				}
			}
			if(tmp.empty()) continue;
			if(ans_v.empty()){
				for(ll j=0;j<tmp.size();++j){
					ans_v.push_back(tmp[j]);
				}
				continue;
			}
			ll ts=tmp.size();
			ll as=ans_v.size();
			bool flag=0;
			for(ll j=0;j<min(ts,as);++j){
				if(ans_v[j]<tmp[j]){
					flag=1;
					break;
				}else if(ans_v[j]>tmp[j]){
					break;
				}
			}
			// for(ll j=0;j<tmp.size();++j){
			// 	cout<<tmp[j]<<" ";
			// }cout<<endl;
			if(flag){
				ans_v.clear();
				for(ll j=0;j<ts;++j){
					ans_v.push_back(tmp[j]);
				}
			}else{
				// !flag중에 부분집합 수열이 있을 수 있다
				bool flag=0;
				for(ll j=0;j<min(ts,as);++j){
					if(ans_v[j]!=tmp[j]){
						flag=1;
						break;
					}
				}
				if(as<ts && !flag){
					ans_v.clear();
					for(ll j=0;j<ts;++j){
						ans_v.push_back(tmp[j]);
					}
				}
			}
		}
		if(ans_v.empty()){
			cout<<ans;
		}else{
			ans=ans_v.size();
			cout<<ans<<"\n";
			for(ll i=0;i<ans;++i){
				cout<<ans_v[i]<<" ";
			}
		}

	}
	return 0;
}