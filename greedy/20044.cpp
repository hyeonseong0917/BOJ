#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> v;

int main() {
	// your code goes here
	int N;
	cin>>N;
	for(int i=0;i<N*2;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int sum=1222232421;
	for(int i=0;i<v.size()/2;++i){
		sum=min(sum,v[i]+v[v.size()-i-1]);
	}
	cout<<sum;
	return 0;
}