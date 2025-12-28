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
        ll n=s.size();
        stack<char> st;
        ll ans=0;
        ll idx=0;
        while(idx<n){
            if(idx<n-1 && s[idx]=='(' && s[idx+1]==')'){
                ll ss=st.size();
                ans+=ss;
                idx+=2;
            }else{
                if(s[idx]=='('){
                    st.push(s[idx]);
                }else{
                    st.pop();
                    ++ans;
                    // cout<<idx<<endl;
                }
                ++idx;
            }
        }
        cout<<ans;
	} 
	return 0;
}