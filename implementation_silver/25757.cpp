#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int N=0;
	char c;
	cin>>N;
	cin>>c;
	int cnt=0;
	int cur_game_num=0;
	if(c=='Y'){
		cur_game_num=2;
	}else if(c=='F'){
		cur_game_num=3;
	}else if(c=='O'){
		cur_game_num=4;
	}
	map<string,int> m;
	int cur_cnt=1;
	for(int i=0;i<N;++i){
		string s="";
		cin>>s;
		if(!m[s]){
			m[s]=1;
			++cur_cnt;
			if(cur_cnt==cur_game_num){
				++cnt;
				cur_cnt=1;
			}
		}
	}
	cout<<cnt;
	
	return 0;
}