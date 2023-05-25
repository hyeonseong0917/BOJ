#include <iostream>
using namespace std;
//1237
const int MAX=1000+1;
int N;
int board[365+1];
void Input(){
	for(int j=0;j<365+1;++j){
		board[j]=0;
	}
	
	cin>>N;
	for(int i=0;i<N;++i){
		int S,E=0;
		cin>>S>>E;
		for(int j=S;j<=E;++j){
			++board[j];
		}
	}
	int sum=0;
	int max_seg=1;
	int cur_start=-1;
	for(int i=1;i<=365;++i){
		if(board[i]==0 && cur_start!=-1){
			sum+=(i-cur_start)*max_seg;
			// cout<<sum<<endl;
			max_seg=1;
			cur_start=-1;
		}else if(board[i]>0){
			if(cur_start==-1){
				cur_start=i;
			}
			max_seg=max(max_seg,board[i]);
		}
	}
	if(cur_start!=-1){
		sum+=(365-cur_start+1)*max_seg;
	}
	// for(int i=1;i<=13;++i){
	// 	cout<<board[i]<<" ";
	// }
	
	cout<<sum;
}
int main() {
	// your code goes here
	Input();
	return 0;
}