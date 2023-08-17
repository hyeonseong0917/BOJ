#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin>>s;
	int idx=0;
	int N=0;
	for(int i=1;i<=10000000;++i){
		// int tmp_idx=idx;
		string cur_str=to_string(i);
		for(int j=0;j<cur_str.size();++j){
			if(cur_str[j]==s[idx] && idx<=s.size()){
				++idx;
			}
		}
		if(idx==s.size()){
			N=i;
			break;
		}
	}
	cout<<N;
	return 0;
}