#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

vector<ll> A;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll N;
	cin>>N;
	for(ll i=0;i<N;++i){
		ll a=0;
		cin>>a;
		A.push_back(a);
	}
	ll cnt=0;
	while(1){
		// for(ll i=0;i<N;++i){
		// 	cout<<A[i]<<" ";
		// }cout<<endl;
		bool flag=0;
		for(ll i=0;i<N-1;++i){
			if(A[i]!=A[i+1]){
				flag=1;
				break;
			}
		}
		if(!flag) break;
		ll min_idx=-1;
		ll min_num=1222322421;
		for(ll i=0;i<N;++i){
			if(A[i]<min_num){
				min_num=A[i];
				min_idx=i;
			}
		}
		ll next_num=1222322421;
		if(min_idx==0){
			ll L=min_idx;
			while(1){
				++L;
				if(L==N) break;
				if(A[L]!=A[min_idx]){
					break;
				}
			}
			cnt+=(A[L]-A[min_idx]);
			for(ll i=min_idx;i<L;++i){
				A[i]=A[L];
			}
		}else if(min_idx==N-1){
			ll R=min_idx;
			while(1){
				--R;
				if(R==-1) break;
				if(A[R]!=A[min_idx]){
					break;
				}
			}
			cnt+=(A[R]-A[min_idx]);
			for(ll i=R+1;i<=min_idx;++i){
				A[i]=A[R];
			}
		}else{
			ll L=min_idx;
			while(1){
				++L;
				if(L==N) break;
				if(A[L]!=A[min_idx]){
					break;
				}
			}
			
			ll R=min_idx-1;

			if(L!=N && A[L]<A[R]){
				cnt+=(A[L]-A[min_idx]);
				for(ll i=min_idx;i<L;++i){
					A[i]=A[L];
				}	
			}else{
				cnt+=(A[R]-A[min_idx]);
				for(ll i=min_idx;i<L;++i){
					A[i]=A[R];
				}	
			}
		}
	}
	cout<<cnt;
	
	return 0;
}