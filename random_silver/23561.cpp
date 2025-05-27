#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		// 1530
		// 3n명의 학생 참가
		// 3명씩 n개의 크루를 만들어서 겨룸
		// 3명중 두번째로 연령이 높은 사람을 에너지로 정의
		// 가장 에너지 높은 크루와 가장 에너지 낮은 크루의 차이를 최소화
		ll n;
		cin>>n;
		vector<ll> v(3*n,0);
		for(ll i=0;i<3*n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll ans=v[2*n-1]-v[n];
		cout<<ans;
	} 
	return 0;
}