#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N, F;
	int answer = 0;
	cin >> N >> F;
	
	N /= 100;
	N *= 100;
	
	while((N+answer) % F != 0 && answer < 100) answer ++;
	
	if(answer < 10) printf("0%d", answer);
	else printf("%d", answer);
	
	return 0;
}