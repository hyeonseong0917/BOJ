#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000000+2];
int cur_arr[1000000+2];
int main() {
	// your code goes here
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
		cur_arr[i]=0;
	}
    arr[N]=0;
    arr[N+1]=0;
	int cnt=0;
	for(int i=0;i<N;++i){
		if(arr[i]!=cur_arr[i]){
			++cnt;
			cur_arr[i]=1-cur_arr[i];
			cur_arr[i+1]=1-cur_arr[i+1];
			cur_arr[i+2]=1-cur_arr[i+2];
		}
	}
	cout<<cnt;
	return 0;
}