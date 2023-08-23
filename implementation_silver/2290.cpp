#include <iostream>
using namespace std;


char board[50+1][1001];
int N,M;
int idx=0;
int cnt=0;
void fill_board(int cur_idx, int s, char cur_num){
	if(cur_num=='1'){
		for(int i=0;i<N;++i){
			if(i%(s+1)!=0){
				board[i][cur_idx+M-1]='|';
			}
		}
		
		// for(int i=0;i<N;++i){
		// 	for(int j=cur_idx;j<cur_idx+M;++j){
		// 		cout<<board[i][j];
		// 	}
		// 	if(i!=N-1){
		// 		cout<<endl;
		// 	}
		// }
	}else if(cur_num=='2'){
		bool flag=0;
		for(int i=0;i<N;++i){
			if(i%(s+1)==0){
				for(int j=cur_idx+1;j<cur_idx+M-1;++j){
					board[i][j]='-';
				}		
			}else{
				if(i<(N/2)){
					board[i][cur_idx+M-1]='|';
				}else{
					board[i][cur_idx]='|';
				}
				
			}
			
		}
	}else if(cur_num=='3'){
		for(int i=0;i<N;++i){
			if(i%(s+1)==0){
				for(int j=cur_idx+1;j<cur_idx+M-1;++j){
					board[i][j]='-';
				}		
			}else{
				board[i][cur_idx+M-1]='|';
			}
			
		}
	}else if(cur_num=='4'){
		for(int i=1;i<N-1;++i){
			if(i<(N/2)){
				board[i][cur_idx]='|';
				board[i][cur_idx+M-1]='|';
			}else{
				if(i==(N/2)){
					for(int j=cur_idx+1;j<cur_idx+M-1;++j){
						board[i][j]='-';
					}
				}else{
					board[i][cur_idx+M-1]='|';
				}
			}
		}
	}else if(cur_num=='5'){
		for(int i=0;i<N;++i){
			if(i%(s+1)==0){
				for(int j=cur_idx+1;j<cur_idx+M-1;++j){
					board[i][j]='-';
				}		
			}else{
				if(i<(N/2)){
					board[i][cur_idx]='|';
				}else{
					board[i][cur_idx+M-1]='|';	
				}
				
			}
			
		}
	}else if(cur_num=='6'){
		for(int i=0;i<N;++i){
			if(i%(s+1)==0){
				for(int j=cur_idx+1;j<cur_idx+M-1;++j){
					board[i][j]='-';
				}		
			}else{
				if(i<(N/2)){
					board[i][cur_idx]='|';
				}else{
					board[i][cur_idx]='|';
					board[i][cur_idx+M-1]='|';	
				}
				
			}
			
		}
	}else if(cur_num=='7'){
		for(int i=0;i<N;++i){
			if(i==0){
				for(int j=cur_idx+1;j<cur_idx+M-1;++j){
					board[i][j]='-';
				}		
			}else{
				if(i%(s+1)!=0){
					board[i][cur_idx+M-1]='|';	
				}
				
			}
			
		}
	}else if(cur_num=='8'){
		for(int i=0;i<N;++i){
			if(i%(s+1)==0){
				for(int j=cur_idx+1;j<cur_idx+M-1;++j){
					board[i][j]='-';
				}		
			}else{
				board[i][cur_idx]='|';
				board[i][cur_idx+M-1]='|';	
				
			}
			
		}
	}else if(cur_num=='9'){
		for(int i=0;i<N;++i){
			if(i%(s+1)==0){
				for(int j=cur_idx+1;j<cur_idx+M-1;++j){
					board[i][j]='-';
				}		
			}else{
				board[i][cur_idx+M-1]='|';
				if(i<(N/2)){
					board[i][cur_idx]='|';		
				}
			}
			
		}
	}else{
		for(int i=0;i<N;++i){
			if(i==(N/2)) continue;
			if(i%(s+1)==0){
				for(int j=cur_idx+1;j<cur_idx+M-1;++j){
					board[i][j]='-';
				}		
			}else{
				board[i][cur_idx]='|';
				board[i][cur_idx+M-1]='|';	
				
			}
			
		}
	}
}
int main() {
	// your code goes here
	for(int i=0;i<50+1;++i){
		for(int j=0;j<1000+1;++j){
			board[i][j]=' ';
		}
	}
	string s,n;
	cin>>s;
	cin>>n;
	N=(stoi(s)*2)+3;
	M=stoi(s)+2;
	// fill_board(0,stoi(s),'1');
	for(int i=0;i<n.size();++i){
		fill_board(idx,stoi(s),n[i]);
		idx+=(M+1);
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<((M+1)*(n.size()-1))+M;++j){
			cout<<board[i][j];
		}
		if(i!=N-1){
			cout<<endl;
		}
	}
	return 0;
}