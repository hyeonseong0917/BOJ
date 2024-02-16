#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

int N,R,C;
int cnt=0;
int ans=0;
void Z(int y, int x, int cur_num){
	if(y==R && x==C){
		ans=cnt;
		return;
	}else if(R<y+cur_num && R>=y && C<x+cur_num && C>=x){
		Z(y,x,cur_num/2);	
		Z(y,x+cur_num/2,cur_num/2);
		Z(y+cur_num/2,x,cur_num/2);
		Z(y+cur_num/2,x+cur_num/2,cur_num/2);	
	}else{
		cnt+=cur_num*cur_num;
	}
	
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>R>>C;
	Z(0, 0, (int)pow(2,N));
	cout<<ans;
	return 0;
}