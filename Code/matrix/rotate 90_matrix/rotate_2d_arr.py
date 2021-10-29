import numpy as np

def rotate_matrix(old_matrix):
    old_matrix = np.matrix(old_matrix)
    shape = old_matrix.shape
    new_matrix = np.zeros(shape).T
    for i in range(shape[0]):
        for j in range(shape[1]):
            new_matrix[j,i] = old_matrix[shape[0]-1-i,j]
    return new_matrix