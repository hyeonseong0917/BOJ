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
		ll a,b,n;
		cin>>a>>b>>n;
		vector<pair<ll,ll>> blue, red;
		for(ll i=0;i<n;++i){
			ll cur_time;
			char c;
			ll cur_cnt;
			cin>>cur_time>>c>>cur_cnt;
			if(c=='B'){
				blue.push_back({cur_time,cur_cnt});
			}else{
				red.push_back({cur_time,cur_cnt});
			}
		}
		vector<ll> blue_start, red_start;
		for(ll i=0;i<blue.size();++i){
			ll cur_time=blue[i].first;
			ll cur_cnt=blue[i].second;
			if(i==0){
				blue_start.push_back(cur_time);
			}else{
				ll last_blue_start=blue_start[blue_start.size()-1];
				if(last_blue_start<cur_time){
					blue_start[blue_start.size()-1]=cur_time;
				}
				cur_time=max(cur_time,last_blue_start);
			}
			
			for(ll j=1;j<=cur_cnt;++j){
				blue_start.push_back(cur_time+j*a);
			}
		}
		for(ll i=0;i<red.size();++i){
			ll cur_time=red[i].first;
			ll cur_cnt=red[i].second;
			if(i==0){
				red_start.push_back(cur_time);
			}else{
				ll last_red_start=red_start[red_start.size()-1];
				if(last_red_start<cur_time){
					red_start[red_start.size()-1]=cur_time;
				}
				cur_time=max(cur_time,last_red_start);
			}
			for(ll j=1;j<=cur_cnt;++j){
				red_start.push_back(cur_time+j*b);
			}
		}
		ll cnt=1;
		vector<ll> red_num, blue_num;
		ll red_idx=0, blue_idx=0;
		ll rs=red_start.size();
		ll bs=blue_start.size();
		while(red_idx<rs-1 || blue_idx<bs-1){
			ll cur_red_start=2023101800;
			ll cur_blue_start=2023101800;
			if(red_idx<rs-1){
				cur_red_start=red_start[red_idx];
			}
			if(blue_idx<bs-1){
				cur_blue_start=blue_start[blue_idx];
			}
			if(cur_blue_start<=cur_red_start){
				blue_num.push_back(cnt);
				++cnt;
				++blue_idx;
			}else{
				red_num.push_back(cnt);
				++cnt;
				++red_idx;
			}
		}
		ll last_rs=red_num.size();
		ll last_bs=blue_num.size();
		cout<<last_bs<<"\n";
		for(ll i=0;i<last_bs;++i){
			cout<<blue_num[i]<<" ";
		}cout<<"\n";
		cout<<last_rs<<"\n";
		for(ll i=0;i<last_rs;++i){
			cout<<red_num[i]<<" ";
		}
	}
	return 0;
}