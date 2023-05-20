#include <iostream>
#include <vector>
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
	int lastNum=v[N-1]+1;
	int sum=0;
	for(int i=N-1;i>=0;--i){
		if(lastNum<=v[i]){
			sum+=v[i]-(lastNum-1);
			v[i]=lastNum-1;
		}
		lastNum=v[i];
	}
	cout<<sum;
	return 0;
}