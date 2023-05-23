#include <iostream>
#include <map>
#include <math.h>
using namespace std;

//1336
char l,r;
string ans;
string board[3+1];
bool check[26+1]; //자음이면 check[i]=1
map<char,pair<int,int>> m;
int taxi_dist(pair<int,int> a, pair<int,int> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
void Input(){
	cin>>l>>r;
	cin>>ans;
	board[0]="qwertyuiop";
	board[1]="asdfghjkl";
	board[2]="zxcvbnm";
	for(int i=0;i<3;++i){
		for(int j=0;j<10;++j){
			if(board[i][j]!=' '){
				m[board[i][j]]={i,j};
			}
		}
	}
	
	for(int i=0;i<3;++i){
		for(int j=0;j<5;++j){
			if(i==2 && j==4){
				continue;
			}
			check[board[i][j]-'a']=1;
		}
	}
	// for(int i=0;i<3;++i){
	// 	for(int j=0;j<10;++j){
	// 		cout<<check[board[i][j]-'a'];
	// 	}cout<<endl;
	// }
}
void solve(){
	int sum=0;
	for(int i=0;i<ans.size();++i){
		pair<int,int> target_pos=m[ans[i]];
		pair<int,int> cur_pos;
		if(check[ans[i]-'a']==1){
			cur_pos=m[l];
			l=ans[i];
		}else{
			cur_pos=m[r];
			r=ans[i];
		}
		// cout<<target_pos.first<<" "<<target_pos.second<<endl;
		// cout<<cur_pos.first<<" "<<cur_pos.second<<endl;
		int dist=taxi_dist(cur_pos,target_pos);
		// cout<<dist<<endl;
		sum+=(dist+1);
	}
	cout<<sum;
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}