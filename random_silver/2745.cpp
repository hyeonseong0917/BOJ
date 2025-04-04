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
		string a;
		ll b;
		cin>>a>>b;
		ll ans=0;
		for(ll i=0;i<a.size();++i){
			char c=a[a.size()-1-i];
			if('0'<=c && c<='9'){
				ans+=(c-'0')*(ll)pow(b,i);
			}else{
				ans+=(c-'A'+10)*(ll)pow(b,i);
			}
		}
		cout<<ans<<"\n";

	} 
	return 0;
}