#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll x,y;
		cin>>x>>y;
		
		// 0+1+2+...+n=x+y인 n을 찾는다
		ll L=0, R=1000000000;
		ll n=-1;
		while(L<=R){
			// 0+1+2+...+mid=(x+y)?
			ll mid=(L+R)/2;
			ll sum;
			if(mid%2==0){
				sum=mid*(mid/2)+mid/2;
			}else{
				sum=mid*((mid+1)/2);
			}
			// cout<<L<<" "<<R<<" "<<sum<<endl;

			if(sum==(x+y)){
				n=mid;
				break;
			}
			if(sum<(x+y)){
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		if(n==-1){
			cout<<-1;
			break;
		}
		if(x==0){
			cout<<0;
			break;
		}
		// cout<<n<<endl;
		// cout<<n<<endl;
		// min인 start_num을 구한다
		L=0, R=n;
		ll min_start_num=n+1;
		while(L<=R){
			ll mid=(L+R)/2;
			// [mid,n]까지의 합
			ll cnt=n-mid+1;
			ll sum=0;
			if(cnt%2==0){
				sum=(n+mid)*(cnt/2);
			}else{
				// 홀수개라면
				sum=(n+mid)*(cnt/2)+(n+mid)/2;
			}
			// cout<<mid<<" "<<sum<<endl;
			if(sum<x){
				min_start_num=min(min_start_num,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		ll ans;
		if(min_start_num==n+1){
			ans=1;
		}else{
			ans=n-min_start_num+1;
			++ans;
		}
		cout<<ans;
	} 
	return 0;
}