#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		// 길이는 n, 가치는 x여야함
		// 6 64
		// 길이가 n이면서, 사전순으로 가장 앞서는
		// 11111
		ll n,x;
		cin>>n>>x;
		if(x<n || 26*n<x){
			cout<<"!";
		}else{
			ll idx=0;
			ll sum=0;
			string ans="";
			for(ll i=0;i<26;++i){
				if(idx>=n){
					break;
				}
				char c='A'+i;
				ll cnt=1; // cnt개를 박을 수 있음
				// [idx,idx+cnt-1]에 박아도 문제가 없는지??
				// [idx+cnt,n-1]
				while(idx+cnt<=n){
					// idx
					if(sum+cnt*(i+1)+26*(n-idx-cnt)>=x){
						++cnt;
					}else{
						--cnt;
						break;
					}
				}
				if(cnt<=0) continue;
				if(idx+cnt>n){
					--cnt;
				}
				// cnt
				idx+=cnt;
				sum+=cnt*(i+1);
				while(cnt--){
					ans+=c;
				}
				
			}
			cout<<ans;

		}
	} 
	return 0;
}