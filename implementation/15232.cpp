#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=1000+1;
int arr[MAX];
int Time[MAX];
int main() {
	// your code goes here
	int N=0;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	for(int i=0;i<N;++i){
		Time[i]=0;
	}
	int cnt=0;
	while(1){
		bool flag=0;
		for(int i=0;i<N;++i){
			if(arr[i]!=0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			break;
		}
		for(int i=0;i<N;++i){
			if(arr[i]>0){
				--arr[i];
				++cnt;
				if(arr[i]==0){
					Time[i]=cnt;
				}
			}
		}
	}
	for(int i=0;i<N;++i){
		cout<<Time[i]<<" ";
	}
	return 0;
}