#include <iostream>
#include <vector>
using namespace std;

const int MAX=100+1;
int N=0;
vector<string> parrot[MAX];
vector<int> sentence_idx; // 몇 번 문장?, idx는 몇?
string ans="";
vector<string> ans_word;
void Input(){
	// cin>>N;
	string num="";
	getline(cin,num);
	N=stoi(num);
	for(int i=0;i<N;++i){
		string s="";
		getline(cin,s);
		// cout<<s<<endl;
		string tmp="";
		for(int j=0;j<s.size();++j){
			if(s[j]==' '){
				parrot[i].push_back(tmp);
				tmp="";
			}else{
				tmp+=s[j];
			}
		}
		parrot[i].push_back(tmp);
		sentence_idx.push_back(0);
	}
	getline(cin,ans);
	// cout<<ans;
	string cur_tmp="";
	for(int i=0;i<ans.size();++i){
		if(ans[i]==' '){
			ans_word.push_back(cur_tmp);
			cur_tmp="";
		}else{
			cur_tmp+=ans[i];
		}
	}	
	ans_word.push_back(cur_tmp);
}
void solve(){
	// cout<<ans_word.size()<<endl;
	int sum=0;
	for(int i=0;i<N;++i){
		sum+=parrot[i].size();
	}
	if(ans_word.size()!=sum){
		cout<<"Impossible";
		return;
	}
	for(int i=0;i<ans_word.size();++i){
		string cur_word=ans_word[i];
		// cout<<cur_word<<endl;
		bool flag=0;
		// cout<<i<<" "<<cur_word<<" "<<sentence_idx[0].second<<endl;
		for(int j=0;j<N;++j){
			int cur_sentence_num=j;
			int cur_sentence_idx=sentence_idx[j];
			if(cur_sentence_idx>=parrot[cur_sentence_num].size()) continue;
			if(cur_word==parrot[cur_sentence_num][cur_sentence_idx]){
				flag=1;
				++sentence_idx[j];
				break;
			}
		}
		if(flag==0){
			cout<<"Impossible";
			return;
		}
	}
	cout<<"Possible";
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}