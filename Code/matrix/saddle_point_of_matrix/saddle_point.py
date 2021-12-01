mat = [[1,2,3],[4,5,6],[7,8,9]]
saddle_pt = None

for row in mat:
	for elem in row:
		if elem == min(row):
			column_n = row.index(elem)
			column = []
			for i in range(len(mat)):
				column.append(mat[i][column_n])
			if elem == max(column):
				saddle_pt = elem
				
if saddle_pt == None:
    print("The matrix has no saddle point.")
else:
    print("Saddle point of the matrix is ",saddle_pt)
