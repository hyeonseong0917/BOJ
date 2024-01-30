#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;

	while(t--){
		vector<ll> v;
		ll N;
		cin>>N;
		for(ll i=0;i<N;++i){
			ll a=0;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		
		deque<ll> dq;
		int idx=N-1;
		dq.push_back(v[idx--]);
		bool flag=1;
		while(idx>=0){
			if(flag){
				dq.push_front(v[idx--]);
				flag=0;
			}else{
				dq.push_back(v[idx--]);
				flag=1;
			}
		}
		ll max_num=abs(dq.front()-dq.back());
		ll cur_num=dq.front();
		dq.pop_front();
		while(!dq.empty()){
			max_num=max(max_num, abs(cur_num-dq.front()));
			cur_num=dq.front();
			dq.pop_front();
		}
		cout<<max_num<<"\n";
	}
}