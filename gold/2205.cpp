#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 납덩어리 1..n
		// 주석덩어리 1..n
		// 납덩어리 1개와 주석덩어리 1개를 녹여 질량이 2의 n제곱이 되는 저울추 n개 만들 예정
		// 납이 2의 n제곱이라면 주석도 2의 m제곱이어야함
		// 납이 2의 n제곱 - x라면 주석은 2의 m제곱 + x여야함
		// 24=16+8=8+16
		ll n;
		cin>>n;
		// n까지의 합 *2를 2의 거듭제곱으로 나타내는 방법?
		vector<ll> ans;
		vector<ll> check(n+1,0);
		for(ll i=n;i>=1;--i){
			// i와 매칭됐을 때 2의 거듭제곱으로 만들기
			// i보다 큰 2의 거듭제곱
			ll c=1;
			while(1){
				c*=2;
				ll d=c-i;
				if(d>n){
					c/=2;
					break;
				}
			}
			while(1){
				if(!check[c-i]){
					++check[c-i];
					ans.push_back(c-i);
					break;
				}else{
					c/=2;
				}
			}
			
		}
		reverse(ans.begin(),ans.end());
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<"\n";
		}
	}
	return 0;
}