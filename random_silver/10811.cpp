#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int arr[100+1];
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	
	for(int i=1;i<=N;++i){
		arr[i]=i;
	}
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		vector<int> v;
		for(int j=a;j<=b;++j){
			v.push_back(arr[j]);
		}
		reverse(v.begin(),v.end());
		for(int j=0;j<v.size();++j){
			arr[a+j]=v[j];
		}
	}
	for(int i=1;i<=N;++i){
		cout<<arr[i]<<" ";
	}


	return 0;
}