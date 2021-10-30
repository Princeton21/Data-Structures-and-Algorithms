#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int r = -1;
        int s = 0;
        int e = n-1;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            if(matrix[mid][0]==target)return true;
            else if(matrix[mid][0]<target){
                r = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        
        if(r==-1)return false;
        
        int c = -1;
        s = 0;
        e = m-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(matrix[r][mid]==target)return true;
            else if(matrix[r][mid]<target){
                c = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        
        return false;
    }

int main(){

  vector<vector<int>> matrix = {
    {2,3,4,5},
    {6,7,8,9},
    {10,11,12,13},
    {14,15,16,17}
  };

  int ele = 12;
  cout<<searchMatrix(matrix,ele)<<endl;

}


