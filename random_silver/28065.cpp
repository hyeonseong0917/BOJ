#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;	
	while(t--){	
		ll n;
		cin>>n;
		// 2<=i<=n-1
		// |a[i]-a[i-1]|>|a[i+1]-a[i]|
		// 1이상 n이하의 정수, n>=3
		// n 1 n-1 2 n-2 3
		ll L=1, R=n;
		for(ll i=0;i<n;++i){
			if(i%2==0){
				cout<<R<<" ";
				--R;
			}else{
				cout<<L<<" ";
				++L;
			}
		}
	}
	return 0;
}