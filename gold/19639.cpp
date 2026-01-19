#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	// cin>>o;
	while(o--){
		ll x,y,m;
		cin>>x>>y>>m;
		vector<pair<ll,ll>> monster;
		vector<pair<ll,ll>> item;
		for(ll i=0;i<x;++i){
			ll a;
			cin>>a;
			monster.push_back({a,i});
		}
		for(ll i=0;i<y;++i){
			ll a;
			cin>>a;
			item.push_back({a,i});
		}
		sort(monster.begin(),monster.end());
		sort(item.begin(),item.end());
		vector<ll> ans;
		ll hp=m;
		ll idx=0;
		bool flag=0;
		for(ll i=0;i<x;++i){
			// i번째 몬스터 잡을 수 있는지?
			if(hp>monster[i].first){
				hp-=monster[i].first;
				ans.push_back((monster[i].second+1)*-1);
			}else{
				// hp<m/2인 상태임
				ll diff=monster[i].first-hp;
				// diff만큼을 채워야함
				// 넘치는 경우 없음 무조건
				// 2 3 7 -> 5필요
				while(idx<y){
					hp+=item[idx].first;
					ans.push_back(item[idx].second+1);
					++idx;
					if(hp>monster[i].first){
						break;
					}
				}
				if(hp<=monster[i].first){
					flag=1;
					break;
				}
				hp-=monster[i].first;
				ans.push_back((monster[i].second+1)*-1);
			}
		}
		if(flag){
			cout<<0;
		}else{
			for(ll i=idx;i<y;++i){
				ans.push_back(item[i].second+1);
			}
			for(ll i=0;i<x+y;++i){
				cout<<ans[i]<<"\n";
			}
		}
	}
	return 0;
}