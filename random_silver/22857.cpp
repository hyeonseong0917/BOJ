#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=1;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		ll odd_num=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]%2==1){
				++odd_num;
			}
		}
		k=min(k,odd_num);
		vector<ll> rdp(n,0), ldp(n,0);
		if(v[n-1]%2==0){
			rdp[n-1]=1;
		}
		for(ll i=n-2;i>=0;--i){
			if(v[i]%2==0){
				rdp[i]=rdp[i+1]+1;
			}
		}
		if(v[0]%2==0){
			ldp[0]=1;
		}
		for(ll i=1;i<n;++i){
			if(v[i]%2==0){
				ldp[i]=ldp[i-1]+1;
			}
		}
		ll L=1;
		while(L<n){
			if(v[L]%2==1){
				break;
			}
			++L;
		}
		ll R=-1;
		ll cnt=k;
		for(ll i=L;i<n;++i){
			if(v[i]%2==1){
				--cnt;
			}
			if(cnt==0){
				R=i;
				break;
			}
		}
		if(R==-1){
			ll ans=0;
			for(ll i=0;i<n;++i){
				if(v[i]%2==0){
					++ans;
				}
			}
			cout<<ans;
			return 0;
		}
		ll ans=0;
		while(L<=R && R+1<n){
			ll cur_num=R-L+1-k+ldp[L-1]+rdp[R+1];;
			while(R+1<n){
				++R;
				if(v[R]%2==1){
					break;
				}
			}
			while(L<n){
				++L;
				if(L==n) break;
				if(v[L]%2==1){
					break;
				}
			}
			ans=max(ans,cur_num);
		}
		cout<<ans;
	}
	return 0;
}