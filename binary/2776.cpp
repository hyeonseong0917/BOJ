#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int m,n;
		cin>>n;
		vector<int> a,b;
		for(int i=0;i<n;++i){
			int c=0;
			cin>>c;
			a.push_back(c);
		}
		sort(a.begin(),a.end());
		cin>>m;
		for(int i=0;i<m;++i){
			int c=0;
			cin>>c;
			b.push_back(c);
		}
		vector<int> ans;
		for(int i=0;i<m;++i){
			int curNum=b[i];
			
			int left=0;
			int right=n-1;
			bool flag=0;
			while(left<=right){
				int mid=(left+right)/2;
				if(a[mid]<curNum){
					left=mid+1;
				}else if(a[mid]>curNum){
					right=mid-1;
				}else{
					flag=1;
					break;
				}
			}
			if(flag==1){
				cout<<1<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}
		
		
	}
	return 0;
}