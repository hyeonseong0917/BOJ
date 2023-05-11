#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a=0;
	cin>>a;
	while(a--){
		int x,y;
		cin>>x>>y;
		if(x<y){
			cout<<"NO BRAINS"<<endl;
		}else{
			cout<<"MMM BRAINS"<<endl;
		}
	}
	return 0;
}