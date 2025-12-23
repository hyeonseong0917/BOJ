#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll time_check[50000+1][10+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		for(ll i=0;i<=50000;++i){
			for(ll j=0;j<=10;++j){
				time_check[i][j]=0;
			}
		}
		ll n;
		cin>>n;
		map<string,ll> name_check;
		vector<pair<pair<string,string>,pair<ll,ll>>> v;
		for(ll i=0;i<n;++i){
			string a,b;
			ll c,d;
			cin>>a>>b;
			cin>>c>>d;
			if(!name_check[a]){
				++name_check[a];
				v.push_back({{a,b},{c,d}});
			}
		}
		// 가장 많은 사람들이 제출한 장소,시간대
		// 장소별 시간대를 나누자
		// 가장 많은 사람들이 제출한 장소를 구하고싶음
		map<string,ll> place_check;
		vector<string> place;
		for(ll i=0;i<v.size();++i){
			if(!place_check[v[i].first.second]){
				place.push_back(v[i].first.second);
				++place_check[v[i].first.second];
			}
		}
		sort(place.begin(),place.end());
		ll idx=0;
		map<string,ll> place_idx;
		for(ll i=0;i<place.size();++i){
			place_idx[place[i]]=idx++;
		}
		ll max_cnt=0;
		for(ll i=0;i<v.size();++i){
			string cur_place=v[i].first.second;
			ll cur_idx=place_idx[cur_place];
			ll cur_start=v[i].second.first;
			ll cur_fin=v[i].second.second;
			for(ll j=cur_start;j<cur_fin;++j){
				++time_check[j][cur_idx];
				max_cnt=max(max_cnt,time_check[j][cur_idx]);
			}
		}
		// cout<<max_cnt<<endl;
		bool flag=0;
		ll fin_idx=-1;
		ll start_time=-1;
		ll fin_time=-1;
		for(ll i=0;i<idx;++i){
			// i번째 타입에 대해 가장 먼저 나오는 max_cnt를 고른다
			for(ll j=1;j<=50000;++j){
				if(time_check[j][i]==max_cnt){
					flag=1;
					fin_idx=i;
					start_time=j;
					fin_time=j;
					while(1){
						++fin_time;
						if(time_check[fin_time][i]!=max_cnt){
							--fin_time;
							break;
						}
						if(fin_time==50000) break;
					}
					break;
				}
			}
			if(flag) break;
		}
		// cout<<start_time<<" "<<fin_time<<"\n";
		cout<<place[fin_idx]<<" "<<start_time<<" "<<fin_time+1<<"\n";
	}
	return 0;
}