#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,h;
		cin>>n>>h;
		vector<ll> a,b;
		for(ll i=0;i<n;++i){
			ll c;
			cin>>c;
			if(i%2==0){
				a.push_back(c);
			}else{
				b.push_back(c);
			}
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ll as=a.size();
		ll bs=b.size();
		ll min_num=2023101800;
		vector<ll> cnt(n+1,0);
		for(ll i=1;i<=h;++i){
			// i에서 출발할 때 마주치는 장애물의 개수
			ll sum=0;
			ll L=0, R=a.size()-1;
			// a에서 i보다 크거나 같은 수의 개수 구하기
			// a에서 처음으로 i보다 크거나 같은 수 구하기
			ll min_idx=2023101800;
			while(L<=R){
				ll mid=(L+R)/2;
				if(a[mid]>=i){
					min_idx=min(min_idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			if(min_idx!=2023101800){
				sum+=(as-min_idx);
			}
			L=0, R=b.size()-1;
			min_idx=2023101800;
			ll cur_num=h-i+1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(b[mid]>=cur_num){
					min_idx=min(min_idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			if(min_idx!=2023101800){
				sum+=(bs-min_idx);
			}
			++cnt[sum];
			min_num=min(min_num,sum);
		}
		cout<<min_num<<" "<<cnt[min_num]<<"\n";
	}
	return 0;
}