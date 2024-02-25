#include <iostream>
#include <stack>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin>>s;
	stack<char> st;
	for(int i=0;i<s.size();++i){
		st.push(s[i]);
		if(st.size()>=4){
			string t="";
			char fst_num=st.top();
			st.pop();
			char sed_num=st.top();
			st.pop();
			char trd_num=st.top();
			st.pop();
			char fth_num=st.top();
			st.pop();
			t+=fst_num;
			t+=sed_num;
			t+=trd_num;
			t+=fth_num;
			// cout<<t<<" "<<st.size()<<endl;
			if(t=="PAPP"){
				st.push('P');
			}else{
				st.push(fth_num);
				st.push(trd_num);
				st.push(sed_num);
				st.push(fst_num);
			}
		}
	}
	if(st.size()==1){
		if(st.top()=='P'){
			cout<<"PPAP";	
		}else{
			cout<<"NP";
		}
	}else{
		cout<<"NP";
	}
	
	return 0;
}