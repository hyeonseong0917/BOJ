#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

string get_clock_num(string input_str){
	vector<string> clock_num;
	clock_num.push_back(input_str);
	clock_num.push_back(input_str.substr(1)+input_str.substr(0,1));
	clock_num.push_back(input_str.substr(2)+input_str.substr(0,2));
	clock_num.push_back(input_str.substr(3)+input_str.substr(0,3));
	sort(clock_num.begin(),clock_num.end());
	return clock_num[0];
}

int main() {
	// your code goes here
	string ans="";
	// cout<<get_clock_num("7322");
	// int rank[9999+1]={0,};
	// for(int i=0;i<10000;++i){
	// 	rank[i]=0;
	// }
	map<string,int> rank;
	for(int i=0;i<4;++i){
		int a=0;
		cin>>a;
		ans+=(a+'0');
	}
	ans=get_clock_num(ans);
	// cout<<ans;
	int cnt=1;
	for(int i=1111;i<=9999;++i){
		string cur_string=to_string(i);
		bool isZeroExist=0;
		for(int j=0;j<4;++j){
			if(cur_string[j]=='0'){
				isZeroExist=1;
				break;
			}
		}
		if(isZeroExist==0){
			cur_string=get_clock_num(cur_string);
			if(rank[cur_string]==0){
				rank[cur_string]=cnt++;
			}
		}
	}
	cout<<rank[ans];
	return 0;
}