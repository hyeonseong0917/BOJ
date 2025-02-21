#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll e,s,m;
		cin>>e>>s>>m;
		ll ans=1;
		ll a=1,b=1,c=1;
		while(1){
			if(a==e && b==s && c==m){
				break;
			}
			a=a%15+1;
			b=b%28+1;
			c=c%19+1;
			++ans;
		}
		cout<<ans;
	}
	return 0;
}