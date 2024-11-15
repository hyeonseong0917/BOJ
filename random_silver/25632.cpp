#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll a,b;
		ll c,d;
		cin>>a>>b;
		cin>>c>>d;
		vector<ll> is_prime(1000+1,0);
		is_prime[2]=1;
		for(ll i=3;i<=1000;++i){
			is_prime[i]=1;
			for(ll j=2;j<i;++j){
				if(i%j==0){
					is_prime[i]=0;
					break;
				}
			}
		}
		vector<ll> fst_tmp, sed_tmp;
		for(ll i=a;i<=b;++i){
			if(is_prime[i]){
				fst_tmp.push_back(i);
			}
		}
		for(ll i=c;i<=d;++i){
			if(is_prime[i]){
				sed_tmp.push_back(i);
			}
		}
		ll cnt=0;
		ll fs=fst_tmp.size();
		ll ss=sed_tmp.size();
		vector<bool> fst_check(fs,0);
		vector<bool> sed_check(ss,0);
		while(1){
			// yt가 자신의 패를 낸다
				// 1. fst_tmp와 sed_tmp 겹치는 게 있는지?
				ll fst_idx=-1, sed_idx=-1;
				for(ll i=0;i<fs;++i){
					if(fst_check[i]) continue;
					for(ll j=0;j<ss;++j){
						if(sed_check[j]) continue;
						if(fst_tmp[i]==sed_tmp[j]){
							fst_idx=i;
							sed_idx=j;
							break;
						}
					}
					if(fst_idx!=-1 && sed_idx!=-1) break;
				}
				if(fst_idx!=-1 && sed_idx!=-1){
					fst_check[fst_idx]=1;
					sed_check[sed_idx]=1;
				}else{
					bool flag=0;
					if(cnt%2==0){
						for(ll i=0;i<fs;++i){
							if(!fst_check[i]){
								flag=1;
								fst_check[i]=1;
								break;
							}
						}
					}else{
						for(ll i=0;i<ss;++i){
							if(!sed_check[i]){
								flag=1;
								sed_check[i]=1;
								break;
							}
						}
					}
					
					if(!flag) break;
				}
				// 2. 겹치는 게 없다면, !fst_check[i]인 것이 있는지?
			++cnt;
		}
		if(cnt%2==0){
			cout<<"yj";
		}else{
			cout<<"yt";
		}

	}
	return 0;
}