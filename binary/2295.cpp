#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
vector<int> v;
vector<int> sum;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
}
void solve(){
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			sum.push_back(v[i]+v[j]);
		}
	}
	sort(sum.begin(),sum.end());
	int ans=-1;
	for(int i=N-1;i>=0;--i){
		for(int j=0;j<i;++j){
			// i번째 인덱스의 숫자에 대해 j번째 인덱스의 숫자와 sum의 idx를 더한 것을 비교
			int L=0;
			int R=sum.size()-1;
			while(L<=R){
				int mid=(L+R)/2;
				if(sum[mid]+v[j]<v[i]){
					L=mid+1;
				}else if(sum[mid]+v[j]>v[i]){
					R=mid-1;
				}else{
					ans=v[i];
					break;
				}
			}
		}
		if(ans!=-1){
			break;
		}
	}
	cout<<ans;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}