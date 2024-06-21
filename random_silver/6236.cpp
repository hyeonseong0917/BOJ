#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		// M번만 통장에서 돈 뺌
		// K원을 인출, 해당 돈으로 하루를 보낼 수 있으면 그대로 사용
		// 안되면 통장에 돈 넣고 K원 빼기
		ll L=0;
		ll R=1000000000;
		ll K=1000000000;
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		while(L<=R){
			ll mid=(L+R)/2;
			bool flag=0;
			// mid원으로 하루를 보낼 수 있는지?
			// m보다 작거나 같은 횟수만큼 인출하면 가능
			ll cnt=0;
			ll cur_money=0;
			for(ll i=0;i<n;++i){
				if(cur_money<0) break;
				if(cur_money<v[i]){
					++cnt;
					cur_money=mid;
					cur_money-=v[i];
				}else{
					cur_money-=v[i];
				}
			}
			if(cnt<=m && cur_money>=0){
				flag=1;
			}
			if(flag){
				if(mid<K){
					K=mid;
				}
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		cout<<K;
	}
	return 0;
}