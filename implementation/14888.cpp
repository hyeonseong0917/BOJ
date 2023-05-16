#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N=0;
int ADD,SUB,MUL,DIV=0;
const int MAX=100+1;
int arr[MAX]={0,};
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	cin>>ADD>>SUB>>MUL>>DIV;
}
int maxNum=-(1000000000+1), minNum=1000000000+1;
void dfs(int a, int s, int m, int d, int idx, int res){
	if(idx==N+1){
		return;
	}
	if(a==0 && s==0 && m==0 && d==0){
		maxNum=max(maxNum,res);
		minNum=min(minNum,res);
		return;
	}
	if(a>0){
		// cout<<"hello";
		dfs(a-1,s,m,d,idx+1,res+arr[idx+1]);
	}
	if(s>0){
		// cout<<"hello";
		dfs(a,s-1,m,d,idx+1,res-arr[idx+1]);
	}
	if(m>0){
		dfs(a,s,m-1,d,idx+1,res*arr[idx+1]);
	}
	if(d>0){
		// cout<<"hello";
		dfs(a,s,m,d-1,idx+1,res/arr[idx+1]);
	}
	
}

int main() {
	// your code goes here
	Input();
	dfs(ADD,SUB,MUL,DIV,0,arr[0]);
	cout<<maxNum<<endl;
	cout<<minNum<<endl;
	return 0;
}