#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	cout<<v[0]<<" "<<v[n-1];
	return 0;
}