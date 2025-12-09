#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> a(n,0);
		vector<ll> b(m,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		vector<ll> check(100000+1,0);
		for(ll i=0;i<m;++i){
			cin>>b[i];
			++check[b[i]];
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ll a_cnt=0, d_cnt=0, b_cnt=0;
		for(ll i=0;i<n;++i){
			ll cur_num=a[i];
			ll L=0, R=m-1;
			// cur_num이랑 같은거 b에 몇개인지?
			d_cnt+=check[cur_num];
			// cur_num보다 큰 최소의 인덱스를 구한다
			ll min_idx=2023101800;
			while(L<=R){
				ll mid=(L+R)/2;
				if(b[mid]<=cur_num){
					L=mid+1;
				}else{
					min_idx=min(min_idx,mid);
					R=mid-1;
				}
			}
			ll cur_same_cnt=check[cur_num];
			if(min_idx==2023101800){
				// cur_num보다 큰거 없음
				// cur_num과 같은거 d_cnt개 있음
				// cur_num보다 작은거 m-d_cnt개 있음
				a_cnt+=m-cur_same_cnt;
			}else{
				// cur_num보다 큰거 [min_idx,m-1]
				b_cnt+=(m-min_idx);
				a_cnt+=(min_idx-cur_same_cnt);
			}
		}
		cout<<a_cnt<<" "<<b_cnt<<" "<<d_cnt<<"\n";
	}
	return 0;
}