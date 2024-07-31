#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

int main() {
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		priority_queue<ll> pq;
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			pq.push(a);
		}
		if(n==1){
			ll cur_num=pq.top();
			if(cur_num>1440){
				cout<<-1;
			}else{
				cout<<cur_num;
			}
			break;
		}
		ll ans=0;
		while(1){
			ll fst_num=pq.top();
			pq.pop();
			ll sed_num=pq.top();
			pq.pop();
			if(fst_num==0 || sed_num==0){
				ans+=max(fst_num,sed_num);
				break;
			}
			pq.push(fst_num-1);
			pq.push(sed_num-1);
			++ans;
		}
		if(ans>1440){
			cout<<-1;
		}else{
			cout<<ans;
		}
	}
	return 0;
}