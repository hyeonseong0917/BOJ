#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N=0;
vector<char> v;
vector<string> ans;
int calc(int a, char c, int b){
	if(c=='+'){
		return a+b;
	}else if(c=='-'){
		return a-b;
	}
	return 0;
}

void pick(int pm_cnt, int N){
	if(pm_cnt==0){
		int sum=0;
		string cur_str="";
		for(int i=0;i<N-1;++i){
			cur_str+=(i+1)+'0';
			cur_str+=v[i];
		}
		cur_str+=N+'0';
		string new_str="";
		vector<char> idx;
		for(int i=0;i<cur_str.size();++i){
			if(cur_str[i]!=' '){
				if(cur_str[i]=='-' || cur_str[i]=='+'){
					idx.push_back(cur_str[i]);
				}
				new_str+=cur_str[i];
			}
		}
		vector<int> num;
		string tmp="";
		for(int i=0;i<new_str.size();++i){
			if(new_str[i]=='-' || new_str[i]=='+'){
				num.push_back(stoi(tmp));
				tmp="";
			}else{
				tmp+=new_str[i];
			}
		}
		if(tmp!=""){
			num.push_back(stoi(tmp));
		}
		// int pre_num=0;
		for(int i=0;i<idx.size();++i){
			if(i==0){
				sum=calc(num[i],idx[i],num[i+1]);
			}else{
				sum=calc(sum,idx[i],num[i+1]);
			}
		}
		if(sum==0 && idx.size()){
			ans.push_back(cur_str);
		}
		
		return;
	}
	v.push_back('+');
	pick(pm_cnt-1,N);
	v.pop_back();

	v.push_back('-');
	pick(pm_cnt-1,N);
	v.pop_back();

	v.push_back(' ');
	pick(pm_cnt-1,N);
	v.pop_back();

}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		cin>>N;
		v.clear();
		ans.clear();
		pick(N-1,N);
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();++i){
			cout<<ans[i]<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}