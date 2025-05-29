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
		// 1131
		// k종류 마시면 뻗음
		// n개중 k개 선택, 맛을 극대화 하는 방법
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll ans=v[n-1];
		ll L=0, R=n-2;
		ll cnt=1;
		ll cur_num=0;
		while(L<=R && cnt<k){
			if(cnt%2==1){
				cur_num=v[L];
				++L;
			}else{
				ans+=v[R]-cur_num;
				--R;
			}
			++cnt;
		}
		cout<<ans;
		// 3 6 8 8 15
	} 
	return 0;
}