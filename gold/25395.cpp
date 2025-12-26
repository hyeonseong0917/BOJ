#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,s;
		cin>>n>>s;
		vector<ll> x(n,0);
		vector<ll> h(n,0);
		for(ll i=0;i<n;++i){
			cin>>x[i];
		}
		for(ll i=0;i<n;++i){
			cin>>h[i];
		}
		ll L=s-1, R=s-1;
		ll min_num=max(0ll,x[L]-h[L]);
		ll max_num=min(x[L]+h[L],x[n-1]);
		while(L<=R && L>=0 && R<n){
			// L-1로 갈 수 있는지?
			bool fst_flag=0;
			if(L){
				if(x[L-1]>=min_num){
					min_num=min(min_num,max(0ll,x[L-1]-h[L-1]));
					max_num=max(max_num,min(x[n-1],x[L-1]+h[L-1]));
					--L;
					fst_flag=1;
				}
			}
			// R+1로 갈 수 있는지?
			bool sed_flag=0;
			if(R+1<n){
				if(x[R+1]<=max_num){
					max_num=max(max_num,min(x[n-1],x[R+1]+h[R+1]));
					min_num=min(min_num,max(0ll,x[R+1]-h[R+1]));
					++R;
					sed_flag=1;
				}
			}
			if(!fst_flag && !sed_flag) break;
		}
		for(ll i=L;i<=R;++i){
			cout<<i+1<<" ";
		}
	}
	return 0;
}