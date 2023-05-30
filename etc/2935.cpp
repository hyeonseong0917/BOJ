#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string A;
	string B;
	char c;
	cin>>A;
	cin>>c;
	cin>>B;
	if(c=='+'){
		if(A.size()>B.size()){
			A[A.size()-B.size()]='1';
			cout<<A<<endl;
		}else if(A.size()<B.size()){
			B[B.size()-A.size()]='1';
			cout<<B<<endl;
		}else{
			A[0]='2';
			cout<<A<<endl;
		}
	}else{
		for(int i=0;i<B.size()-1;++i){
			A+='0';
		}
		cout<<A<<endl;
	}
	return 0;
}