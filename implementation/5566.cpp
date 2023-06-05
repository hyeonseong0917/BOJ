#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int N,M=0;
	cin>>N>>M;
	vector<int> v;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	int idx=0;
	int res=-1;
	for(int i=0;i<M;++i){
		int a=0;
		cin>>a;
		idx+=a;
		idx+=v[idx];
		if(idx>=N-1){
			res=i+1;
			cout<<res;
			break;
		}
	}
	if(res==-1){
		cout<<M;
	}
	return 0;
}