#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> check(200000+1,0);
		vector<ll> x_pos;
		vector<ll> x[100000+1];
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			x[a].push_back(b);
			if(!check[a+100000]){
				check[a+100000]=1;
				x_pos.push_back(a);
			}
		}
		ll m;
		cin>>m;
		vector<ll> q(m,0);
		for(ll i=0;i<m;++i){
			cin>>q[i];
		}
		ll last_y=0;
		ll cnt=1;
		pair<ll,ll> pos_check[n+1];
		sort(x_pos.begin(),x_pos.end());
		for(ll i=0;i<x_pos.size();++i){
			ll cx=x_pos[i];
			sort(x[cx].begin(),x[cx].end());
			ll cs=x[cx].size();
			ll fst_y=x[cx][0];
			ll fin_y=x[cx][cs-1];
			if(fst_y==fin_y){
				pos_check[cnt++]={cx,fst_y};
				last_y=fin_y;
			}else{
				if(fst_y==last_y){
					for(ll j=0;j<cs;++j){
						ll next_y=x[cx][j];
						pos_check[cnt++]={cx,next_y};
						last_y=next_y;
					}
				}else{
					for(ll j=cs-1;j>=0;--j){
						ll next_y=x[cx][j];
						pos_check[cnt++]={cx,next_y};
						last_y=next_y;
					}
				}
			}
		}
		for(ll i=0;i<m;++i){
			ll cur_num=q[i];
			pair<ll,ll> cur_pair=pos_check[cur_num];
			ll cx=cur_pair.first;
			ll cy=cur_pair.second;
			cout<<cx<<" "<<cy<<"\n";
		}
		
	}
	return 0;
}