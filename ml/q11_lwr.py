"""
question 11: non-parametric locally weighted regression (lwr) algorithm.
this script implements lwr from scratch to fit a set of non-linear data points,
and plots the resulting regression curve.
"""

import numpy as np
import matplotlib.pyplot as plt

def radial_kernel(x0, x, tau):
    # the radial kernel (gaussian) calculates the weight (influence) of each training point x on the query point x0
    # closer points get higher weights, farther points get exponentially lower weights
    # tau controls the bandwidth (how quickly the weight drops off with distance)
    # the shape is a bell curve
    return np.exp(-np.sum((x - x0) ** 2, axis=1) / (2 * tau ** 2))

def local_regression(x0, x, y, tau):
    # perform locally weighted linear regression for a single query point x0
    
    # step 1: add a column of 1s to x for the intercept term (bias)
    x_b = np.c_[np.ones(len(x)), x]
    
    # step 2: compute weights for all training points relative to the query point x0
    # a diagonal matrix where the diagonal elements are the weights
    xw = np.diag(radial_kernel(x0, x, tau))
    
    # step 3: calculate the locally weighted coefficients (theta)
    # formula: theta = (x^t * w * x)^-1 * (x^t * w * y)
    # this minimizes the weighted sum of squared errors
    theta = np.linalg.pinv(x_b.T.dot(xw).dot(x_b)).dot(x_b.T).dot(xw).dot(y)
    
    # step 4: predict the value for the query point x0
    x0_b = np.r_[1, x0]
    return x0_b.dot(theta)

def main():
    # step 1: generate some synthetic non-linear data (e.g., a sine wave with noise)
    np.random.seed(42)
    x = np.linspace(-3, 3, 100)
    # y is a noisy sine wave
    y = np.sin(x) + np.random.normal(0, 0.2, len(x))
    
    # step 2: set the bandwidth parameter tau
    # smaller tau means the regression relies heavily on very close points (more wiggly, prone to overfitting)
    # larger tau means a smoother curve that considers points further away
    tau = 0.5
    
    # step 3: predict values for an array of query points (domain)
    domain = np.linspace(-3, 3, 200)
    predictions = [local_regression(x0, x, y, tau) for x0 in domain]
    
    # step 4: plot the original data and the lwr fit
    plt.scatter(x, y, color='blue', alpha=0.5, label='training data')
    plt.plot(domain, predictions, color='red', linewidth=2, label=f'lwr fit (tau={tau})')
    plt.title('locally weighted regression')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend()
    plt.grid(True)
    
    # display the graph
    print("displaying the locally weighted regression plot...")
    plt.show()

if __name__ == "__main__":
    main()
