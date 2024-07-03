#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int p;
		cin>>p;
		int val=-1;
		string name;
		for(int i=0;i<p;++i){
			int a;
			cin>>a;
			string s;
			cin>>s;
			if(val<a){
				name=s;
				val=a;
			}
		}
		cout<<name<<endl;
	}
	return 0;
}