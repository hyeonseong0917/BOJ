#include <iostream>
using namespace std;

const int MAX=600+1;
int B[MAX][MAX];
int H,W,X,Y;
void Input(){
	cin>>H>>W>>X>>Y;
	for(int i=0;i<H+X;++i){
		for(int j=0;j<W+Y;++j){
			cin>>B[i][j];
		}
	}
}
void solve(){
	for(int i=X;i<H;++i){
		for(int j=Y;j<W;++j){
			if(B[i][j]==0){
				break;
			}
			B[i][j]-=B[i-X][j-Y];
		}
	}
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			cout<<B[i][j]<<" ";
		}cout<<endl;
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}