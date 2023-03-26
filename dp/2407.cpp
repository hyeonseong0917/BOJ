#include <iostream>
#include <cstring>
using namespace std;


string cache[100+1][100+1];
string add(string num1, string num2){
    string num = "";
    int sum = 0;
    int size = max(num1.size(),num2.size());

    for(int i=0;i<size || sum;i++){
        if(num1.size()>i) sum += num1[i]-'0';
        if(num2.size()>i) sum += num2[i]-'0';

        num += sum%10 +'0';
        sum /= 10;
    }

    return num;
}
string C(int a, int b){
	// if(b==1){
	// 	return to_string(a);
	// }
	if(a==b || b==0){
		return "1";
	}
	string &ret=cache[a][b];
	if(ret!="") return ret;
	ret=add(C(a-1,b),C(a-1,b-1));
	return ret;
	
}



int main() {
	// your code goes here
	int n=0, m=0;
	cin>>n>>m;
	
	C(n,m);
	for(int i=cache[n][m].size()-1;i>=0;--i){
		cout<<cache[n][m][i];
	}
	return 0;
}