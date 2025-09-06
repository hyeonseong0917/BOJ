#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1212
		ll n,k,t;
		cin>>n>>k>>t;
		vector<ll> v(n,0);
		ll sum=0;
		bool flag=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]){
				flag=1;
			}
			sum+=v[i];
		}
		sort(v.begin(),v.end());
		if(sum%k!=0){
			cout<<"NO";
			break;
		}
		if(!flag){
			cout<<"YES";
			break;
		}
		if(sum<k){
			cout<<"NO";
			break;
		}
		// v[i]<k
		// T회 이하로 옮겨서 모두 터트리는 것이 가능한지?
		// n k t
		// 3 5 3
		// 0 1 2 3 4 5 6 7
		// 1 1 2 2 3 3 4 4
		ll L=0, R=n-1;
		ll cnt=0;
		while(L<R){
			// R번째를 터트리기 위해 L번쨰 인덱스의 값부터 가져옴
			ll diff=k-v[R];
			// L번쨰 인덱스부터 diff값을 가져옴
			ll cur_sum=0;
			while(L<R){
				cur_sum+=v[L];
				cnt+=v[L];
				if(cur_sum<diff){
					++L;
				}else{
					// cur_sum>=diff
					// (cur_sum-diff)만큼 넘쳤음
					ll c=v[L]-(cur_sum-diff);
					// v[L]에서는 c만큼 가져갈 것임?
					cnt-=v[L];
					v[L]-=c;
					cnt+=c;
					break;
				}
			}
			--R;
		}
		if(cnt<=t){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}
	return 0;
}