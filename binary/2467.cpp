#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAX=100000+1;
vector<int> v;
int N=0;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
}
vector<int> Minus,Plus;
int val1=0, val2=0, res=2000000000+1;

void solve(){
	int left=0, right=N-1;
	int res=abs(v[left]+v[right]);
	val1=v[left];
	val2=v[right];
	while(left<right){
		int tmp=v[left]+v[right];
		if(abs(tmp)<res){
			val1=v[left];
			val2=v[right];
			res=abs(tmp);
		}
		if(tmp<0){
			++left;
		}else{
			--right;
		}
	}
	cout<<val1<<" "<<val2;
}
int main() {
	// your code goes here
	Input();
	solve();
	
	return 0;
}#include <iostream>
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