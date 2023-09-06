#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX=10000+1;
long long arr[MAX];
int main() {
	// your code goes here
	int N=0;
	cin>>N;
	long long max_num=-1;
	for(int i=0;i<N;++i){
		cin>>arr[i];
		max_num=max(max_num,arr[i]);
	}	
	long long total=0;
	cin>>total;
	int L=0;
	int R=max_num;
	long long ans=0;
	while(L<=R){
		long long mid=(L+R)/2;
		long long sum=0;
		for(int i=0;i<N;++i){
			if(arr[i]>mid){
				sum+=mid;
			}else{
				sum+=arr[i];
			}
		}
		if(sum>total){
			R=mid-1;
		}else{
			L=mid+1;
			ans=max(ans,mid);
		}
		// cout<<L<<" "<<R<<" "<<sum<<endl;
	}
	cout<<ans;	
	return 0;
}