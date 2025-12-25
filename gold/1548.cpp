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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// n은 최대 50
		// a에 들어있는 수는 10^9보다 작거나 같음
		// 가장 긴 삼각 부분 수열의 길이
		// x,y,z가 있을 때
		// 1. x+y>z
		// 2. x+z>y
		// 3. y+z>x
		sort(v.begin(),v.end());
		if(n<3){
			cout<<n;
		}else{
			ll ans=2;
			for(ll i=0;i<n-1;++i){
				for(ll j=i+1;j<n;++j){
					// [i,j]를 정답구간이라고 할 때
					bool flag=0;
					if(v[i]+v[i+1]<=v[j]){
						flag=1;
					}
					if(!flag){
						ans=max(ans,j-i+1);
					}
				}
			}
			cout<<ans;
		}
	}
	return 0;
}