#include<iostream>
using namespace std;

int main(){
	int t;		//testcases
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		
		int m[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				m[i][j]=0;
		}
		int no=1;
		for(int i=0;i<n;i++){
			if(i%2==0){
				for(int j=0;j<n;j++){
					m[i][j]=no;
					no+=1;
				}
			}
			else{
				for(int j=n-1;j>=0;j--){
					m[i][j]=no;		
					no+=1;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<m[i][j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
