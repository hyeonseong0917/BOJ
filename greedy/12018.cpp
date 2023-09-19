#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	// your code goes here
	int N,M;
	cin>>N>>M;
	vector<int> maxNum;
	for(int i=0;i<N;++i){
		int P=0;
		int L=0;
		vector<int> tmp;
		cin>>P>>L;
		for(int j=0;j<P;++j){
			int a=0;
			cin>>a;
			tmp.push_back(a);
		}
		if(P<L){
			maxNum.push_back(1);
		}else{//p>=L
			sort(tmp.begin(),tmp.end());
			reverse(tmp.begin(),tmp.end());
			maxNum.push_back(tmp[L-1]);
		}
		
		
	}
	sort(maxNum.begin(),maxNum.end());
	int sum=0;
	int cnt=0;
	for(int i=0;i<maxNum.size();++i){
		if(M>=maxNum[i]){
			++cnt;
			M-=maxNum[i];
		}else{
			break;
		}
	}
	cout<<cnt;
	return 0;
}