#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1240
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int dir=1;
int u=1,d=6,f=5,b=2,l=4,r=3;
int N,M,K=0;
const int MAX=21+1;
int board[MAX][MAX];
int y=0,x=0;

bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void Input(){
	cin>>N>>M>>K;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
}
void turn(int cur_dir){
	int tu=u,td=d,tf=f,tb=b,tl=l,tr=r;
	if(cur_dir==0){
		d=tb;
		f=td;
		u=tf;
		b=tu;
	}else if(cur_dir==1){
		d=tr;
		l=td;
		u=tl;
		r=tu;
	}else if(cur_dir==2){
		d=tf;
		b=td;
		u=tb;
		f=tu;
	}else if(cur_dir==3){
		d=tl;
		r=td;
		u=tr;
		l=tu;
	}
}
int cnt=1;
bool visited[MAX][MAX]={0,};
void dfs(int p, int q, int curNum){
	for(int i=0;i<4;++i){
		int np=p+dy[i];
		int nq=q+dx[i];
		if(!isRange(np,nq)){
			continue;	
		} 
		if(visited[np][nq]==1){
			continue;	
		} 
		if(curNum==board[np][nq]){
			// cout<<np<<" "<<nq<<" "<<endl;
			visited[np][nq]=1;
			++cnt;
			dfs(np,nq,curNum);
		}
	}
}
int sum=0;
void solve(){
	
	for(int i=0;i<K;++i){
		for(int j=0;j<N;++j){
			for(int k=0;k<M;++k){
				visited[j][k]=0;
			}
		}
		y+=dy[dir];
		x+=dx[dir];
		cnt=1;
		// cout<<dir<<" "<<d<<endl;
		if(!isRange(y,x)){
			y-=dy[dir];
			x-=dx[dir];
			if(dir==0){
				dir=2;
			}else if(dir==1){
				dir=3;
			}else if(dir==2){
				dir=0;
			}else if(dir==3){
				dir=1;
			}
			y+=dy[dir];
			x+=dx[dir];
		}
		// cout<<dir<<" "<<d<<endl;
		turn(dir);
		// cout<<dir<<" "<<d<<endl;
		// cout<<endl;
		visited[y][x]=1;
		//점수 획득
		int num=board[y][x];
		dfs(y,x,num);
		
		sum+=(cnt*board[y][x]);
		
		// cout<<sum<<endl;
		// if(sum==55){
		// 	cout<<d<<" "<<dir<<" "<<board[y][x]<<endl;
		// }
		
		if(d>board[y][x]){
			if(dir==0){
				dir=1;
			}else if(dir==1){
				dir=2;
			}else if(dir==2){
				dir=3;
			}else if(dir==3){
				dir=0;
			}
		}else if(d<board[y][x]){
			if(dir==0){
				dir=3;
			}else if(dir==1){
				dir=0;
			}else if(dir==2){
				dir=1;
			}else if(dir==3){
				dir=2;
			}
		}
		// if(sum==55){
		// 	cout<<y<<" "<<x<<" "<<dir<<endl;
		// 	return;
		// }
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	cout<<sum;
	return 0;
}