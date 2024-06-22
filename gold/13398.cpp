#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

int n;
const int MAX=100000+1;
vector<int> v(MAX,0);
vector<int> f(MAX,0);
vector<int> b(MAX,0);

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>n;
	int sum=0;
	bool flag=0;
	for(int i=0;i<n;++i){
		cin>>v[i];
		if(v[i]<0){
			flag=1;
		}
		sum+=v[i];
	}
	if(n==1){
		cout<<sum;
		return 0;
	}
	if(!flag){
		cout<<sum;
	}else{
		f[0]=v[0];
		for(int i=1;i<n;++i){
			f[i]=max(v[i],v[i]+f[i-1]);
		}
		b[n-1]=v[n-1];
		for(int i=n-2;i>=0;--i){
			b[i]=max(v[i],v[i]+b[i+1]);
		}
		// 0
		sum=max(sum,b[1]);
		sum=max(sum,f[n-2]);
		for(int i=1;i<n-1;++i){
			if(v[i]<0){
				// v[i]를 삭제
				sum=max(sum,max(f[i-1],b[i+1]));
				sum=max(sum,f[i-1]+b[i+1]);	
			}
			
		}
		cout<<sum;
	}
	

	return 0;
}