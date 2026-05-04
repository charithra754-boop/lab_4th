import pandas as pd

df = pd.read_csv("california_housing.csv")

X = df.iloc[:, 0]
Y = df.iloc[:, 1]


x_mean = X.mean()
y_mean = Y.mean()


num = ((X - x_mean) * (Y - y_mean)).sum()
den = ((X - x_mean) ** 2).sum()
b1 = num / den


b0 = y_mean - b1 * x_mean

print("Slope (b1):", b1)
print("Intercept (b0):", b0)


Y_pred = b0 + b1 * X
print("Predicted values:\n", Y_pred)