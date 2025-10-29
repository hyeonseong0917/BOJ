#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll t;
		cin>>t;
		while(t--){
			ll n,m;
			cin>>n>>m;
			ll ans=0;
			// n은 황소의 초기 체력, m은 현재 가지고 있는 먹이의 개수
			while(n){
				n/=2;
				++ans;
			}
			ans+=n+m;
			cout<<ans<<"\n";


		}
	}
	return 0;
}