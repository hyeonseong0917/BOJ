#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

const int MAX=1000+1;

ll n,m;
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0-1};
bool isRange(ll y, ll x){
	return (y>=1 && x>=1 && y<=n && x<=n);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	// cin>>o;
	while(o--){
		
		cin>>n>>m;
		vector<ll> a(m,0),b(m,0);
		for(ll i=0;i<m;++i){
			cin>>a[i];
			cin>>b[i];
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ll x=a[m/2];
		ll y=b[m/2];
		ll ans=0;
		for(ll i=0;i<m;++i){
			ans+=abs(x-a[i])+abs(y-b[i]);
		}
		cout<<ans;
	}
	return 0;
}