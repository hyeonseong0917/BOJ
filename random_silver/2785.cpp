#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	vector<int> v;
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int L=0, R=N-1;
	int sum=0;
	while(L<R){
		if(v[L]<=R-L-1){
			R-=v[L];
			sum+=v[L];
			++L;
		}else{
			sum+=R-L;
			break;
		}
	}
	cout<<sum;
	return 0;
}