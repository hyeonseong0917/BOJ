#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>t;
	while(o--){
		ll n,k;
		cin>>n>>k;
		stack<ll> a,b;
		ll a_sum=0, b_sum=0;
		for(ll i=0;i<n;++i){
			ll c;
			cin>>c;
			a.push(c);
			a_sum+=c;
		}
		for(ll i=0;i<n;++i){
			ll c; 
			cin>>c;
			b_sum+=c;
			b.push(c);
		}
		// 1. 승형이는 a와b중에 더 가벼운거 가져감
		// 2. 원빈이는 승형이가 가져간 거 말고 다른거 가져감
		// 3. 원빈이가 들어야 하는 무게의 최솟값??
		// 4. k번 제거할 수 있음
		while(k--){
			if(a_sum<=b_sum){
				b_sum-=b.top();
				b.pop();
			}else{
				a_sum-=a.top();
				a.pop();
			}
		}
		cout<<max(a_sum,b_sum);
	} 
	return 0;
}