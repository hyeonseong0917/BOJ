#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	
	vector<int> v;
	for(int i=0;i<3;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<3;++i){
		cout<<v[i]<<" ";
	}
	return 0;
}