#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// i-1번째 행성에서 i번째 행성으로 이동하기 위한 필요한 최고 속도 v[i]
		// i=1 -> 0번째 행성에서 1번째 행성으로 이동하기 위해 필요한 최고 속도 300
		// i=2 -> 1번째 행성에서 2번째 행성으로 이동하기 위해 필요한 최고 속도 400
		// 300 400 500 400 300
		// 900 800 500 400 300
		// n은 최대 30만
		ll cur_num=0;
		for(ll i=n-1;i>=0;--i){
			if(cur_num<=v[i]){
				cur_num=v[i];
			}else{
				// cur_num>v[i]
				ll q=(cur_num+v[i]-1)/v[i];
				cur_num=v[i]*q;
			}
		}
		cout<<cur_num;
	}

	return 0;
}