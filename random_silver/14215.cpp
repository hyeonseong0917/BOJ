#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
	
		sort(arr, arr+3);
	
		if(arr[0] + arr[1] <= arr[2]) arr[2] = arr[0] + arr[1] - 1;
		cout << arr[0]+arr[1]+arr[2];

	} 
	return 0;
}