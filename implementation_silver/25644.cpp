#include <iostream>
#include <vector>
using namespace std;

const int MAX=200000+1;
int a[MAX];
int b[MAX];

int main() {
	// your code goes here
	int N=0;
	cin>>N;
	int ans=0;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	int pre_num=0;
	for(int i=N-1;i>=0;--i){
		if(a[i]>pre_num){
			pre_num=a[i];
		}
		b[i]=pre_num;
	}
	for(int i=0;i<N;++i){
		ans=max(ans,b[i]-a[i]);
	}
	cout<<ans;
	return 0;
}