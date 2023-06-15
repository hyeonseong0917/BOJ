#include <iostream>
using namespace std;

const int MAX=1000+1;
char board[MAX][MAX];
int N=0;
//355
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
int main() {
	// your code goes here
	
	cin>>N;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
	// cout<<board[1][2]<<endl;
	int hy=0, hx=0;
	bool flag=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			// cout<<board[i][j];
			if(board[i][j]=='*'){
				hy=i;
				hx=j;
				flag=1;
				break;
			}
		}
		if(flag==1){
			break;
		}
	}
	++hy;
	cout<<hy+1<<" "<<hx+1<<endl;
	int cy=0, cx=0;
	int left_arm=0;
	cy=hy;
	cx=hx;
	while(1){
		--cx;
		if(!isRange(cy,cx)){
			break;
		}
		if(board[cy][cx]=='*'){
			++left_arm;
		}else{
			break;
		}
	}
	cout<<left_arm<<" ";
	
	int right_arm=0;
	cy=hy;
	cx=hx;
	while(1){
		++cx;
		if(!isRange(cy,cx)){
			break;
		}
		if(board[cy][cx]=='*'){
			++right_arm;
		}else{
			break;
		}
	}
	cout<<right_arm<<" ";
	
	int body_size=0;
	cy=hy;
	cx=hx;
	while(1){
		++cy;
		if(!isRange(cy,cx)){
			break;
		}
		if(board[cy][cx]=='*'){
			++body_size;
		}else{
			break;
		}
	}
	cout<<body_size<<" ";
	
	int left_leg=1;
	int left_y=cy;
	int left_x=cx-1;
	while(1){
		++left_y;
		if(!isRange(left_y,left_x)){
			break;
		}
		if(board[left_y][left_x]=='*'){
			++left_leg;
		}else{
			break;
		}
	}
	cout<<left_leg<<" ";
	
	int right_leg=1;
	int right_y=cy;
	int right_x=cx+1;
	while(1){
		++right_y;
		if(!isRange(right_y,right_x)){
			break;
		}
		if(board[right_y][right_x]=='*'){
			++right_leg;
		}else{
			break;
		}
	}
	cout<<right_leg;
	return 0;
}