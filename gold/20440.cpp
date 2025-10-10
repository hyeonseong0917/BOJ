#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		vector<ll> tmp;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
			tmp.push_back(a);
			tmp.push_back(b);
		}
		sort(tmp.begin(),tmp.end());
		ll cnt=1;
		priority_queue<ll> pq;
		vector<ll> check;
		// check.push_back(0);
		// check[0]=x, 0번째 상대좌표 값은 x임
		ll pre_num=-1;
		for(ll i=0;i<tmp.size();++i){
			if(pre_num==-1){
				check.push_back(tmp[i]);
				pre_num=tmp[i];
			}else{
				if(pre_num==tmp[i]) continue;
				check.push_back(tmp[i]);
				pre_num=tmp[i];
			}
		}
		// cout<<endl;
		// for(ll i=0;i<check.size();++i){
		// 	cout<<i<<" "<<check[i]<<endl;
		// }
		// check[0]=x: 0번째 상대좌표 값은 x
		cnt=check.size();
		vector<ll> diff(cnt,0), psum(cnt,0);
		for(ll i=0;i<n;++i){
			ll start_pos=v[i].first;
			ll fin_pos=v[i].second;
			// 1. start_pos의 idx는?
			ll l=0, r=cnt-1;
			ll start_idx=-1;
			while(l<=r){
				ll mid=(l+r)/2;
				if(check[mid]>start_pos){
					r=mid-1;
				}else if(check[mid]<start_pos){
					l=mid+1;
				}else{
					start_idx=mid;
					break;
				}
			}
			// 2. fin_pos의 idx는?
			l=0, r=cnt-1;
			ll fin_idx=-1;
			while(l<=r){
				ll mid=(l+r)/2;
				if(check[mid]>fin_pos){
					r=mid-1;
				}else if(check[mid]<fin_pos){
					l=mid+1;
				}else{
					fin_idx=mid;
					break;
				}
			}
			++diff[start_idx];
			--diff[fin_idx];
			// cout<<i<<" "<<start_idx<<" "<<fin_idx<<endl;
		}
		psum[0]=diff[0];
		ll max_num=psum[0];
		// cout<<max_num<<endl;
		for(ll i=1;i<cnt;++i){
			psum[i]=psum[i-1]+diff[i];
			max_num=max(max_num,psum[i]);
		}
		ll L=-1, R=-1;
		for(ll i=0;i<cnt;++i){
			if(max_num==psum[i]){
				if(L==-1){
					L=i;
					R=L+1;
				}else{
					R=i+1;
				}
			}else{
				if(L!=-1 && R!=-1){
					break;
				}
			}
		}
		cout<<max_num<<"\n";
		cout<<check[L]<<" "<<check[R];
	}
	return 0;
}
