#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int N=0;
	cin>>N;
	vector<int> v;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int sum=1;
	int allowed_num=0;
	int res=122232421;
	for(int i=0;i<N;++i){
		if(sum-v[i]<=allowed_num && sum-v[i]>=0){
			allowed_num+=v[i];
			sum+=v[i];
			res=sum;
		}else{
			if(allowed_num+1==v[i]){
				res=v[i]+1;
				break;
			}else{
				res=allowed_num+1;
				break;
			}
		}
		// cout<<"allowd-ed_num: "<<allowed_num<<endl;
		// cout<<"sum: "<<sum<<endl;
	}
	cout<<res;
	
	
	return 0;
}