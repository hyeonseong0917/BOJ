#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	string s="";
	cin>>s;
	int zero_cnt=0;
	int one_cnt=0;
	int lastNum=-1;
	for(int i=0;i<s.size();++i){
		if(lastNum!=s[i]){
			if(s[i]=='0'){
				++zero_cnt;
			}else{
				++one_cnt;
			}
			// cout<<zero_cnt<<" "<<one_cnt<<endl;
			lastNum=s[i];
			
		}
	}
	cout<<min(zero_cnt,one_cnt);
	return 0;
}