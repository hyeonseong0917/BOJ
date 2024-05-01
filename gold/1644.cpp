#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

vector<int> v;
int arr[4000000+1];

int main() {
	// your code goes here
	int N;
	cin>>N;
	if(N==1){
		cout<<0;
		return 0;
	}
	for(int i=2;i<=N;++i){
		arr[i]=0;
	}
	for(int i=2;i<=N;++i){
		if(arr[i]) continue;
		v.push_back(i);
		for(int j=1;i*j<=N;++j){
			arr[i*j]=1;
		}
	}
	int vs=v.size();
	vector<int> psum(vs+1,0);
	psum[0]=v[0];
	for(int i=1;i<vs;++i){
		psum[i]=psum[i-1]+v[i];
	}
	int L=0;
	int R=0;
	int cnt=0;
	while(L<=R && R<vs && L<vs){
		int cur_num=psum[R]-psum[L]+v[L];
		if(cur_num<N){
			++R;
		}else if(cur_num==N){
			++L;
			++cnt;
		}else{
			++L;
		}
	}
	cout<<cnt;
	return 0;
}	