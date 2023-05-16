#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,d=0;
const int MAX=500+1;
int board[MAX][MAX];
vector<int> vert,horizon,prime,sub;
void vectorInit(){
	vert.clear();
	horizon.clear();
	prime.clear();
	sub.clear();
	for(int i=0;i<n;++i){
		prime.push_back(board[i][i]);
	}
	for(int i=0;i<n;++i){
		sub.push_back(board[i][n-1-i]);
	}
	for(int i=0;i<n;++i){
		vert.push_back(board[i][n/2]);
	}
	for(int i=0;i<n;++i){
		horizon.push_back(board[n/2][i]);
	}
}
void rightClock(){
	vectorInit();
	for(int i=0;i<n;++i){
		board[i][i]=horizon[i];
	}
	for(int i=0;i<n;++i){
		board[i][n-1-i]=vert[i];
	}
	for(int i=0;i<n;++i){
		board[i][n/2]=prime[i];
	}
	for(int i=0;i<n;++i){
		board[n/2][i]=sub[n-1-i];
	}
	
}
void leftClock(){
	vectorInit();
	for(int i=0;i<n;++i){
		board[i][i]=vert[i];
	}
	for(int i=0;i<n;++i){
		board[i][n-1-i]=horizon[n-i-1];
	}
	for(int i=0;i<n;++i){
		board[i][n/2]=sub[i];
	}
	for(int i=0;i<n;++i){
		board[n/2][i]=prime[i];
	}
	
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				board[i][j]=0;
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>board[i][j];
			}
		}
		if(d>0){
			for(int i=0;i<d/45;++i){
				rightClock();
			}
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					cout<<board[i][j]<<" ";
				}cout<<endl;
			}
		}else{
			for(int i=0;i<(d*-1)/45;++i){
				leftClock();
			}
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					cout<<board[i][j]<<" ";
				}cout<<endl;
			}
		}
	}
	return 0;
}