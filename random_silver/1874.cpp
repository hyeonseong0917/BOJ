#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long



// 같은 원소가 K개 이하로 들어있는 최장 연속 부분 수열
int N;
int K;
const int MAX=200000+1;
const int DMAX=100+5;
int arr[MAX]={0,};
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>K;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}

	int L=0, R=N-1;
	int ans=1;
	map<int,int> m;

	while(L<=R){
		m.clear();
		int next_val=-1;
		for(int i=L;i<N;++i){
			++m[arr[i]];
			if(m[arr[i]]>K){
				next_val=arr[i];
				break;
			}else{
				ans=max(ans,i-L+1);
			}
		}
		if(next_val==-1){
			break;
		}
		for(int i=L;i<N;++i){
			--m[arr[i]];
			if(arr[i]==next_val){
				L=i+1;
				break;;
			}
		}
		// cout<<L<<endl;
		// L=next_idx+1;
		
	}
	cout<<ans;


	return 0;
}