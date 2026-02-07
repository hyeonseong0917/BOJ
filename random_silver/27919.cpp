#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
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
    string s;
    cin>>s;
    // u와 c, d와 p가 바뀔 수 있음
    string ans="";
    // 1. u가 선정 가능한지?
    ll u_cnt=0;
    ll c_cnt=0;
    ll d_cnt=0;
    ll p_cnt=0;
    ll n=s.size();
    for(ll i=0;i<n;++i){
      if(s[i]=='U'){
        ++u_cnt;
      }
      if(s[i]=='C'){
        ++c_cnt;
      }
      if(s[i]=='D'){
        ++d_cnt;
      }
      if(s[i]=='P'){
        ++p_cnt;
      }
    }
    // 1. u가 가능?
    if(u_cnt+c_cnt>(d_cnt+p_cnt+1)/2){
      ans+='U';
    }
    // 2. D가 가능?
    if(d_cnt || p_cnt){
      ans+="DP";
    }
    if(ans==""){
      ans="C";
    }
    cout<<ans;
	} 
	return 0;
}