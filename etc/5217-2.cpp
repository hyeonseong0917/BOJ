#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	int cnt=1;
	while(t--){
		int a=0;
		cin>>a;
		if(a==2 || a==1){
			cout<<"Pairs for "<<a<<":"<<"\n";
			++cnt;
			continue;
		}
		cout<<"Pairs for "<<a<<": ";
		for(int i=1;i<=a/2;++i){
			if(i*2==a){
				break;
			}
			cout<<i<<" "<<a-i;
			if((i+1)*2<a){
				cout<<", ";
			}
		}
		cout<<"\n";
		++cnt;
	}
	return 0;
}