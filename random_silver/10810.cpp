#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


vector<int> ans;
const int MAX=100+1;
int arr[MAX];
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(int i=0;i<MAX;++i){
		arr[i]=0;
	}
	int N,M;
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b,c;
		cin>>a>>b>>c;
		for(int j=a;j<=b;++j){
			arr[j]=c;
		}
	}
	for(int i=1;i<=N;++i){
		cout<<arr[i]<<" ";
	}
	return 0;
}