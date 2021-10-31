#include<iostream>
using namespace std;

int main(){
    int m1,n1,m2,n2;
    cin >> m1 >> n1 >> m2 >> n2;  //Size of the two matrices

    if(n1 != m2){
        cout << "Multiplication not Possible";
        return 0;
    }

    int mat1[m1][n1], mat2[m2][n2], prod[m1][n2];
//Inputing First matrix
    for(int i=0; i<m1; i++){
        for(int j=0; j<n1; j++) cin >> mat1[i][j];
    }
    cout <<"\n\n";
    //Inputing second matrix
    for(int i=0; i<m2; i++){
        for(int j=0; j<n2; j++) cin >> mat2[i][j];
    }

    for(int i=0; i<m1; i++){        //First two loops are decided by the no. of elements in product matrix
        for(int j=0; j<n2; j++){
            prod[i][j] = 0;
            for(int k=0; k<n1; k++){
                prod [i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    cout << "The product is:" << endl;
    for(int i=0; i<m1; i++){
        for(int j=0; j<n2; j++) cout << prod[i][j] << " ";
        cout << endl;
    }
    return 0;
}