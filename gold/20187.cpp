#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

int K;
vector<char> fold;
int h=0;
void Input(){
	cin>>K;
	for(int i=0;i<2*K;++i){
		char c;
		cin>>c;
		fold.push_back(c);
	}
	cin>>h;
}
int board[256+1][256+1];
void solve(){
	reverse(fold.begin(),fold.end());
	for(int i=0;i<fold.size();++i){
		if(fold[i]=='R'){
			fold[i]='L';
		}else if(fold[i]=='L'){
			fold[i]='R';
		}else if(fold[i]=='U'){
			fold[i]='D';
		}else if(fold[i]=='D'){
			fold[i]='U';
		}
	}
	vector<string> paper;
	paper.push_back("xx");
	paper.push_back("xx");
	if(h==0){
		paper[0][0]='.';
	}else if(h==1){
		paper[0][1]='.';
	}else if(h==2){
		paper[1][0]='.';
	}else{
		paper[1][1]='.';
	}
	for(int i=0;i<fold.size();++i){
		vector<string> new_paper;
		if(fold[i]=='L'){
			for(int j=0;j<paper.size();++j){
				string cur_string=paper[j];
				reverse(cur_string.begin(),cur_string.end());
				new_paper.push_back(cur_string+paper[j]);
			}
		}else if(fold[i]=='R'){
			for(int j=0;j<paper.size();++j){
				string cur_string=paper[j];
				reverse(cur_string.begin(),cur_string.end());
				new_paper.push_back(paper[j]+cur_string);
			}
		}else if(fold[i]=='U'){
			for(int j=paper.size()-1;j>=0;--j){
				new_paper.push_back(paper[j]);	
			}
			for(int j=0;j<paper.size();++j){
				new_paper.push_back(paper[j]);
			}
		}else if(fold[i]=='D'){
			for(int j=0;j<paper.size();++j){
				new_paper.push_back(paper[j]);
			}
			for(int j=paper.size()-1;j>=0;--j){
				new_paper.push_back(paper[j]);	
			}
		}
		paper=new_paper;
	}
	vector<int> ans;
	for(int i=0;i<paper.size();i+=2){
		for(int j=0;j<paper.size();j+=2){
			char zero=paper[i][j];
			char one=paper[i][j+1];
			char two=paper[i+1][j];
			char three=paper[i+1][j+1];
			if(zero=='.'){
				ans.push_back(0);
			}else if(one=='.'){
				ans.push_back(1);
			}else if(two=='.'){
				ans.push_back(2);
			}else if(three='.'){
				ans.push_back(3);
			}
		}
	}
	// cout<<ans.size()<<endl;
	// for(int i=0;i<paper.size();++i){
	// 	cout<<paper[i]<<endl;
	// }
	int cnt=0;
	for(int i=0;i<(int)pow(2,K);++i){
		for(int j=0;j<(int)pow(2,K);++j){
			cout<<ans[cnt++]<<" ";
		}cout<<"\n";
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	Input();
	solve();
	return 0;
}