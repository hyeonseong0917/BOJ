#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N=0;
string s="";
vector<double> v;
void Input(){
	cin>>N;
	cin>>s;
	for(int i=0;i<N;++i){
		double a=0;
		cin>>a;
		v.push_back(a);
	}
}
void solve(){
	cout<<fixed;
	cout.precision(2);
	stack<double> st;
	
	for(int i=0;i<s.size();++i){
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
			double first_num=st.top();
			st.pop();
			double second_num=st.top();
			st.pop();
			if(s[i]=='+'){
				st.push(first_num+second_num);
			}else if(s[i]=='-'){
				st.push(second_num-first_num);
			}else if(s[i]=='*'){
				st.push(first_num*second_num);
			}else if(s[i]=='/'){
				st.push(second_num/first_num);
			}
			// cout<<st.top()<<endl;
		}else{
			// cout<<i<<" "<<s[i]<<endl;
			st.push(v[s[i]-'A']);
		}
	}
	cout<<st.top();
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}