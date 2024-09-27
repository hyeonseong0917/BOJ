#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		string s="";
		for(ll i=0;i<n;++i){
			char c;
			cin>>c;
			s+=c;
		}
		string ans="";
		ll L=0, R=n-1;
		while(L<=R){
			if(L==R){
				ans+=s[L];
				break;
			}
			if(s[L]<s[R]){
				ans+=s[L++];
			}else if(s[L]>s[R]){
				ans+=s[R--];
			}else{
				// s[L]==s[R]
				ll l=L+1;
				ll r=R-1;
				bool is_right_big=0;
				bool is_left_big=0;
				bool is_all_same=0;
				while(l<=r){
					if(l==r){
						is_all_same=1;
						break;
					}
					if(s[l]<s[r]){
						is_right_big=1;
						break;
					}else if(s[l]>s[r]){
						is_left_big=1;
						break;	
					}else{
						++l;
						--r;
					}
				}
				if(is_all_same){
					while(L<=R){
						ans+=s[L++];
					}
					break;
				}else{
					if(is_left_big){
						ans+=s[R--];
					}else{
						ans+=s[L++];
					}
				}
			}
		}
		for(ll i=0;i<ans.size();++i){
			if(i%80==0 & i!=0){
				cout<<"\n";
			}
			cout<<ans[i];
		}
		// cout<<ans;
	}
	return 0;
}