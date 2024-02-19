#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

vector<ll> v;
ll N;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(ll i=0;i<N;++i){
		ll a=0;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	ll L=0, R=N-1;
	ll fst_num, sed_num;
	ll ans=2000000000+1;
	ll pre_sum=2000000000+1;
	while(L<R && L<N && R<N && 0<=L && 0<=R){
		// cout<<L<<" "<<R<<endl;
		if(abs(v[L]+v[R])<=pre_sum){
			pre_sum=abs(v[L]+v[R]);
			if(abs(v[L]+v[R])<=ans){
				fst_num=v[L];
				sed_num=v[R];
				ans=abs(v[L]+v[R]);
			}
			--R;
		}else{
			++R;
			++L;
			pre_sum=abs(v[L]+v[R]);
		}
		
	}
	cout<<fst_num<<" "<<sed_num;
	return 0;
}