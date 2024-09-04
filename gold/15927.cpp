#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		string s;
		cin>>s;
		ll n=s.size();
		if(n==1){
			cout<<-1;
			break;
		}
		bool is_same=1;
		for(ll i=1;i<n;++i){
			if(s[i]!=s[0]){
				is_same=0;
				break;
			}
		}
		if(is_same){
			cout<<-1;
		}else{
			ll L=0, R=n-1;
			bool is_pal=1;
			while(L<R){
				if(s[L]==s[R]){
					++L;
					--R;
				}else{
					is_pal=0;
					break;
				}
			}
			if(is_pal){
				cout<<n-1;
			}else{
				cout<<n;
			}
		}
	}
	return 0;
}