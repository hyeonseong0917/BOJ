#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n,x;
		cin>>n>>x;
		// v: n버거의 사이즈
		vector<ll> v(50+1,0);
		// p: n버거에 p가 몇 개 있는지
		vector<ll> p(50+1,0);
		v[0]=1;
		p[0]=1;
		v[1]=5;
		p[1]=3;
		for(ll i=2;i<n;++i){
			v[i]=v[i-1]*2+3;
			p[i]=p[i-1]*2+1;
		}
		ll ans=0;
		while(x){
			// 현재 n버거, x번째 패티를 먹는 상황
			if(n==0){
				++ans;
				break;
			}
			if(x<v[n-1]+2){
				--n;
				--x;
			}else{
				ans+=1+p[n-1];
				x-=v[n-1]+2;
				--n;
			}
		}
		cout<<ans;
	}
	return 0;
}