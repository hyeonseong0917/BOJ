#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		// 재료마다 유통기한이 다름
		// 밀키트의 유통기한은 모든 재료의 유통기한 중 가장 이른거
		// n개의 재료들 존재
		// i번째 재료의 유통기한은 구매 후 L[i]일까지
		// 부패속도는 S[i]
		// 구매 후 x일에 i번째 재료에 있는 세균=
		// s[i]*max(1,x-L[i])
		// 모든 재료의 세균 합이 G마리 이하인 경우 먹기 가능
		// 재료를 최대 K개까지 뺄 수 있음
		ll n,g,k;
		cin>>n>>g>>k;
		vector<pair<ll,ll>> one_vec, zero_vec;
		for(ll i=0;i<n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			if(c==0){
				zero_vec.push_back({a,b});
			}else{
				one_vec.push_back({a,b});
			}
		}
		ll L=0, R=2000000000;
		ll ans=0;
		while(L<=R){
			ll mid=(L+R)/2; // mid일동안
			ll cur_num=0;
			for(ll i=0;i<zero_vec.size();++i){
				ll fst_num=zero_vec[i].first;
				ll sed_num=zero_vec[i].second;
				cur_num+=fst_num*max(1ll,mid-sed_num);
			}
			priority_queue<ll> pq;
			for(ll i=0;i<one_vec.size();++i){
				ll fst_num=one_vec[i].first;
				ll sed_num=one_vec[i].second;
				pq.push((fst_num*max(1ll,mid-sed_num)));
			}
			ll cnt=0;
			while(!pq.empty() && cnt<k){
				pq.pop();
				++cnt;
			}
			while(!pq.empty()){
				ll c=pq.top();
				pq.pop();
				cur_num+=c;
			}
			if(cur_num<=g){
				ans=max(ans,mid);
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		cout<<ans;

	}	
	return 0;
}