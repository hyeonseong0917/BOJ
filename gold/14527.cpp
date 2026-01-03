#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll x,y;
			cin>>x>>y;
			// 시간, 소의 수로 묶음
			v.push_back({y,x});
		}
		// 시간 순으로 정렬
		sort(v.begin(),v.end());
		ll L=0, R=n-1;
		ll ans=0;
		// 작은 수는 큰 수랑 묶여야함 무조건
		while(L<=R){
			if(L==R){
				ans=max(ans,v[L].first+v[R].first);
				break;
			}
			ll fst_time=v[L].first;
			ll sed_time=v[R].first;

			ll fst_cnt=v[L].second;
			ll sed_cnt=v[R].second;
			ans=max(ans,v[L].first+v[R].first);
			if(fst_cnt<sed_cnt){
				v[R].second-=fst_cnt;
				v[L].second=0;
				++L;
			}else if(fst_cnt>sed_cnt){
				v[L].second-=sed_cnt;
				v[R].second=0;
				--R;
			}else{
				v[L].second=0;
				v[R].second=0;
				++L;
				--R;
			}
		}
		cout<<ans;
	}
	return 0;
}