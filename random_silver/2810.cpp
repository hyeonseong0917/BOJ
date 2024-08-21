#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		string s;
		cin>>s;
		string t=" ";
		for(ll i=0;i<n;++i){
			t+=s[i];
			t+=' ';
		}
		ll ans=0;
		ll ts=t.size();
		ll idx=1;
		// cout<<t<<endl;
		while(idx<ts){
			if(t[idx]=='.' || t[idx]==' '){
				++idx; 
				continue;
			} 
			if(t[idx]=='S'){
				if(t[idx-1]==' '){
					t[idx-1]='.';
					++ans;
					// cout<<idx-1<<endl;
				}else{
					if(t[idx+1]==' '){
						t[idx+1]='.';
						++ans;
						// cout<<idx+1<<endl;
					}
				}
				idx+=2;
			}else{
				if(t[idx-1]==' '){
					t[idx-1]='.';
					// cout<<idx-1<<endl;
					++ans;
				}
				if(t[idx+3]==' '){
					t[idx+3]='.';
					// cout<<idx+3<<endl;
					++ans;
				}
				idx+=4;
			}
		}
		
		cout<<ans;

	}
	return 0;
}