#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		deque<ll> dq;
		ll n,k;
		cin>>n>>k;
		for(ll i=1;i<=n;++i){
			dq.push_front(i);
		}
		ll cnt=0;
		vector<ll> ans;
		while(!dq.empty()){
			ll cur_num=dq.back();
			dq.pop_back();
			++cnt;
			if(cnt%k==0){
				ans.push_back(cur_num);
			}else{
				dq.push_front(cur_num);
			}
		}
		cout<<"<";
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i];
			if(i!=ans.size()-1){
				cout<<", ";
			}
		}
		cout<<">";
	}
	return 0;
}