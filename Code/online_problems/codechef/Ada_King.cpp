#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		
		char arr[8][8];
		memset(arr,'X',sizeof(arr));
		
		arr[0][0]='O';
		int moves=1;
		bool flag=false;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(i==0 && j==0){
					arr[0][0]='O';
					continue;
				}
				if(moves<k){
					arr[i][j]='.';	
					moves++;		
				}	
				else{
					flag=true;
					break;			
				}
			}
			if(flag)
				break;
		}

		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++)
				cout<<arr[i][j];
			cout<<"\n";
		}
	}	
	return 0;	
}
