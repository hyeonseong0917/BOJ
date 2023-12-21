// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <map>
// #include <queue>
// #include <cmath>
// using namespace std;


// string board[9+1];
// void Input(){
// 	for(int i=0;i<9;++i){
// 		cin>>board[i];
// 	}
// }
// map<string[9+1], int> m;

// bool flag=0;
// void pick(int y, int x,string tmp_board[9+1], bool cur_visited[9+1]){
// 	if(m[board]){
// 		return;
// 	}
// 	// cout<<y<<" "<<x<<endl;
// 	if(y==8 && x==8 && !flag){
// 		flag=1;
// 		for(int i=0;i<9;++i){
// 			for(int j=0;j<9;++j){
// 				cout<<board[i][j];
// 			}cout<<"\n";
// 		}
// 		// cout<<"he";
// 		return;
// 	}
// 	if(flag){
// 		return;
// 	}
// 	if(board[y][x]!='0'){
// 		if(!m[board]){
// 			m[board]=1;
// 			if(x+1>8){
// 				pick(y+1,0,tmp_board,cur_visited);
// 			}else{
// 				pick(y,x+1,tmp_board,cur_visited);
// 			}
// 		}
// 	}else{
// 		// string tmp_board[9+1];
// 		// bool cur_visited[9+1];
// 		for(int j=0;j<9;++j){
// 			tmp_board[j]=board[j];
// 		}
// 		for(int i=1;i<=9;++i){
// 			cur_visited[i]=0;
// 		}
// 		for(int i=0;i<9;++i){
// 			if(board[i][x]!='0'){
// 				cur_visited[board[i][x]-'0']=1;
// 			}
// 			if(board[y][i]!='0'){
// 				cur_visited[board[y][i]-'0']=1;
// 			}
// 		}
// 		int sy=y-(y%3);
// 		int sx=x-(x%3);
// 		for(int i=sy;i<sy+3;++i){
// 			for(int j=sx;j<sx+3;++j){
// 				if(board[i][j]!='0'){
// 					cur_visited[board[i][j]-'0']=1;
// 				}
// 			}
// 		}
// 		bool cf=0;
// 		for(int i=1;i<=9;++i){
// 			if(!cur_visited[i]){
// 				cf=1;
// 			}
// 		}
// 		if(!cf){
// 			return;
// 		}
// 		for(int i=1;i<=9;++i){
// 			if(!cur_visited[i]){
// 				cur_visited[i]=1;
// 				board[y][x]=(i+'0');
// 				if(!m[board]){
// 					m[board]=1;
// 					if(x+1>8){
// 						pick(y+1,0,tmp_board,cur_visited);
// 					}else{
// 						pick(y,x+1,tmp_board,cur_visited);
// 					}
// 				}
// 				cur_visited[i]=0;
// 				for(int j=0;j<9;++j){
// 					board[j]=tmp_board[j];
// 				}
// 			}
// 		}
// 	}
// }

// int main() {
// 	// your code goes here
// 	Input();
// 	string tmp_board[9+1];
//     bool cur_visited[9+1];
// 	pick(0,0,tmp_board,cur_visited);
// 	// solve();
	
// 	return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <unordered_set>
using namespace std;


string board[9+1];
bool col[10][10]; // col[i][j]: i번째 열에 j값이 존재하는지? 
bool row[10][10]; // row[i][j]: i번째 행에 j값이 존재하는지?
bool square[10][10][10]; // 사각형
void Input(){
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			for(int k=0;k<10;++k){
				square[i][j][k]=0;
			}
			col[i][j]=0;
			row[i][j]=0;
		}
	}
	for(int i=0;i<9;++i){
		cin>>board[i];
		for(int j=0;j<9;++j){
			if(board[i][j]!='0'){
				col[j][board[i][j]-'0']=1;
				row[i][board[i][j]-'0']=1;
				square[i-(i%3)][j-(j%3)][board[i][j]-'0']=1;
			}
		}
	}
}
bool flag=0;
void dfs(int y, int x){
	// cout<<y<<" "<<x<<endl;
	if(y==9 && x==0 && !flag){
		flag=1;
		for(int i=0;i<9;++i){
			cout<<board[i]<<"\n";
		}
		return;
	}
	if(flag){
		return;
	}
	// if(y==1 && x==0){
	// 	cout<<"he"<<endl;
	// }
	if(board[y][x]!='0'){

		if(x+1<=8){
			dfs(y,x+1);
		}else{
			dfs(y+1,0);
		}
	}else{
		for(int i=1;i<=9;++i){
			
			if(!col[x][i] && !row[y][i] && !square[y-(y%3)][x-(x%3)][i]){

				col[x][i]=1;
				row[y][i]=1;
				square[y-(y%3)][x-(x%3)][i]=1;
				board[y][x]=(i+'0');
				if(x+1<=8){
					dfs(y,x+1);
				}else{
					dfs(y+1,0);
				}		
				col[x][i]=0;
				row[y][i]=0;
				square[y-(y%3)][x-(x%3)][i]=0;
				board[y][x]='0';

			}
		}
	}
}

int main() {
	// your code goes here
	Input();
	dfs(0,0);
	// solve();
	
	return 0;
}