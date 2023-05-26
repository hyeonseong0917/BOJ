#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	//1000111
	//1010110
	while(t--){
		string a,b;
		cin>>a;
		cin>>b;
		string res="";
		// stack<int> ans;
		int idx=1;
		int as=a.size();
		int bs=b.size();
		char to_add='0';
		while(1){
			if(as-idx<0 && bs-idx<0){
				break;
			}
			char curA,curB;
			if(as-idx>=0){
				curA=a[as-idx];
			}else{
				curA='0';
			}
			if(bs-idx>=0){
				curB=b[bs-idx];
			}else{
				curB='0';
			}
			
			int curNum=to_add-'0'+curA-'0'+curB-'0';
			if(curNum==0){
				res+='0';
				to_add='0';
			}else if(curNum==1){
				res+='1';
				to_add='0';
			}else if(curNum==2){
				res+='0';
				to_add='1';
			}else if(curNum==3){
				res+='1';
				to_add='1';
			}
			// cout<<curA<<" "<<curB<<" "<<res<<endl;
			++idx;
		}
		if(to_add=='1'){
			res+='1';
		}
		string ans="";
		reverse(res.begin(),res.end());
		if(res[0]!='0'){
			cout<<res<<endl;	
		}else{
			int startIdx=-1;
			for(int i=0;i<res.size();++i){
				if(res[i]!='0'){
					startIdx=i;
					break;
				}
			}	
			if(startIdx==-1){
				cout<<"0"<<endl;
			}else{
				ans=res.substr(startIdx);
				cout<<ans<<endl;	
			}
			
		}
		
		
	}
	return 0;
}