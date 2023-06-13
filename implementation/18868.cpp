#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int board[10+1][100+1];
//1653
int main() {
	// your code goes here
	int M,N;
	cin>>M>>N;
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
	int cnt=0;
	for(int i=0;i<M;++i){
		//i번째 우주에 대해
		for(int j=i+1;j<M;++j){
			//j번째 우주는 어떤데?
			bool is_same=1;
			for(int x=0;x<N-1;++x){
				//i번째 우주와 j번째 우주의 x번째 값에 대해
				for(int y=x+1;y<N;++y){
					//y번째 값의 대소가 동일한지?
					if(board[i][x]<board[i][y]){
						if(!(board[j][x]<board[j][y])){
							is_same=0;
							
						}
					}else if(board[i][x]==board[i][y]){
						if(!(board[j][x]==board[j][y])){
							is_same=0;
							
						}
					}else if(board[i][x]>board[i][y]){
						if(!(board[j][x]>board[j][y])){
							is_same=0;
							
						}
					}
					if(is_same==0){
						break;
					}
				}
				if(is_same==0){
					break;
				}
			}
			if(is_same==1){
				++cnt;
			}
		}
		
	}
	cout<<cnt;
	return 0;
}