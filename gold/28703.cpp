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
		ll n;
		cin>>n;
		priority_queue<ll> pq;
		ll max_num=-1;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			max_num=max(max_num,a);
			pq.push(a*-1);
		}
		ll fst_max_num=max_num;
		ll min_diff=2023101800;
		while(!pq.empty()){
			ll cur_num=pq.top()*-1;
			min_diff=min(min_diff,max_num-cur_num);
			if(cur_num==fst_max_num) break;
			pq.pop();
			pq.push(cur_num*2*-1);
			if(max_num<cur_num*2){
				max_num=cur_num*2;
			}
		}
		if(min_diff==2023101800){
			cout<<0;
		}else{
			cout<<min_diff;
		}

		
	}
	return 0;
}