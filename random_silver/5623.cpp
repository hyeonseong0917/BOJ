#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

const int MAX=1000+1;
int arr[MAX][MAX];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>arr[i][j];
			}
		}
		vector<int> diff(1,0);
		for(int i=1;i<n-1;++i){
			diff.push_back(arr[i][n-1]-arr[0][n-1]);
		}
		// cout<<arr[0][1]<<" "<<diff[0]<<" "<<diff[1]<<endl;
		int x=(arr[0][1]-(diff[0]+diff[1]))/2;
		// cout<<x<<endl;
		for(int i=0;i<diff.size();++i){
			diff[i]+=x;
		}
		diff.push_back(arr[0][n-1]-x);
		for(int i=0;i<diff.size();++i){
			cout<<diff[i]<<" ";
		}
	}
	return 0;
}