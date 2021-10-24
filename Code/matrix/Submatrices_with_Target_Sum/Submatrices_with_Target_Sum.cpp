// Given a matrix and a target, return the number of non-empty submatrices that sum to target
// Program in C++

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
int countSubarraysWithSumTarget(vector<int> &arr, int target)
{
    int sum = 0, ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for(auto i : arr)
    {
        sum += i;
        ans += mp[sum - target];
        mp[sum]++;
    }
    return ans;
}

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
{
    int n = matrix.size(), m = matrix[0].size(), ans = 0;
    
    for(int l=0;l<m;l++)
    {
        vector<int> col(n);
        for(int r=l;r<m;r++)
        {
            for(int i=0;i<n;i++)
                col[i] += matrix[i][r];
            ans += countSubarraysWithSumTarget(col, target);
        }
    }
    return ans;
}

int main() 
{
    int n, m;
    cin >> n >> m;

    int target;
    cin >> target;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>> matrix[i][j];
    
    int countOfSubmatricesWithSumTarget = numSubmatrixSumTarget(matrix, target);
    cout << countOfSubmatricesWithSumTarget;
}
