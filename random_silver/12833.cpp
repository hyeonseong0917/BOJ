#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
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
		ll a,b,c;
		cin>>a>>b>>c;
		c%=2;
		ll fst_num=a^b;
		ll sed_num=fst_num^b;
		if(c==0){
			cout<<sed_num;
		}else{
			cout<<fst_num;
		}
	}
	return 0;
}