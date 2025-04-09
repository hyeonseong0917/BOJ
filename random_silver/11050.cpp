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
		ll n,k;
        cin>>n>>k;
        ll fst_num=1;
        ll sed_num=1;
        for(ll i=n;i>n-k;--i){
            fst_num*=i;
        }
        for(ll i=1;i<=k;++i){
            sed_num*=i;
        }
        cout<<fst_num/sed_num;
	} 
	return 0;
}