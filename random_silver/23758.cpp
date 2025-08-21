#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1424
		ll n;
		scanf("%lld",&n);
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			scanf("%lld",&v[i]);
		}
		sort(v.begin(),v.end());
		priority_queue<ll> pq;
		for(ll i=0;i<(n+1)/2;++i){
			pq.push(v[i]);
		}
		ll ans=0;
		ll max_num=pq.top();
		vector<ll> dp((n+1)/2,0);
		// 4->2->1->0
		// 5->2->1->0

		// 14->7->3->1->0
		for(ll i=0;i<(n+1)/2;++i){
			ll cur_num=v[i];
			// cur_num보다 큰 최소의 2의 제곱 수는 몇 제곱인지?
			ll L=0, R=30ll;
			ll cnt=R;
			while(L<=R){
				ll mid=(L+R)/2;
				ll c=1;
				for(ll i=0;i<mid;++i){
					c*=2;
				}
				if(c>cur_num){
					R=mid-1;
					cnt=min(cnt,mid);
				}else{
					L=mid+1;
				}
			}

			dp[i]=cnt;
		}
		for(ll i=0;i<(n+1)/2;++i){
			ans+=dp[i]-1;
		}
		++ans;
		cout<<ans;
		// 중앙값 /2
		// 언제 0이 등장하게 되는지?
		// [3,5,7,9]
		// [2,3,7,9]
		// [1,2,7,9]
		// [1,1,7,9]
		// [0,1,7,9]

		// [3,5,7,9,11]
		// [3 3 5]
		// [2 3 3]
		// [1,2,3]
		// [1,1,2]
		// [1,1,1]
		// []
	}
	return 0;
}