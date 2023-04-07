#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int N=0;
		cin>>N;
		vector<long long> A;
		for(int i=0;i<N;++i){
			long long a=0;
			cin>>a;
			A.push_back(a);
		}
		long long sum=0;
		long long target=A[N-1];
		long long cnt=0;
		
		for(int i=N-2;i>=0;--i){
			if(A[i]<=target){
				++cnt;
				sum-=A[i];
			}else{
				sum+=(target*cnt);
				target=A[i];
				cnt=0;
			}
		}
		if(cnt!=0){
			sum+=(target * cnt);
		}
		if(sum<0){
			sum=0;
		}
		cout<<sum<<endl;
	}
	return 0;
}