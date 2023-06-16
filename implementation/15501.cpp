#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n=0;
vector<int> cur,res;
vector<int> right_seg,reverse_seg;
void Input(){
	cin>>n;
	for(int i=0;i<n;++i){
		int a=0;
		cin>>a;
		cur.push_back(a);
	}
	for(int i=0;i<n;++i){
		int a=0;
		cin>>a;
		res.push_back(a);
	}
}
void solve(){
	if(n==1){
		cout<<"good puzzle";
		return;
	}
	right_seg=cur;
	reverse_seg=cur;
	reverse(reverse_seg.begin(),reverse_seg.end());
	int right_idx=0, reverse_idx=0;
	for(int i=0;i<n;++i){
		if(right_seg[i]==res[0]){
			right_idx=i;
			break;
		}
	}
	for(int i=0;i<n;++i){
		if(reverse_seg[i]==res[0]){
			reverse_idx=i;
			break;
		}
	}
	bool right_flag=1, reverse_flag=1;
	if(right_idx==0){
		for(int i=0;i<n;++i){
			if(right_seg[i]!=res[i]){
				right_flag=0;
				break;
			}
		}
	}
	if(reverse_idx==0){
		for(int i=0;i<n;++i){
			if(reverse_seg[i]!=res[i]){
				reverse_flag=0;
				break;
			}
		}
	}
	vector<int> right_ans, reverse_ans;
	right_ans.clear();
	reverse_ans.clear();
	bool can_make=1;
	if(right_flag==1 && reverse_flag==0){
		// cout<<right_idx<<endl;
		for(int i=right_idx;i<n;++i){
			right_ans.push_back(right_seg[i]);
			// cout<<right_seg[i]<<endl;
		}	
		for(int i=0;i<right_idx;++i){
			right_ans.push_back(right_seg[i]);
			// cout<<right_seg[i]<<endl;
		}
		// cout<<right_ans.size()<<endl;
		
		for(int i=0;i<n;++i){
			if(right_ans[i]!=res[i]){
				can_make=0;
			}
		}
	}
	if(reverse_flag==1 && right_flag==0){
		// cout<<reverse_idx<<endl;
		for(int i=reverse_idx;i<n;++i){
			reverse_ans.push_back(reverse_seg[i]);
			// cout<<right_seg[i]<<endl;
		}	
		for(int i=0;i<reverse_idx;++i){
			reverse_ans.push_back(reverse_seg[i]);
			// cout<<right_seg[i]<<endl;
		}
		// for(int i=0;i<n;++i){
		// 	cout<<reverse_ans[i]<<" ";
		// }
		for(int i=0;i<n;++i){
			if(reverse_ans[i]!=res[i]){
				can_make=0;
			}
		}
	}
	if(can_make==0){
		cout<<"bad puzzle";
		return;
	}
	bool first_can_make=1, second_can_make=1;
	if(right_flag==1 && reverse_flag==1){
		// cout<<reverse_idx<<endl;
		for(int i=reverse_idx;i<n;++i){
			reverse_ans.push_back(reverse_seg[i]);
			// cout<<right_seg[i]<<endl;
		}	
		for(int i=0;i<reverse_idx;++i){
			reverse_ans.push_back(reverse_seg[i]);
			// cout<<right_seg[i]<<endl;
		}
		// for(int i=0;i<n;++i){
		// 	cout<<reverse_ans[i]<<" ";
		// }
		for(int i=0;i<n;++i){
			if(reverse_ans[i]!=res[i]){
				first_can_make=0;
			}
		}
		for(int i=right_idx;i<n;++i){
			right_ans.push_back(right_seg[i]);
			// cout<<right_seg[i]<<endl;
		}	
		for(int i=0;i<right_idx;++i){
			right_ans.push_back(right_seg[i]);
			// cout<<right_seg[i]<<endl;
		}
		// cout<<right_ans.size()<<endl;
		
		for(int i=0;i<n;++i){
			if(right_ans[i]!=res[i]){
				second_can_make=0;
			}
		}
		if(first_can_make==0 && second_can_make==0){
			cout<<"bad puzzle";
		}else{
			cout<<"good puzzle";
		}
	}
	
	
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}