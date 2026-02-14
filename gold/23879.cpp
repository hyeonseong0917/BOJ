#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> target(n+2);
    for(int i = 1; i <= n; i++) {
        cin >> target[i];
    }
    for(int i = 1; i <= n; i++) {
        int a;
		cin>>a;
		target[i]-=a;
    }
	int ans=0;
	for(int i=0;i<=n;++i){
		ans+=abs(target[i]-target[i+1]);
	}
	cout<<ans/2;
    return 0;
}