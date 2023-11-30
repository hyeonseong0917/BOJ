#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

const int MAX=100+1;
int arr[MAX];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(int i=0;i<MAX;++i){
		arr[i]=i;
	}
	int N,M;
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		int tmp=arr[a];
		arr[a]=arr[b];
		arr[b]=tmp;
	}
	for(int i=1;i<=N;++i){
		cout<<arr[i]<<" ";
	}
	return 0;
}