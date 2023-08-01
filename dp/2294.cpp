#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=100000+1;

int main() {
	// your code goes here
	int n,k=0;
	cin>>n>>k;
	int d[MAX]={0,};
	for(int i=1;i<=k;++i){
		d[i]=122232421;
	}
	vector<int> v;
	for(int i=0;i<n;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
		d[a]=1;
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=k;++i){
		for(int j=0;j<n;++j){
			if(i-v[j]>=1 && i-v[j]<k){
				d[i]=min(d[i],d[i-v[j]]+1);
			}else{
				break;
			}
		}
		// cout<<i<<" "<<d[i]<<endl;
	}
	if(d[k]==122232421){
		cout<<-1;
	}else{
		cout<<d[k];
	}
	return 0;
}