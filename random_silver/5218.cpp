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
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		ll n=a.size();
		cout<<"Distances: ";
		for(ll i=0;i<n;++i){
			if(a[i]<=b[i]){
				cout<<b[i]-a[i];
			}else{
				cout<<b[i]+26-a[i];
			}
			if(i==n-1){
				cout<<"\n";
			}else{
				cout<<" ";
			}
		}
	}
	return 0;
}