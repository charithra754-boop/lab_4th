"""
question 13: principal component analysis (pca).
this script implements dimensionality reduction using pca from scratch.
it projects a high-dimensional dataset onto a lower-dimensional space.
"""

import numpy as np
import matplotlib.pyplot as plt

def pca(x, num_components):
    # step 1: standardize the dataset
    # centering the data (subtracting the mean) is a crucial step for pca
    # it ensures that the first principal component describes the direction of maximum variance
    mean_val = np.mean(x, axis=0)
    x_centered = x - mean_val
    
    # step 2: compute the covariance matrix
    # the covariance matrix shows how features vary together
    # it's an n x n matrix, where n is the number of features
    cov_matrix = np.cov(x_centered, rowvar=False)
    
    # step 3: compute eigenvalues and eigenvectors of the covariance matrix
    # eigenvectors are the principal components (directions of new feature space)
    # eigenvalues determine the magnitude (importance) of these directions
    eigenvalues, eigenvectors = np.linalg.eig(cov_matrix)
    
    # step 4: sort eigenvectors by eigenvalues in descending order
    # this puts the most important principal components first
    sorted_index = np.argsort(eigenvalues)[::-1]
    sorted_eigenvectors = eigenvectors[:, sorted_index]
    
    # step 5: select the top 'num_components' eigenvectors
    eigenvector_subset = sorted_eigenvectors[:, 0:num_components]
    
    # step 6: transform the data onto the new subspace
    # project the original data using the selected principal components
    x_reduced = np.dot(x_centered, eigenvector_subset)
    
    return x_reduced, eigenvector_subset, eigenvalues

def main():
    # step 1: generate some 3-dimensional dummy data to reduce
    np.random.seed(42)
    # create two clusters of points in 3d space
    class1 = np.random.normal(loc=[1, 1, 1], scale=1, size=(50, 3))
    class2 = np.random.normal(loc=[5, 5, 5], scale=1, size=(50, 3))
    
    # combine the data
    data = np.vstack((class1, class2))
    labels = np.array([0] * 50 + [1] * 50)
    
    # step 2: apply pca to reduce from 3 dimensions to 2 dimensions
    num_components = 2
    data_reduced, components, eigenvalues = pca(data, num_components)
    
    # step 3: visualize the result
    # the 3d data is now projected onto a 2d plane that captures the most variance
    plt.figure(figsize=(8, 6))
    
    # plot the reduced data
    plt.scatter(data_reduced[labels == 0, 0], data_reduced[labels == 0, 1], 
                color='red', label='class 0', alpha=0.7)
    plt.scatter(data_reduced[labels == 1, 0], data_reduced[labels == 1, 1], 
                color='blue', label='class 1', alpha=0.7)
                
    plt.title('pca: dimensionality reduction from 3d to 2d')
    plt.xlabel('principal component 1')
    plt.ylabel('principal component 2')
    plt.legend()
    plt.grid()
    
    print(f"original data shape: {data.shape}")
    print(f"reduced data shape: {data_reduced.shape}")
    print("\neigenvalues (variance captured by each component):")
    print(eigenvalues)
    
    print("\ndisplaying the 2d projection plot...")
    plt.show()

if __name__ == "__main__":
    main()
