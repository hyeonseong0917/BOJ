#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> A(n,0), B(m,0);
		for(ll i=0;i<n;++i){
			cin>>A[i];
		}
		for(ll i=0;i<m;++i){
			cin>>B[i];
		}
		ll sum=0;
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		ll R=n-1;
		ll L=0;
		while(R>=0 && L<m){
			if(A[R]<B[L]){
				break;
			}
			sum+=A[R--]-B[L++];
		}
		cout<<sum;
	}
	return 0;
}