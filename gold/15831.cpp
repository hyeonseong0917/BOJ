#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,b,w;
		cin>>n>>b>>w;
		string s;
		cin>>s;
		ll L=0, R=0;
		ll b_cnt=0, w_cnt=0;
		ll ans=0;
		while(L<=R && R<n){
			// cout<<L<<" "<<R<<" "<<b_cnt<<" "<<w_cnt<<endl;
			// R번째 문자 윈도우에 추가
			if(s[R]=='W'){
				++w_cnt;
			}else{
				++b_cnt;
			}
			if(b_cnt>b){
				while(L<R && b_cnt>b){
					if(s[L]=='W'){
						--w_cnt;
					}else{
						--b_cnt;
					}	
					++L;	
				}
				if(w_cnt>=w && b_cnt<=b){
					ans=max(ans,R-L+1);
				}
			}else{
				if(w_cnt>=w){
					ans=max(ans,R-L+1);
				}
			}
			++R;
		}
		cout<<ans;

	}
	return 0;
}