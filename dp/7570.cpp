#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N=0;
int d[1000000+1]; //d[a]는 a를 마지막 수로 갖는 연속lis의 길이
int res=-1;
void solve(){
	cin>>N;
	for(int i=0;i<1000000+1;++i){
		d[i]=0;
	}
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		d[a]=d[a-1]+1;
		res=max(res,d[a]);
	}
	
	cout<<N-res;
	
}


int main() {
	// your code goes here
	solve();
	return 0;
}