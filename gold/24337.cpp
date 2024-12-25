#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,a,b;
		cin>>n>>a>>b;
		if(a+b>n+1){
			cout<<-1;
			break;
		}
		vector<ll> v(n,0);
		if(a>=b){
			ll k=n-(a+b-1);
			for(ll i=0;i<k;++i){
				v[i]=1;
			}
			ll a_cnt=1;
			ll idx=0;
			for(ll i=k;a_cnt<=a;++i){
				v[i]=a_cnt++;
				idx=i;
			}
			ll b_cnt=b-1;
			for(ll i=idx+1;i<n;++i){
				v[i]=b_cnt--;
			}
		}else{
			ll b_cnt=1;
			ll idx=0;
			for(ll i=n-1;b_cnt<=b;--i){
				v[i]=b_cnt++;
				idx=i;
			}
			if(a==1){
				v[0]=v[idx];
				for(ll i=1;i<=idx;++i){
					v[i]=1;
				}
			}else{
				ll a_cnt=a-1;
				for(ll i=idx-1;a_cnt>=1;--i){
					v[i]=a_cnt--;
				}
				for(ll i=0;i<n;++i){
					if(!v[i]) v[i]=1;
				}
			}
			
		}
		for(ll i=0;i<n;++i){
			cout<<v[i]<<" ";
		}
	}
	return 0;
}