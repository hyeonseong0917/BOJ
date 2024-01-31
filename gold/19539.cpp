#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	vector<int> v;
	cin>>N;
	int sum=0;
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		sum+=a;
		v.push_back(a);
	}
	if(sum%3==0){
		int num=sum/3;
		int one_num=num;
		for(int i=0;i<N;++i){
			if(v[i]>=2){
				if(num<v[i]/2){
					v[i]-=num*2;
					num=0;
				}else{
					num-=(v[i]/2);
					v[i]-=(v[i]/2)*2;
				}
			}
		}
		for(int i=0;i<N;++i){
			one_num-=v[i];
		}
		if(num==0 && one_num==0){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}else{
		cout<<"NO";
	}
	

	return 0;
}