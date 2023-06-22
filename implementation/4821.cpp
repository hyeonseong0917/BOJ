#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> v;
int main() {
	// your code goes here
	int page=0;
	string s;
	int arr[1000+1];
	vector<string> v;
	while(1){
		cin>>page;
		cin>>s;
		if(page==0){
			break;
		}
		v.clear();
		for(int i=0;i<1001;++i){
			arr[i]=0;
		}
		int idx=0;
		string cur_string="";
		for(int i=0;i<s.size();++i){
			if(s[i]==','){
				v.push_back(cur_string);
				cur_string="";
			}else{
				cur_string+=s[i];
			}
		}
		if(cur_string!=""){
			v.push_back(cur_string);
		}
		int cnt=0;
		for(int i=0;i<v.size();++i){
			string cur_seg=v[i];
			bool isOnly=1;
			int minusIdx=0;
			for(int j=0;j<cur_seg.size();++j){
				if(cur_seg[j]=='-'){
					isOnly=0;
					minusIdx=j;
				}
			}
			if(isOnly==0){
				// cout<<minusIdx<<endl;
				int first_num=stoi(cur_seg.substr(0,minusIdx));
				int second_num=stoi(cur_seg.substr(minusIdx+1));
				if(first_num<=second_num){
					for(int i=first_num;i<=second_num;++i){
						if(!arr[i] && i<=page){
							++cnt;
							arr[i]=1;
						}
					}
				}
			}else{
				if(!arr[stoi(cur_seg)] && stoi(cur_seg)<=page){
					arr[stoi(cur_seg)]=1;
					++cnt;
				}
			}
		}
		
		cout<<cnt<<"\n";
		// cout<<s<<endl;
	}
	return 0;
}