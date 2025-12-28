#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

bool fst_comp(pair<ll,pair<ll,ll>> a, pair<ll,pair<ll,ll>> b){
	return a.second.first-a.second.second<b.second.first-b.second.second;
}
bool sed_comp(pair<ll,pair<ll,ll>> a, pair<ll,pair<ll,ll>> b){
	return a.second.first+a.second.second<b.second.first+b.second.second;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,pair<ll,ll>>> v,p;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({i,{a,b}});
			p.push_back({i,{a,b}});
		}
		// a-b 순으로 정렬
		sort(v.begin(),v.end(),fst_comp);

		// a+b 순으로 정렬	
		sort(p.begin(),p.end(),sed_comp);

		// 1. a+b순으로 정렬된 배열에 대해 a-b가 몇 번째로 큰지?
		// 2. a-b순으로 정렬된 배열에 대해 a+b가 몇 번째로 큰지?
		// 작을수록 1번째 2번째임

		map<ll,pair<ll,ll>> m;
		for(ll i=0;i<n;++i){
			ll cur_idx=v[i].first;
			ll fst_num=v[i].second.first-v[i].second.second;
			// fst_num보다 작은, 제일 작은 인덱스 찾기?
			ll L=0, R=n-1;
			ll min_idx=n;
			// if(i==2){
			// 	cout<<fst_num<<endl;
			// }
			while(L<=R){
				ll mid=(L+R)/2;
				if(p[mid].second.first+p[mid].second.second>=fst_num){
					min_idx=min(min_idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			// if(i==2){
			// 	cout<<min_idx<<endl;
			// }
			if(min_idx==n){
				min_idx=0;
			}
			ll sed_num=v[i].second.first+v[i].second.second;
			// 제일 큰 인덱스 찾기? -에서 sed_num보다 작거나 같은
			// cout<<i<<" "<<sed_num<<endl;
			L=0, R=n-1;
			ll max_idx=-1;
			while(L<=R){
				ll mid=(L+R)/2;
				// cout<<mid<<endl;
				if(v[mid].second.first-v[mid].second.second<=sed_num){
					max_idx=max(max_idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			// cout<<i<<" "<<max_idx<<endl;
			if(max_idx==-1){
				max_idx=n-1;
			}
			// cout<<i<<" "<<cur_idx<<" "<<min_idx<<" "<<max_idx<<endl;
			m[cur_idx]={min_idx+1,max_idx+1};
		}
		for(ll i=0;i<n;++i){
			cout<<m[i].first<<" "<<m[i].second<<"\n";
		}

	}
	return 0;
}