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
		// n개의 통에 초콜릿을 담아서 초콜릿의 개수가 오름차순이 되도록함
		// 1번째 통<=2번째 통, ... 
		// K<i인 i를 골라서 i-K번째 통에 있는 초콜릿의 개수와 같아질 때까지
		// i번째 통에 있는 초콜릿을 먹음
		// 최대한 많이 먹고 싶은데 몇 개 먹을 수 있는지??
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// 4 2
		--k;		
		// 0 1 2 3
		// 1 2 2 3
		// 최대 개수와, 해당 개수의 초콜릿 먹기 위해 필요한 최소 날짜
		// k보다 큰 인덱스 중, 어떤걸 먹어야 할까?? 가장 많은거??
		// i-k번째 인덱스의 초콜릿과 i번째 초콜릿의 개수를 비교함
		// 1 2 2 3 5
		// 1 2 2 2 5
		// 1 2 2 2 3
		ll ans=0, d=0;
		for(ll i=1;i<n;++i){
			if(v[i]>v[0]){
				ans+=v[i]-v[0];
				++d;
			}
		}
		cout<<ans<<" "<<d;

	} 
	return 0;
}