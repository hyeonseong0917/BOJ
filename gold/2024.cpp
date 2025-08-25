#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll m;
		cin>>m;
		vector<pair<ll,ll>> v;
		while(1){
			ll a,b;
			cin>>a>>b;
			if(a==0 && b==0){
				break;
			}
			v.push_back({a,b});
		}
		// [0,m]을 덮는 방법
		// [-1,0]
		// [0,1]
		// 최소 개수의 선들로 덮는법
		// [0,20]
		
		// [0,9]
		// [0,3]
		// [1,4]
		// [4,5]
		// [4,6]
		// [6,9]
		// [9,11]

		// [1,9]
		// [2,14]

		// 끝에가 더 큰 것을 선택해야하는게 이득이긴함
		// 1. 시작 순 정렬
		// 2. 0을 커버할 수 있으면서 최대의 끝점을 찾는다.
		// 3. 9를 커버할 수 있으면서 최대. 9보다 크다면 fail
		// 4. 시작점이 9보다 커졌다면 지금까지 후보(두번째 값)로 두었던 것들 중에 가장 큰 것을
		// 현재의 시작점으로 두고 ++cnt. 만약 후보가 현재의 시작점보다 작다면 fail

		// 1. start_pos를 커버하 수 있으면서? 최대의 끝점을 찾는다.
		// 2. start_pos를 커버할 수 없다면? -> start_pos를 최대의 끝점으로 두고, 최대의 끝점을 v[i].second로 두고 ++cnt
		sort(v.begin(),v.end());
		ll n=v.size();
		ll cnt=1;
		ll start_pos=0;
		ll fin_pos=0;
		bool flag=0;
		for(ll i=0;i<n;++i){
			// fin_pos를 커버할 수 있으면서 최대의 끝점은?
			if(fin_pos>=m){
				break;
			}
			if(v[i].second<=0) continue;
			if(v[i].first<=start_pos){
				fin_pos=max(fin_pos,v[i].second);
			}else{
				// v[i].first>start_pos
				if(v[i].first>fin_pos){
					flag=1;
					break;
				}
				start_pos=fin_pos;
				fin_pos=v[i].second;
				++cnt;
			}
		}
		if(fin_pos<m){
			flag=1;
		}
		if(flag){
			cout<<0;
			break;
		}
		cout<<cnt;

	}
	return 0;
}