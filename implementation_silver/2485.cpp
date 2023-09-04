#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int GCD(int a, int b){
	if(b==0){
		return a;
	}
	return GCD(b,a%b);
}

int main() {
	// your code goes here
	int N=0;
	char c;
	cin>>N;
	vector<long long> v;
	for(int i=0;i<N;++i){
		long long a=0;
		cin>>a;
		v.push_back(a);
	}
	// long long diff=1222232421;
	vector<long long> diff;
	for(int i=0;i<N-1;++i){
		diff.push_back(v[i+1]-v[i]);
	}
	int cur_gcd=diff[0];
	for(int i=1;i<diff.size();++i){
		cur_gcd=GCD(diff[i],cur_gcd);
	}
	long long cnt=0;
	for(int i=0;i<N-1;++i){
		cnt+=((v[i+1]-v[i])/cur_gcd)-1;
	}
	cout<<cnt;
	return 0;
}