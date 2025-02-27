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
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		if(n==1){
			cout<<0<<"\n";
		}else{
			string s="";
			for(ll i=0;i<n;++i){
				s+='2';
			}
			s[0]='1';
			s[n-1]='1';
			cout<<s<<"\n";
		}
	}
	return 0;
}