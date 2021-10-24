import numpy as np
import sys
x = int(input('The order of matrix is? -> '))
m = np.zeros((x,2*x))
print('Enter the matrix values ->')
for i in range(x):
    for j in range(x):
        m[i][j] = float(input( 'm['+str(i)+']['+ str(j)+']='))
for i in range(x):
    for j in range(x):
        if i == j:
            m[i][j+x] = 1
for i in range(x):
    if m[i][i] == 0.0:
        sys.exit('Divide by zero detected!')
    for j in range(x):
        if i != j:
            ratio = m[j][i]/m[i][i]
            for k in range(2*x):
                m[j][k] = m[j][k] - ratio * m[i][k]
for i in range(x):
    divisor = m[i][i]
    for j in range(2*x):
        m[i][j] = m[i][j]/divisor
print('\nINVERSE MATRIX IS:')
for i in range(x):
    for j in range(x, 2*x):
        print(m[i][j], end='\t')
    print()