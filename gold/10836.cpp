#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


int N,M;
const int MAX=700+1;
int board[MAX][MAX];
int to_add[MAX][MAX];
vector<int> v(MAX*2,0);
void Input(){
	cin>>M>>N;
	for(int i=0;i<M;++i){
		for(int j=0;j<M;++j){
			board[i][j]=1;
			to_add[i][j]=0;
		}
	}
	
	for(int i=0;i<N;++i){
		int a,b,c;
		cin>>a>>b>>c;
		for(int j=a;j<a+b;++j){
			v[j]+=1;
		}
		for(int j=a+b;j<a+b+c;++j){
			v[j]+=2;
		}
	}
}
void solve(){
	for(int i=0;i<M;++i){
		board[M-i-1][0]+=v[i];
	}
	for(int i=M;i<2*M -1;++i){
		board[0][i-M+1]+=v[i];
	}
	for(int i=1;i<M;++i){
		for(int j=1;j<M;++j){
			board[i][j]+=v[M+j-1];
		}
	}
	for(int i=0;i<M;++i){
		for(int j=0;j<M;++j){
			cout<<board[i][j]<<" ";
		}cout<<"\n";
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