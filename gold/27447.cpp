#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		vector<ll> p(n,0);
		map<ll,ll> check;
		bool flag=0;
		ll cur_time=0, max_time=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]<=1){
				flag=1;
			}
			++check[v[i]];
			p[i]=v[i]-m;
			// v[i]는 p[i] 전에는 만들면 안됨
		}
		max_time=v[n-1];
		if(flag){
			cout<<"fail";
			break;
		}
		ll bef=0, aft=0;
		ll idx=0;
		for(ll i=0;i<=max_time && idx<n;++i){
			if(check[i]){
				// i번째 시간에 손님이 찾아옴
				if(aft){
					// 만들어진 커피가 있음 -> 서빙
					--aft;
				}else{
					flag=1;
					break;
				}
			}else{
				if(i>=p[idx]){
					if(bef){
						--bef;
						++aft;
						++idx;
					}else{
						++bef;
					}
				}else{
					++bef;
				}
			}
		}
		if(flag){
			cout<<"fail";
		}else{
			cout<<"success";
		}

	}
	return 0;
}