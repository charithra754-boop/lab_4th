"""
question 3: gradient descent for linear regression.
this script manually implements the gradient descent algorithm to find the optimal weights
for a linear regression model, demonstrating how learning rates and iterations affect learning.
"""

import numpy as np
import matplotlib.pyplot as plt

def compute_cost(x, y, theta):
    # calculates the mean squared error (cost) for the current weights (theta)
    m = len(y)
    predictions = x.dot(theta)
    cost = (1 / (2 * m)) * np.sum(np.square(predictions - y))
    return cost

def gradient_descent(x, y, theta, learning_rate, iterations):
    # iteratively updates weights (theta) to minimize the cost function
    m = len(y)
    cost_history = np.zeros(iterations)
    
    for i in range(iterations):
        # calculate predictions
        predictions = x.dot(theta)
        
        # calculate the gradient (derivative of cost function with respect to weights)
        errors = np.dot(x.T, (predictions - y))
        
        # update weights by taking a step in the opposite direction of the gradient
        theta -= (learning_rate / m) * errors
        
        # record the cost at each iteration to monitor convergence
        cost_history[i] = compute_cost(x, y, theta)
        
    return theta, cost_history

def main():
    # step 1: generate some random linear data
    np.random.seed(42)
    x = 2 * np.random.rand(100, 1)
    y = 4 + 3 * x + np.random.randn(100, 1)
    
    # step 2: prepare the data for gradient descent
    # add a column of ones to x for the bias term (intercept)
    x_b = np.c_[np.ones((100, 1)), x]
    
    # initialize weights (theta) randomly
    theta = np.random.randn(2, 1)
    
    # set hyperparameters
    learning_rate = 0.1
    iterations = 100
    
    # step 3: run gradient descent
    theta_optimal, cost_history = gradient_descent(x_b, y, theta, learning_rate, iterations)
    
    print("optimal weights found by gradient descent:")
    print(theta_optimal)
    
    # step 4: visualize convergence
    # plot the cost over iterations to ensure it's decreasing
    plt.plot(range(iterations), cost_history, 'b-')
    plt.xlabel('iterations')
    plt.ylabel('cost (mse)')
    plt.title('gradient descent convergence')
    plt.show()

if __name__ == "__main__":
    main()
