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
	cin>>t;
	while(t--){
		// 1533
		// 1st computer
		// update: 모든 n개의 컴퓨터의 파일에 복사됨
		ll n,k;
		cin>>n>>k;
		if(k==1){
			cout<<n-1<<"\n";
			continue;
		}
		if(n==1){
			cout<<1<<"\n";
			continue;
		}
		ll m=0;
		ll c=1;
		while(1){
			if(c>=k){
				break;
			}
			c*=2;
			++m;
		}
		// cout<<m<<" "<<k<<endl;
		ll ans=m;
		// cout<<(ll)pow(2,m-1)+k<<endl;	
		// cout<<ans<<endl;
		if(c<n){
			ll diff=n-c;
			ans+=(diff+k-1)/k;
		}else if(c>n){
			// pow(2,m-1)+k>n
			// m일 당시에는 n보다 많음
			bool flag=0;
			for(ll i=0;i<m;++i){
				if((ll)pow(2,i)>=n){
					ans=i;
					flag=1;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}