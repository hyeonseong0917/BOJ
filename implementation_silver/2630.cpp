#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int N=0;
const int MAX=128+1;
int board[MAX][MAX];
bool is_all_white=1;
bool is_all_blue=1;
int ans=0;
void Input(){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]=0;
		}
	}
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];	
		}
	}
}
void solve(){
	//모두 0인경우
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(board[i][j]!=0){
				is_all_white=false;
				break;
			}
		}
	}
	//모두 1인경우
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(board[i][j]!=1){
				is_all_blue=false;
				break;
			}
		}
	}
	if(is_all_blue || is_all_white){
		if(is_all_blue){
			cout<<0<<"\n";
			cout<<1;
		}else{
			cout<<1<<"\n";
			cout<<0;
		}
		
		return;
	}
	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({{0,0},{(N/2)-1,(N/2)-1}});
	q.push({{0,N/2},{(N/2)-1,N-1}});
	q.push({{N/2,0},{N-1,(N/2)-1}});
	q.push({{N/2,N/2},{N-1,N-1}});
	int white_cnt=0;
	int blue_cnt=0;
	int k=0;
	while(!q.empty()){
		// ++k;
		// if(k==30){
		// 	break;
		// }
		int ly=q.front().first.first;
		int lx=q.front().first.second;
		int ry=q.front().second.first;
		int rx=q.front().second.second;
		// cout<<ly<<" "<<lx<<" "<<ry<<" "<<rx<<endl;
		q.pop();
		//(ly,lx)에서(ry,rx)구간까지 모두 같은 색이거나 1*1인지?
		bool flag=0;
		if(ly==ry && lx==rx){
			if(board[ly][lx]==0){
				white_cnt+=1;
			}else{
				blue_cnt+=1;
			}
			flag=1;
		}
		if(flag==1){
			continue;
		}
		// 1. 모두 같은 색인가?
		bool can_cut=0;
		bool is_white=1;
		bool is_blue=1;
		for(int i=ly;i<=ry;++i){
			for(int j=lx;j<=rx;++j){
				if(board[i][j]==1){
					is_white=0;
					break;
				}
			}
		}
		for(int i=ly;i<=ry;++i){
			for(int j=lx;j<=rx;++j){
				if(board[i][j]==0){
					is_blue=0;
					break;
				}
			}
		}
		if(is_white || is_blue){
			if(is_white){
				white_cnt+=1;
			}else{
				blue_cnt+=1;
			}
		}else{
			//나누기
			int ps=(rx-lx+1)/2;
			q.push({{ly,lx},{ly+ps-1,lx+ps-1}});
			q.push({{ly,lx+ps},{ly+ps-1,rx}});
			q.push({{ly+ps,lx},{ry,lx+ps-1}});
			q.push({{ly+ps,lx+ps},{ry,rx}});
		}
	}
	cout<<white_cnt<<"\n";
	cout<<blue_cnt;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();	
	
	return 0;
}