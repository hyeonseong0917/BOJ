#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=60*4;
char board[MAX][MAX];
int N=0;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
string str="";
void Input(){
	cin>>N;
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]='#';
		}
	}
	cin>>str;
}
int turn_dir(char dir, int cur_dir){
	if(dir=='L'){
		--cur_dir;
		if(cur_dir==-1){
			cur_dir=3;
		}
	}else{
		++cur_dir;
		if(cur_dir==4){
			cur_dir=0;
		}
	}
	return cur_dir;
}
void solve(){
	int minY=55;
	int minX=55;
	int maxY=55;
	int maxX=55;
	int cy=55,cx=55;
	board[cy][cx]='.';
	int d=2;
	for(int i=0;i<str.size();++i){
		char c=str[i];
		if(c=='F'){
			minY=min(minY,cy);
			minX=min(minX,cx);
			maxY=max(maxY,cy);
			maxX=max(maxX,cx);
			cy+=dy[d];
			cx+=dx[d];
			board[cy][cx]='.';
			minY=min(minY,cy);
			minX=min(minX,cx);
			maxY=max(maxY,cy);
			maxX=max(maxX,cx);
		}else{
			d=turn_dir(c,d);
		}
	}
	// cout<<minY<<" "<<minX<<" "<<maxY<<" "<<maxX<<endl;
	for(int i=minY;i<=maxY;++i){
		for(int j=minX;j<=maxX;++j){
			cout<<board[i][j];
		}cout<<"\n";
	}
}



int main() {
	// your code goes here
	Input();
	solve();
}