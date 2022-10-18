#include <iostream>

using namespace std;

int main() {
	int t;
	const int n = 4;
	cin>>t;
	while(t--){
	    long int arr[n];
	    for(int i = 0; i < n; i++){
	        cin >>arr[i];
	    }
        
	    int flag = 0, count = 0;
	    for(int i = 0; i < n; i++){
	        if(arr[i] <= 0){
	            if(arr[i] == 0){
	                count++;
	            }
	            else{
	                flag++;
	            }
	        }
	    }
	    if(count != 0){
	        cout<<"0"<<endl;
	    }
	    else{
	        if(flag % 2 == 0){
	            cout<<"0"<<endl;
	        }
	        else{
	            cout<<"1"<<endl;
	        }
	    }
	}
	return 0;
}