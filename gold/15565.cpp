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
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		ll one_cnt=0;
		// 01 && 10
		vector<ll> p;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(!(v[i]&2)){
				++one_cnt;
				p.push_back(i);
			}
		}
		if(one_cnt<k){
			cout<<-1;
			break;
		}
		// 라이언 1, 어피치 2
		// 1이 k개 이상 있는 가장 작은 집합의 크기
		// 0 1 2 3 4 5 6 7 8 9
		// 1 2 2 2 1 2 1 2 2 1
		// 0 4 6 9
		ll ans=2023101800;
		ll ps=p.size();
		for(ll i=0;i+k<=ps;++i){
			ans=min(ans,p[i+k-1]-p[i]+1);
		}
		cout<<ans;

	}
	return 0;
}