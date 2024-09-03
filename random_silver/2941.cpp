#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		string s;
		cin>>s;
		ll n=s.size();
		if(n==1){
			cout<<1;
			break;
		}
		ll ans=0;
		ll idx=0;
		while(idx<n){
			if(idx+2<=n-1){
				string t=s.substr(idx,3);
				if(t.compare("dz=")==0){
					++ans;
					idx+=3;
					continue;
				}
			}
			// cout<<idx<<endl;
			if(idx+1<=n-1){
				string t=s.substr(idx,2);
				// cout<<idx<<endl;
				if(t.compare("c=")==0){
					++ans;	
					idx+=2;
					continue;
				} 
				if(t.compare("c-")==0){
					++ans;	
					idx+=2;
					continue;
				} 
				if(t.compare("d-")==0){
					++ans;	
					idx+=2;
					continue;
				} 
				if(t.compare("lj")==0){
					++ans;	
					idx+=2;
					continue;
				} 
				if(t.compare("nj")==0){
					++ans;	
					idx+=2;
					continue;
				} 
				if(t.compare("s=")==0){
					++ans;	
					idx+=2;
					continue;
				} 
				if(t.compare("z=")==0){
					++ans;	
					idx+=2;
					continue;
				} 
			}
			++ans;
			++idx;
			
		}
		

		cout<<ans;
	}
	return 0;
}