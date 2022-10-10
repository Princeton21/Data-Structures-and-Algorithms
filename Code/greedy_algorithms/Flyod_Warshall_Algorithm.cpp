  
/*****Floyd Warshall Algorithm********/


#include <bits/stdc++.h>
using namespace std;
#define INF 99999

void printSolution(int d[][4])
{
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (d[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << d[i][j] << "     ";
        }
        cout << endl;
    }
}
void floydWarshallAlgorithm(int g[][4])
{
    
    int d[4][4], i, j, k;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
    
    for (k = 0; k < 4; k++) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (d[i][j] > (d[i][k] + d[k][j])
                    && (d[k][j] != INF
                        && d[i][k] != INF))
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    printSolution(d);
}
int main()
{
    int g[4][4] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
    floydWarshallAlgorithm(g);
    return 0;
}
 
