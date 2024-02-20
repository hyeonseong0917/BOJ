#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin>>N;
	string s;
	cin>>s;
	vector<int> ans;
	int cur_num=0;
	int next_num=0;
	char c=' ';
	for(int i=0;i<s.size();++i){
		if(s[i]=='S' || s[i]=='M' || s[i]=='U' || s[i]=='P' || s[i]=='C'){
			if(c==' '){
				if(s[i]=='C'){
					ans.push_back(cur_num);
				}else{
					c=s[i];
				}
				continue;
			}
			int cur_ans;
			if(c=='S'){
				cur_ans=cur_num-next_num;
			}else if(c=='M'){
				cur_ans=cur_num*next_num;
			}else if(c=='U'){
				cur_ans=cur_num/next_num;
			}else if(c=='P'){
				cur_ans=cur_num+next_num;
			}
			if(s[i]=='C'){
				if(c==' '){
					ans.push_back(cur_num);		
				}else{
					ans.push_back(cur_ans);
					c=' ';
				}
			}else{
				c=s[i];
			}
			cur_num=cur_ans;
			next_num=0;
		}else{
			if(c==' '){
				string cur_str=to_string(cur_num);
				cur_str+=s[i];
				cur_num=stoi(cur_str);
			}else{
				string next_str=to_string(next_num);
				next_str+=s[i];
				next_num=stoi(next_str);
			}
		}
	}
	if(ans.empty()){
		cout<<"NO OUTPUT";
	}else{
		for(int i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}
	}
	

	return 0;
}