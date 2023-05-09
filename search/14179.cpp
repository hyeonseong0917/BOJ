#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H,W=0;
int board[500+1][500+1];
bool visited[500+1][500+1];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<int> height;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<H && x<W);
}
void Input(){
	cin>>H>>W;
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			board[i][j]=0;
		}
	}
	for(int i=0;i<W;++i){
		int a=0;
		cin>>a;
		height.push_back(a);
	}
}
void blockFill(){
	for(int i=0;i<W;++i){
		int cur_h=height[i];
		int cnt=0;
		for(int j=H-1;j>=0;--j){
			if(cnt==cur_h){
				break;
			}
			board[j][i]=1;
			++cnt;
			
		}
	}
}
int res=0;
void rainFill(){
	for(int i=H-1;i>=0;--i){
		for(int j=1;j<W-1;++j){
			// if(i==2&&j==3){
			// 		cout<<"he";
			// 	}
			if(board[i][j]==0 && !visited[i][j]){
				// cout<<i<<" "<<j<<endl;
				int y=i;
				int x=j;
				visited[y][x]=1;
				bool firstFlag=0;
				bool finalFlag=0;
				
				if(x==1){
					if(board[y][0]!=1){
						
						firstFlag=1;
					}
				}
				
				// if(firstFlag==1){
				// 	continue;
				// }
				vector<pair<int,int>> v;
				v.push_back({y,x});
				
				while(1){
					x+=1;
					if(board[y][x]==1){
						break;
					}
					if(x==W-1){
						finalFlag=1;
						break;
					}
					visited[y][x]=1;
					v.push_back({y,x});
				}
				
				if(firstFlag==1 || finalFlag==1){
					continue;	
				}
				res+=v.size();
				// for(int k=0;k<v.size();++k){
				// 	cout<<v[k].first<<" "<<v[k].second<<endl;
				// }
				
				
			}
		}
	}
}
int main() {
	// your code goes here
	Input();
	blockFill();
	// for(int i=0;i<H;++i){
	// 	for(int j=0;j<W;++j){
	// 		cout<<board[i][j]<<" ";
	// 	}cout<<endl;
	// }
	rainFill();
	cout<<res;
	return 0;
}