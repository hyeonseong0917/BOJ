#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

//1038
int main() {
	// your code goes here
	int N,L=0;
	vector<int> arr; //높이
	cin>>N>>L;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	for(int i=0;i<N;++i){
		if(arr[i]<=L){
			++L;
		}
	}
	cout<<L;
	
	return 0;
}