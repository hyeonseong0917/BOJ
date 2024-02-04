#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int N,K;
const int MAX=50+1;
int board[MAX][MAX];
void Input(){
	cin>>N>>K;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
int ans=122232421;
void pick(int K){
	if(K==0){
		int y=0, x=0, pos=0;
		int cnt=0;
		while(1){
			// cout<<y<<" "<<x<<" "<<pos<<endl;
			if(y==N-1 && x==N-1){
				if(board[y][x]==2 || board[y][x]==5){
					if(board[y][x]==2){
						if(pos==1){
							++cnt;
							ans=min(ans,cnt);
						}
					}else{
						if(pos==0){
							++cnt;
							ans=min(ans,cnt);
						}
					}
				}
				break;
			}
			if(board[y][x]==0){
				if(pos==3 || pos==2){
					if(pos==3){
						x+=1;
						pos=0;
						if(!isRange(y,x)){
							break;
						}
					}else{
						y+=1;
						pos=1;
						if(!isRange(y,x)){
							break;
						}
					}
				}else{
					break;
				}
			}else if(board[y][x]==1){
				if(pos==3 || pos==0){
					if(pos==3){
						x-=1;
						pos=2;
						if(!isRange(y,x)){
							break;
						}
					}else{
						y+=1;
						pos=1;
						if(!isRange(y,x)){
							break;
						}
					}
				}else{
					break;
				}
			}else if(board[y][x]==2){
				if(pos==1 || pos==2){
					if(pos==1){
						x+=1;
						pos=0;
						if(!isRange(y,x)){
							break;
						}
					}else{
						y-=1;
						pos=3;
						if(!isRange(y,x)){
							break;
						}
					}
				}else{
					break;
				}
			}else if(board[y][x]==3){
				if(pos==0 || pos==1){
					if(pos==0){
						y-=1;
						pos=3;
						if(!isRange(y,x)){
							break;
						}
					}else{
						x-=1;
						pos=2;
						if(!isRange(y,x)){
							break;
						}
					}
				}else{
					break;
				}
			}else if(board[y][x]==4){
				if(pos==1 || pos==3){
					if(pos==1){
						y+=1;
						pos=1;
						if(!isRange(y,x)){
							break;
						}
					}else{
						y-=1;
						pos=3;
						if(!isRange(y,x)){
							break;
						}
					}
				}else{
					break;
				}
			}else if(board[y][x]==5){
				if(pos==0 || pos==2){
					if(pos==0){
						x+=1;
						pos=0;
						if(!isRange(y,x)){
							break;
						}
					}else{
						x-=1;
						pos=2;
						if(!isRange(y,x)){
							break;
						}
					}
				}else{
					break;
				}
			}
			++cnt;
		}
		return;
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			for(int k=0;k<6;++k){
				if(board[i][j]!=k){
					int tmp=board[i][j];
					board[i][j]=k;
					pick(K-1);
					board[i][j]=tmp;
				}
			}
		}
	}
}
void solve(){
	pick(K);
	if(ans==122232421){
		cout<<-1;
	}else{
		cout<<ans;
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