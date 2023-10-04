#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	string s;
	cin>>N;
	cin>>s;
	int num=N/5;
	char board[5+1][20000+1];
	bool viisted[5+1][20000+1];
	int h=0;
	for(int i=0;i<5;++i){
		for(int j=i*num;j<(i*num)+num;++j){
			board[i][j-(i*num)]=s[j];
		}
	}
	string ans="";
	int idx=0;
	while(1){
		if(idx>=num){
			break;
		}
		if(board[0][idx]=='.'){
			++idx;
			continue;
		}
		bool isOne=1;
		for(int j=0;j<5;++j){
			if(board[j][idx]!='#'){
				isOne=0;
				break;
			}
		}
		if(idx+1<num){
			for(int j=0;j<5;++j){
				if(board[j][idx+1]!='.'){
					isOne=0;
					break;
				}
				
			}
		}
		if(isOne){
			ans+='1';
			++idx;
		}else{
			string cur_str="";
			for(int i=0;i<5;++i){
				for(int j=idx;j<idx+3;++j){
					cur_str+=board[i][j];
				}
			}
			idx+=3;
			if(cur_str=="####.##.##.####"){
				ans+='0';
			}else if(cur_str=="###..#####..###"){
				ans+='2';
			}else if(cur_str=="###..####..####"){
				ans+='3';
			}else if(cur_str=="#.##.####..#..#"){
				ans+='4';
			}else if(cur_str=="####..###..####"){
				ans+='5';
			}else if(cur_str=="####..####.####"){
				ans+='6';
			}else if(cur_str=="###..#..#..#..#"){
				ans+='7';
			}else if(cur_str=="####.#####.####"){
				ans+='8';
			}else if(cur_str=="####.####..####"){
				ans+='9';
			}
		}
	}
	cout<<ans;
	// for(int i=0;i<5;++i){
	// 	for(int j=0;j<num;++j){
	// 		cout<<board[i][j];
	// 	}cout<<endl;
	// }
	return 0;
}