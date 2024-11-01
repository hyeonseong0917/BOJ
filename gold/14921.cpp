#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
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
		vector<ll> v(n,0);
		bool is_all_minus=1, is_all_plus=1;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]>0){
				is_all_minus=0;
			}
			if(v[i]<0){
				is_all_plus=0;
			}
		}
		if(is_all_minus){
			cout<<v[n-2]+v[n-1];
			break;
		}
		if(is_all_plus){
			cout<<v[0]+v[1];
			break;
		}
		ll L=0, R=n-1;
		ll ans=2023101800;
		ll last_L, last_R;
		while(L<R && R<n){
			ll cur_diff=abs(v[R]+v[L]);
			if(cur_diff<ans){
				ans=cur_diff;
				last_L=L;
				last_R=R;
			}
			if(v[R]+v[L]>0){
				--R;
			}else if(v[R]+v[L]<0){
				++L;
			}else{
				last_L=L;
				last_R=R;
				break;
			}
			// if(L==R){
			// 	++R;
			// }else{
			// 	if(v[R]+v[L]>0){
			// 		--R;
			// 	}else if(v[R]+v[L]<0){
			// 		++L;
			// 	}else{
			// 		last_L=L;
			// 		last_R=R;
			// 		break;
			// 	}
			// }
		}
		cout<<v[last_L]+v[last_R];
		
		
	}
	return 0;
}