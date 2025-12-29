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
        ll t;
        cin>>t;
        while(t--){
            string s;
            cin>>s;
            ll n=s.size();
            stack<char> lst, rst;
            string ans="";
            for(ll i=0;i<n;++i){
                if(s[i]=='<'){
                    if(!lst.empty()){
                        char l=lst.top();
                        lst.pop();
                        rst.push(l);
                    }
                }else if(s[i]=='>'){
                    if(!rst.empty()){
                        char r=rst.top();
                        rst.pop();
                        lst.push(r);
                    }
                }else if(s[i]=='-'){
                    if(!lst.empty()){
                        lst.pop();
                    }
                }else{
                    lst.push(s[i]);
                }
            }
            while(!rst.empty()){
                char r=rst.top();
                rst.pop();
                lst.push(r);
            }

            while(!lst.empty()){
                char l=lst.top();
                ans+=l;
                lst.pop();
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<"\n";
        }
	} 
	return 0;
}