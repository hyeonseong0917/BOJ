#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool comp(int a,int b){
	return a>b;
}
int main() {
	// your code goes here
	vector<long long> v;
	int N=0;
	cin>>N;
	for(int i=0;i<N;++i){
		long long a=0;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),comp);
	// cout<<v[0];
	long long sum=0;
	for(int i=0;i<N;++i){
		long long curNum=v[i]-i;
		if(curNum>=0){
			sum+=curNum;
		}
	}
	cout<<sum;
	return 0;
}