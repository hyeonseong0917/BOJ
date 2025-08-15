#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	// cin>>o;
	while(o--){
		ll n,A,B;
		cin>>n>>A>>B;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll ans=0;
		for(ll i=0;i<A;++i){
			// i만큼 자는경우
			ll C=A;
			for(ll j=-1;j<n;++j){
				// j번째 끝내고 자는경우
				ll cur_time=0;
				ll cnt=0;
				C=A;
				if(j==-1){
					// 처음에 잠
					cur_time+=i*B;
					C-=i;
					for(ll k=0;k<n;++k){
						if(cur_time+C<=v[k]){
							cur_time+=C;
							++cnt;
						}
					}
				}else{
					// j번째 끝내고 잠을 잠.
					// [0,j]까지는 기존의 C로 감
					// 잠을 잠
					// [j,n-1]까지는 조정된 C로감
					for(ll k=0;k<=j;++k){
						if(cur_time+C<=v[k]){
							cur_time+=C;
							++cnt;
						}
					}
					C-=i;
					cur_time+=i*B;
					for(ll k=j+1;k<n;++k){
						if(cur_time+C<=v[k]){
							cur_time+=C;
							++cnt;
						}
					}
				}
				ans=max(ans,cnt);
			}
		}
		cout<<ans;
	}
	return 0;
}