int fun(int ind,int wt[],int val[],int n,int W,vector<vector<int>> &v){
        if(ind==n||W<=0){
            return 0;
        }
        if(v[W][ind]!=-1)return v[W][ind];
        int val1=fun(ind+1,wt,val,n,W,v);
        int val2=0;
        if(W-wt[ind]>=0)
        val2=fun(ind+1,wt,val,n,W-wt[ind],v)+val[ind];
        return v[W][ind]=max(val1,val2);
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> v(W+1,vector<int>(n,-1));
       return fun(0,wt,val,n,W,v);
    }
