#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
int main() {
	
	// your code goes here
	// 1 9 
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int cnt=1;
	while(cnt--){
		ll n,m;
		cin>>n>>m;
		ll min_fst_num=1222232421;
		ll min_sed_num=1222232421;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			min_fst_num=min(min_fst_num,a);
			min_sed_num=min(min_sed_num,b);
		}
		ll ans=0;
		ans+=(n/6)*min(min_fst_num,min_sed_num*6);
		n%=6;
		ans+=min(n*min_sed_num,min_fst_num);
		
		cout<<ans;
	}
	

	

	return 0;
}