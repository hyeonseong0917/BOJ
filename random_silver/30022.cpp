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
		// n종류의 물건이 한 개씩 필요함
		// 동하가 A개를 준비, 지원이가 B개를 준비
		// 상점 1,2에서 N종류의 물건
		// 동하는 상점 1, 지원이는 상점 2에서 구입할 예정
		ll n,a,b;
		cin>>n>>a>>b;
		vector<ll> p(n,0), q(n,0);
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			cin>>p[i];
			cin>>q[i];
			v.push_back({p[i]-q[i],i});
		}
		// p에서 a개, q에서 b개. 서로 다른 인덱스
		//    0  1 2 3  4
		// p  4  7 5 3  10
		// q  6  2 5 6  9
		//p-q -2 5 0 -3 1
		sort(v.begin(),v.end());
		ll ans=0;
		for(ll i=0;i<a;++i){
			ll idx=v[i].second;
			ans+=p[idx];
		}
		for(ll j=a;j<n;++j){
			ll idx=v[j].second;
			ans+=q[idx];
		}
		cout<<ans;
	}
}