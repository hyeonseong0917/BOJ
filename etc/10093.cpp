#include <iostream>
#include <map>
using namespace std;

int main() {
	// your code goes here
	long long a,b;
	cin>>a>>b;
	long long minNum=min(a,b);
	long long maxNum=max(a,b);
	if(maxNum==minNum){
		cout<<0;
	}else{
		cout<<maxNum-minNum-1<<endl;
		for(long long i=minNum+1;i<maxNum;++i){
			cout<<i<<" ";
		}	
	}
	
	
	
	return 0;
}