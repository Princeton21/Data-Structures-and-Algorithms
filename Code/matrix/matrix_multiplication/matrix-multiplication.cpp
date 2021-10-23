#include <iostream>
using namespace std;

int main() {
    int R1,R2,C1,C2;

    cout<<"Enter number of rows and columns of Matrix 1: "<<endl;
    cin>>R1>>C1;

	int mat1[R1][C1];
	cout<<"Enter elements of Matrix 1: "<<endl;
    for(int i=0;i<R1;i++){
        for(int j=0;j<C1;j++){
            cin>>mat1[i][j];
        }
    }

    cout<<"Enter number of rows and columns of Matrix 2: "<<endl;
    cin>>R2>>C2;

    if (C1 != R2) {
    		cout << "The number of columns in Matrix-1 must be equal to the number of rows in "
    				"Matrix-2" << endl;
    		return 0;
    	}
	int mat2[R2][C2];

    cout<<"Enter elements of Matrix 2: "<<endl;
    for(int i=0;i<R2;i++){
        for(int j=0;j<C2;j++){
            cin>>mat2[i][j];
        }
    }

	int rslt[R1][C2];
	cout<<"Multiplication result: "<<endl;
	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			rslt[i][j] = 0;
			for (int k = 0; k < R2; k++) {
				rslt[i][j] += mat1[i][k] * mat2[k][j];
			}
			cout << rslt[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}