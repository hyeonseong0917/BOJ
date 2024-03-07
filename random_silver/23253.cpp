#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int M,N;
	cin>>N>>M;
	bool flag=0;
	for(int i=0;i<M;++i){
		int K=0;
		cin>>K;
		int tmp_num=-1;
		
		for(int j=0;j<K;++j){
			int a=0;
			cin>>a;
			if(tmp_num==-1){
				tmp_num=a;
				continue;
			}
			if(tmp_num<a){
				flag=1;
			}
			tmp_num=a;
		}
		
	}
	if(flag){
		cout<<"No";
	}else{
		cout<<"Yes";
	}
	return 0;
}