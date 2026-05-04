import numpy as np
import pandas as pd


def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)
    
df = pd.read_csv("ann.csv")


X = df.iloc[:, :-1].values
y = df.iloc[:, -1].values.reshape(-1, 1)

X = X / X.max(axis=0)


np.random.seed(1)
input_neurons = X.shape[1]
weights = 2 * np.random.random((input_neurons, 1)) - 1


for i in range(20000):

    output = sigmoid(np.dot(X, weights))
    error = y - output
    adjustment = error * sigmoid_derivative(output)
    weights += np.dot(X.T, adjustment)

print("Final Weights after training:")
print(weights)

print("\nFirst 5 Predictions vs Actual:")
for i in range(5):
    print(f"Pred: {output[i][0]:.4f} | Actual: {y[i][0]}")
