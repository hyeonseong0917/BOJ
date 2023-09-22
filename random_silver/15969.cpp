#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N=0;
	cin>>N;
	vector<int> v;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	cout<<v[v.size()-1]-v[0];
	return 0;
}