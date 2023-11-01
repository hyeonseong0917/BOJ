#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int board[10+1][10+1];
int color_paper[5+1]; // color_paper[i]: i번째 색종이가 color_paper[i]개 남음
string init_str="";
void Input(){
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			cin>>board[i][j];
			init_str+=(board[i][j]+'0');
		}
	}
	for(int i=1;i<=5;++i){
		color_paper[i]=5;
	}
}
int min_num=122232421;
void dfs(string s, int ans, int y, int x){
	// for(int i=0;i<10;++i){
	// 	for(int j=0;j<10;++j){
	// 		cout<<s[j+i*10];
	// 	}cout<<endl;
	// }cout<<endl;
	// cout<<y<<" "<<x<<endl;
	bool flag=1;
	for(int i=0;i<100;++i){
		if(s[i]=='1'){
			flag=0;
			break;
		}
	}
	if(flag){
		min_num=min(min_num,ans);
		return;
	}
	if(x>=10 || y>=10){
		return;
	}
	if(s[x+10*y]=='0'){
		if(x+1<10){
			dfs(s,ans,y,x+1);
		}else if(y+1<10){
			dfs(s,ans,y+1,0);
		}
	}else{
		for(int i=1;i<=5;++i){
			if(!color_paper[i]) continue;
			--color_paper[i];
			bool isExist=1;
			for(int j=y;j<y+i;++j){
				for(int k=x;k<x+i;++k){
					if(j>=10 || k>=10 || s[k+j*10]=='0'){
						isExist=0;
					}
				}
				if(!isExist){
					break;
				}
			}
			if(isExist){
				string tmp_s=s;
				for(int j=y;j<y+i;++j){
					for(int k=x;k<x+i;++k){
						s[k+j*10]='0';
					}
				}
				if((x+i)==10){
					dfs(s,ans+1,y+1,0);	
				}else{
					dfs(s,ans+1,y,x+i);
				}
				s=tmp_s;
			}
			++color_paper[i];
		}
	}

}
void solve(){
	dfs(init_str,0,0,0);
	if(min_num==122232421){
		cout<<-1;
	}else{
		cout<<min_num;
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}