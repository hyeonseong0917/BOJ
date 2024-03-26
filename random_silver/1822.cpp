#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int A=0,B=0;
	cin>>A>>B;
	vector<int> a,b;
	for(int i=0;i<A;++i){
		int c=0;
		cin>>c;
		a.push_back(c);
		// cout<<a[i]<<" ";
	}
	for(int i=0;i<B;++i){
		int c=0;
		cin>>c;
		b.push_back(c);
	}
	// cout<<"he";
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	vector<int> ans;
	for(int i=0;i<A;++i){
		int cur_num=a[i];
		int L=0, R=B-1;
		int mid=(L+R)/2;
		bool flag=0;
		while(L<=R){
			mid=(L+R)/2;
			if(b[mid]==cur_num){
				flag=1;
				break;
			}
			if(b[mid]<cur_num){
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		if(!flag){
			ans.push_back(cur_num);
		}
		// cout<<cur_num<<"\n";
	}
	if(ans.empty()){
		cout<<0;
	}else{
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}
	}
	
	return 0;
}