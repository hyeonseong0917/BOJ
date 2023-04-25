#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

//1445
int N=0;
int dir=0;
int dy[4]={0,1,0,-1};
int dx[4]={-1,0,1,0};
const int MAX=500+1;
int board[MAX][MAX];
int order[MAX][MAX];
map<int,pair<int,int>> m;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
void order_init(){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			order[i][j]=0;
		}
	}
	int curY=N/2;
	int curX=N/2;
	
	int step=0;
	int cnt=0;
	int a=1;
	int t=0;
	while(1){
		
		if(curY==0 && curX==0){
			break;
		}
		
		if(cnt%4==0){
			++step;
		}else{
			if(cnt%2==0){
				++step;
			}
		}
		
		int curStep=step;
		// cout<<curStep<<endl;
		while(curStep--){
			curY+=dy[dir%4];
			curX+=dx[dir%4];
			if(!isRange(curY,curX)){
				curY-=dy[dir%4];
				curX-=dx[dir%4];
				break;
			}
			order[curY][curX]=a++;	
		}
		++dir;
		++cnt;
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			m[order[i][j]]={i,j};
		}
	}
}

int move(int cnt){
	int y=m[cnt].first;
	int x=m[cnt].second;
	//board[y][x]에서 발생
	int ny=m[cnt+1].first;
	int nx=m[cnt+1].second;
	int dir=0;
	for(int i=0;i<4;++i){
		int cy=y+dy[i];
		int cx=x+dx[i];
		if(cy==ny && cx==nx){
			dir=i;
			break;
		}
	}
	// cout<<dir<<endl;
	int cur_sand=board[ny][nx];
	board[ny][nx]=0;
	int sum=0;
	int to_minus=0;
	// cout<<ny<<" "<<nx<<endl;
	int vert_dir[2]={0,0};
	int ay=0, ax=0;
	
	if(dir%2==0){
		vert_dir[0]=1;
		vert_dir[1]=3;
	}else{
		vert_dir[0]=0;
		vert_dir[1]=2;
	}
	// cout<<vert_dir[0]<<endl;
	for(int i=0;i<4;++i){
		if(i==0){
			for(int j=0;j<2;++j){
				int cy=y+dy[vert_dir[j]];
				int cx=x+dx[vert_dir[j]];
				// cout<<cy<<" "<<cx<<endl;
				if(isRange(cy,cx)){
					board[cy][cx]+=cur_sand*0.01;
				}else{
					sum+=cur_sand*0.01;
				}
				to_minus+=cur_sand*0.01;
			}
			y+=dy[dir];
			x+=dx[dir];
		}else if(i==1){
			for(int j=0;j<2;++j){
				int cy=y+dy[vert_dir[j]];
				int cx=x+dx[vert_dir[j]];
				if(isRange(cy,cx)){
					board[cy][cx]+=cur_sand*0.07;
				}else{
					sum+=cur_sand*0.07;
				}
				to_minus+=cur_sand*0.07;
				int cny=cy+dy[vert_dir[j]];
				int cnx=cx+dx[vert_dir[j]];
				if(isRange(cny,cnx)){
					board[cny][cnx]+=cur_sand*0.02;
				}else{
					sum+=cur_sand*0.02;
				}
				to_minus+=cur_sand*0.02;
			}
			y+=dy[dir];
			x+=dx[dir];
		}else if(i==2){
			ay=y;
			ax=x;
			
			for(int j=0;j<2;++j){
				int cy=y+dy[vert_dir[j]];
				int cx=x+dx[vert_dir[j]];
				if(isRange(cy,cx)){
					board[cy][cx]+=cur_sand*0.1;
				}else{
					sum+=cur_sand*0.1;
				}
				to_minus+=cur_sand*0.1;
				
			}
			y+=dy[dir];
			x+=dx[dir];
		}else if(i==3){
			if(isRange(y,x)){
				board[y][x]+=cur_sand*0.05;	
			}else{
				sum+=cur_sand*0.05;
			}
			to_minus+=cur_sand*0.05;
			
		}
	}
	if(isRange(ay,ax)){
		board[ay][ax]+=(cur_sand-to_minus);	
	}else{
		sum+=(cur_sand-to_minus);
	}
	
	
	return sum;
}
int solve(){
	int cnt=0;
	int res=0;
	int dir=0;
	while(cnt<(N*N)-1){
		res+=move(cnt);
		++cnt;
	}
	return res;
}

int main() {
	// your code goes here
	Input();
	order_init();
	cout<<solve();
	
	return 0;
}