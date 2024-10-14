#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(m,0);
		vector<ll> check(n+1,0);
		for(ll i=0;i<m;++i){
			cin>>v[i];
		}
		for(ll i=0;i<m;++i){
			++check[v[i]];
		}
		vector<ll> page;
		for(ll i=1;i<=n;++i){
			if(!check[i]) page.push_back(i);
		}
		if(page.empty()){
			cout<<0;
		}else{
			ll cur_page=page[0];
			ll cur_cost=7;
			for(ll i=1;i<page.size();++i){
				if(page[i]==cur_page+1){
					cur_page=page[i];
					cur_cost+=2;
				}else{
					// +7을 하느냐 or cur_page에서 page[i]까지 연속인쇄?
					cur_cost+=min((ll)7,(page[i]-cur_page)*2);
					cur_page=page[i];
				}
			}
			cout<<cur_cost;	
		}
	}
	
	
	
	
	return 0;
}