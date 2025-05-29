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
		// n명의 회원들 존재
		// 최소한의 사람들에게 펜을 빌리고자함
		// 한 팀이 k명의 팀원으로 구성됨
		ll n,m,k;
		cin>>n;
		cin>>m>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll sum=0;
		for(ll i=0;i<n;++i){
			sum+=v[i];
		}
		if(sum<k*m){
			cout<<"STRESS";
		}else{
			ll c=0;
			sum=0;
			for(ll i=n-1;i>=0;--i){
				sum+=v[i];
				++c;
				if(sum>=m*k){
					break;
				}
			}
			cout<<c;
		}
	} 
	return 0;
}