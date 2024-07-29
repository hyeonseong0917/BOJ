#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
#define ll long long

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ll o=1;
    while(o--){
    	string s;
    	ll n;
    	cin>>n;
    	cin>>s;
    	string r="";
    	string b="";
    	for(ll i=0;i<n;++i){
    		r+='R';
    		b+='B';
    	}
    	ll ans=1222232421;
    	ll r_cnt=1;
    	// 다 r로 칠했다고 가정
    	// B의 연속구간 개수?
    	ll L=0, R=0;
    	while(L<n){
    		// cout<<L<<endl;
    		if(s[L]=='B'){
    			++r_cnt;
    			ll next_idx=-1;
    			for(ll i=L+1;i<n;++i){
    				if(s[i]!=s[L]){
    					next_idx=i;
    					break;
    				}
    			}
    			if(next_idx==-1){
    				break;
    			}
    			L=next_idx;
    		}else{
    			++L;
    		}
    	}
    	
    	ll b_cnt=1;
    	L=0;
    	while(L<n){
    		if(s[L]=='R'){
    			++b_cnt;
    			ll next_idx=-1;
    			for(ll i=L+1;i<n;++i){
    				if(s[i]!=s[L]){
    					next_idx=i;
    					break;
    				}
    			}
    			if(next_idx==-1){
    				break;
    			}
    			L=next_idx;
    		}else{
    			++L;
    		}
    	}
    	ans=min(r_cnt,b_cnt);

    	L=0, R=0;
    	ll cnt=1;
    	while(L<=R && R<n-1){
    		if(s[L]!=s[R+1]){
    			L=R+1;
    			++R;
    			++cnt;
    		}else{
    			++R;
    		}
    	}
    	// cout<<cnt<<"\n";
    	ans=min(ans,cnt);
    	cout<<ans;
    }
    return 0;
}

