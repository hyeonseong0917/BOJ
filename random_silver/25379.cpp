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
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll fst_sum=0, sed_sum=0;
		// fst_sum: 왼쪽 짝수
		// sed_sum: 왼쪽 홀수
		ll odd_cnt=0, even_cnt=0;
		for(ll i=0;i<n;++i){
			if(v[i]%2==0){
				// 짝수라면
				++even_cnt;
				fst_sum+=odd_cnt;
				// odd_cnt=0;
			}else{
				++odd_cnt;
				sed_sum+=even_cnt;
				// even_cnt=0;
			}
		}
		cout<<min(fst_sum,sed_sum);
		

	}
	return 0;
}