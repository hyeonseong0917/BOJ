#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string s;
int ans=0;
void Input(){
	cin>>s;
}
void solve(){
	stack<char> st;
	int cur_sum=0;
	int to_add=1;
	bool flag=0;
	for(int i=0;i<s.size();++i){
		char cur_char=s[i];
		if(cur_char=='[' || cur_char=='('){
			if(cur_char=='['){
				to_add*=3;
				st.push('[');
			}else{
				to_add*=2;
				st.push('(');
			}
			// st.push(cur_char);
		}else{
			if(cur_char==']'){
				if(st.empty() || st.top()!='['){
					ans=0;
					break;
				}
				if(s[i-1]=='['){
					ans+=to_add;
					to_add/=3;
					st.pop();
				}else{
					to_add/=3;
					st.pop();
				}
				
			}else{
				if(st.empty() || st.top()!='('){
					ans=0;
					break;
				}
				if(s[i-1]=='('){
					ans+=to_add;
					to_add/=2;
					st.pop();
				}else{
					to_add/=2;
					st.pop();
				}
			}
		}
		// if(!st.empty()){
		// 	ans=0;
		// }
		// cout<<ans;
		// cout<<s[i]<<" "<<to_add<<" "<<cur_sum<<" "<<ans<<endl;
	}
	if(!st.empty()){
		ans=0;
	}
	cout<<ans;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}