#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second>b.second;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		vector<ll> tmp;
		map<ll,ll> tmp_check;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
			if(!tmp_check[a]){
				++tmp_check[a];
				tmp.push_back(a);
			}
			if(!tmp_check[b]){
				++tmp_check[b];
				tmp.push_back(b);
			}
		}
		sort(tmp.begin(),tmp.end());
		map<ll,ll> num_check;
		ll cnt=1;
		for(ll i=0;i<tmp.size();++i){
			num_check[tmp[i]]=cnt++;
		}
		// p에는 상대좌표가 담겼음
		vector<pair<ll,ll>> p;
		vector<ll> fst_vec, sed_vec;
		for(ll i=0;i<v.size();++i){
			p.push_back({num_check[v[i].first],num_check[v[i].second]});
			fst_vec.push_back(p[i].first);
			sed_vec.push_back(p[i].second);
		}
		// 1. 끝점 기준으로 정렬
		sort(p.begin(),p.end(),comp);
		sort(fst_vec.begin(),fst_vec.end());
		sort(sed_vec.begin(),sed_vec.end());
		ll min_start=2023101800;
		ll ans=0;
		for(ll i=0;i<p.size();++i){
			ll fst_num=p[i].first;
			ll sed_num=p[i].second;
			// [fst_num,sed_num] 구간을 제외한 구간이 몇 개 있는지?
			// 1. fst_num보다 작은 min_start가 있으면 pass
			if(min_start<fst_num) continue;
			min_start=fst_num;
			// min_start>=fst_num
			// n-1-(fst_num에서 끝나는거 개수 + sed_num에서 시작하는거 개수)
			// 1. fst_num보다 작은 좌표에서 시작하는거 개수 구하기
			// fst_vec에서 fst_num보다 작은, 제일 큰 인덱스를 구하기
			ll max_idx=-1;
			ll L=0, R=n-1;
			ll fst_cnt=0, sed_cnt=0;
			while(L<=R){
				ll mid=(L+R)/2;
				if(fst_vec[mid]<fst_num){
					max_idx=max(max_idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			if(max_idx!=-1){
				fst_cnt=max_idx+1;
			}
			// 2. sed_num보다 큰 좌표에서 끝나는거 개수 구하기
			// sed_num보다 큰 최소값, 제일 작은 인덱스 구하기
			ll min_idx=n;
			L=0, R=n-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(sed_vec[mid]>sed_num){
					min_idx=min(min_idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			if(min_idx!=n){
				sed_cnt=n-min_idx;
			}
			// cout<<"i: "<<i<<" max_idx: "<<max_idx<<" min_idx: "<<min_idx<<" fst_cnt: "<<fst_cnt<<" sed_cnt: "<<sed_cnt<<endl;
			ans=max(ans,n-1-(fst_cnt+sed_cnt));
		}
		cout<<ans;
	}
	return 0;
}