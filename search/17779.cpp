#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N=0;
const int MAX=20+1;
int board[MAX][MAX]={0,};
int check[MAX][MAX]={0,};
//x,y,d1,d2
vector<pair<pair<int,int>, pair<int,int>>> v;

bool isRange(int x, int y){
	return (x>=1 && y>=1 && y<=N && x<=N);
}
int minNum=122232421;

void solve(){
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			check[i][j]=0;
		}
	}
	int x=v[0].first.first;
	int y=v[0].first.second;
	int d1=v[0].second.first;
	int d2=v[0].second.second;
	int nx=x;
	int ny=y;
	for(int i=0;i<=d1;++i){
		nx=x+i;
		ny=y-i;
		
		if(isRange(nx,ny)){
			check[nx][ny]=5;
			continue;
		}else{
			nx-=i;
			ny+=i;
			break;
		}
	}
	for(int i=0;i<=d2;++i){
		nx=x+i;
		ny=y+i;
		
		if(isRange(nx,ny)){
			check[nx][ny]=5;
			continue;
		}else{
			nx-=i;
			ny+=i;
			break;
		}
	}
	int cx=x+d1;
	int cy=y-d1;
	for(int i=0;i<=d2;++i){
		int nx=cx+i;
		int ny=cy+i;
		if(isRange(nx,ny)){
			check[nx][ny]=5;
		}else{
			break;
		}
	}
	cx=x+d2;
	cy=y+d2;
	for(int i=0;i<=d1;++i){
		int nx=cx+i;
		int ny=cy-i;
		if(isRange(nx,ny)){
			check[nx][ny]=5;
		}else{
			break;
		}
	}
	for(int i=1;i<x+d1;++i){
		
		for(int j=1;j<=y;++j){
			if(check[i][j]!=0){
				break;
			}
			check[i][j]=1;
		}
	}
	for(int i=1;i<=x+d2;++i){
		bool flag=0;
		for(int j=y+1;j<=N;++j){
			if(check[i][j]==5){
				flag=1;
				continue;
			} 
			if(flag==1){
				check[i][j]=2;	
			}
			
		}
		if(flag==0){
			for(int j=y+1;j<=N;++j){
				check[i][j]=2;
			}
		}
	}
	for(int i=x+d1;i<=N;++i){
		for(int j=1;j<y-d1+d2;++j){
			if(check[i][j]==5) break;
			check[i][j]=3;
		}
	}
	for(int i=x+d2+1;i<=N;++i){
		bool flag=0;
		for(int j=y-d1+d2;j<=N;++j){
			if(check[i][j]==5){
				flag=1;
				continue;
			} 
			if(flag){
				check[i][j]=4;	
			}
			
		}
		if(flag==0){
			for(int j=y-d1+d2;j<=N;++j){
				check[i][j]=4;
			}
		}
	}
	
	
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(check[i][j]==0){
				check[i][j]=5;
			}
		}
	}
	vector<int> A(6,0);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			A[check[i][j]]+=board[i][j];
		}
	}
	sort(A.begin(), A.end());
	minNum=min(minNum,A[5]-A[1]);
	// for(int i=1;i<=N;++i){
	// 	for(int j=1;j<=N;++j){
	// 		cout<<check[i][j];
	// 	}cout<<endl;
	// }
	// cout<<endl;
	
}
//x, y, d1, d2 
void pick(){
	for(int i=1;i<=N;++i){ //x
		for(int j=1;j<=N;++j){ //y
			for(int m=1;m<=N;++m){ //d1
				for(int n=1;n<=N;++n){ //d2
					
					
					if(i+m+n<=N && j-m>=1 && j+n<=N){
						
						if(!v.empty()){
							v.clear();	
						}
						v.push_back({{i,j},{m,n}});
						solve();
						// if(i==3 && j==3 && m==1 && n==1){
								
						// }
						
						
						
						// solve();
						
					}
				}
			}
		}
	}
}

void Input(){
	cin>>N;
	// v.push_back({{4,3},{1,1}});
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>board[i][j];
		}
	}
}


int main() {
	// your code goes here
	Input();
	pick();
	cout<<minNum;
	return 0;
}