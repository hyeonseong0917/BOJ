#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	// int cnt=1;
	while(t--){
		int a=0;
		int cnt=0;
		cin>>a;
		if(a==2 || a==1){
			cout<<"Pairs for "<<a<<":"<<"\n";
			++cnt;
			continue;
		}
		cout << "Pairs for " << a << ": ";
        for (int i = 1; i <= 12; i++)
            for (int j = 1; j <= 12; j++)
                if (i + j == a && i<j)
                {
                    if (!cnt)
                    {
                        cnt++;
                        cout << i << ' ' << j;
                    }
                    else
                        cout << ", " << i << ' ' << j;
                }
        cout << '\n';
	}
	return 0;
}