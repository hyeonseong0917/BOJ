#include <iostream>
using namespace std;

int n=0;
char U[3][3],D[3][3],F[3][3],B[3][3],L[3][3],R[3][3];
char color[6+1]={'w','y','r','o','g','b'};
void Init(){
	int idx=0;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			U[i][j]=color[idx];
		}
	}
	++idx;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			D[i][j]=color[idx];
		}
	}
	++idx;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			F[i][j]=color[idx];
		}
	}
	++idx;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			B[i][j]=color[idx];
		}
	}
	++idx;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			L[i][j]=color[idx];
		}
	}
	++idx;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			R[i][j]=color[idx];
		}
	}
	++idx;
}


void solve(string s){
	char TU[3][3],TD[3][3],TF[3][3],TB[3][3],TL[3][3],TR[3][3];
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			TU[i][j]=U[i][j];
			TD[i][j]=D[i][j];
			TF[i][j]=F[i][j];
			TB[i][j]=B[i][j];
			TL[i][j]=L[i][j];
			TR[i][j]=R[i][j];
		}
	}
	if(s=="L-"){
		for(int i=0;i<3;++i){
			L[2-i][0]=TL[0][i];
			L[2-i][1]=TL[1][i];
			L[2-i][2]=TL[2][i];
            
			U[i][0]=TF[i][0];
			F[i][0]=TD[i][0];
			D[i][0]=TB[2-i][2];
			B[i][2]=TU[2-i][0];
		}
	}else if(s=="L+"){
		for(int i=0;i<3;++i){
			
			// cout<<TB[2][2-i]<<" "<<endl;
			L[i][2]=TL[0][i];
			L[i][1]=TL[1][i];
			L[i][0]=TL[2][i];
			
			U[i][0]=TB[2-i][2];
			B[i][2]=TD[2-i][0];
			D[i][0]=TF[i][0];
			F[i][0]=TU[i][0];
		}
	}else if(s=="R-"){
		for(int i=0;i<3;++i){
			R[2-i][0]=TR[0][i];
			R[2-i][1]=TR[1][i];
			R[2-i][2]=TR[2][i];
			
			U[i][2]=TB[2-i][0];
			F[i][2]=TU[i][2];
			D[i][2]=TF[i][2];
			B[i][0]=TD[2-i][2];
		}
	}else if(s=="R+"){
		for(int i=0;i<3;++i){
			
			R[i][2]=TR[0][i];
			R[i][1]=TR[1][i];
			R[i][0]=TR[2][i];
			
			U[i][2]=TF[i][2];
			B[i][0]=TU[2-i][2];
			D[i][2]=TB[2-i][0];
			F[i][2]=TD[i][2];
		}
	}else if(s=="U-"){
		for(int i=0;i<3;++i){
			U[2-i][0]=TU[0][i];
			U[2-i][1]=TU[1][i];
			U[2-i][2]=TU[2][i];
			
			F[0][i]=TL[0][i];
			R[0][i]=TF[0][i];
			B[0][i]=TR[0][i];
			L[0][i]=TB[0][i];
		}
	}else if(s=="U+"){
		for(int i=0;i<3;++i){
			U[i][2]=TU[0][i];
			U[i][1]=TU[1][i];
			U[i][0]=TU[2][i];
			
			F[0][i]=TR[0][i];
			R[0][i]=TB[0][i];
			B[0][i]=TL[0][i];
			L[0][i]=TF[0][i];
		}
	}else if(s=="D-"){
		for(int i=0;i<3;++i){
			D[2-i][0]=TD[0][i];
			D[2-i][1]=TD[1][i];
			D[2-i][2]=TD[2][i];
			
			F[2][i]=TR[2][i];
			R[2][i]=TB[2][i];
			B[2][i]=TL[2][i];
			L[2][i]=TF[2][i];
		}
	}else if(s=="D+"){
		for(int i=0;i<3;++i){
			D[i][2]=TD[0][i];
			D[i][1]=TD[1][i];
			D[i][0]=TD[2][i];
			
			F[2][i]=TL[2][i];
			R[2][i]=TF[2][i];
			B[2][i]=TR[2][i];
			L[2][i]=TB[2][i];
		}
	}else if(s=="F-"){
		for(int i=0;i<3;++i){
			F[2-i][0]=TF[0][i];
			F[2-i][1]=TF[1][i];
			F[2-i][2]=TF[2][i];
			
			U[2][i]=TR[i][0];
			L[i][2]=TU[2][2-i];
			D[0][i]=TL[i][2];
			R[i][0]=TD[0][2-i];
		}
	}else if(s=="F+"){
		for(int i=0;i<3;++i){
			F[i][2]=TF[0][i];
			F[i][1]=TF[1][i];
			F[i][0]=TF[2][i];
			U[2][i]=TL[2-i][2];
			R[i][0]=TU[2][i];
			D[0][i]=TR[2-i][0];
			L[i][2]=TD[0][i];
		}
	}else if(s=="B-"){
		for(int i=0;i<3;++i){
			B[2-i][0]=TB[0][i];
			B[2-i][1]=TB[1][i];
			B[2-i][2]=TB[2][i];
			
			U[0][i]=TL[2-i][0];
			R[i][2]=TU[0][i];
			D[2][2-i]=TR[i][2];
			L[i][0]=TD[2][i];
		}
		
	}else if(s=="B+"){
		for(int i=0;i<3;++i){
			B[i][2]=TB[0][i];
			B[i][1]=TB[1][i];
			B[i][0]=TB[2][i];
			
			U[0][i]=TR[i][2];
			R[i][2]=TD[2][2-i];
			D[2][i]=TL[i][0];
			L[i][0]=TU[0][2-i];
			
		}
	}
}

int main() {
	// your code goes here
	int t=0;
	
	cin>>t;
	while(t--){
		cin>>n;
		Init();
		for(int i=0;i<n;++i){
			string s="";
			cin>>s;
			solve(s);
			// cout<<s<<endl;
			// for(int j=0;j<3;++j){
			// 	for(int k=0;k<3;++k){
			// 		cout<<U[j][k];
			// 	}cout<<"\n";
			// }
			// cout<<endl;
		}
		for(int j=0;j<3;++j){
			for(int k=0;k<3;++k){
				cout<<U[j][k];
				
			}cout<<"\n";
		}
	}
	return 0;
}