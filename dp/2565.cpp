#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX=500+1;
int dp[MAX];
int A[MAX];

int main() {
	// your code goes here
	int N=0;
	cin>>N;
	for(int i=0;i<MAX;++i){
		dp[i]=0;
		A[i]=0;
	}
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		A[a]=b;
		dp[a]=1;
	}
	int max_length=0; 
	// dp[x]: x인덱스를 마지막으로 가지는 가장 긴 LIS
	// x를 기준으로 이전 인덱스를 살펴봤을 때 A[x]보다 더 작은 수가 있다면 dp[x]=dp[x-a]+1
	for(int i=1;i<MAX;++i){
		for(int j=1;j<i;++j){
			if(A[i]>A[j]){
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
		max_length=max(max_length,dp[i]);
	}
	cout<<N-max_length;

	return 0;
}