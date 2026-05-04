import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score


# 🔹 Train
def train(df):
    model = {}
    classes = df.iloc[:, -1].unique()

    for c in classes:
        subset = df[df.iloc[:, -1] == c].iloc[:, :-1].astype(float)
        mean = subset.mean().values
        var = subset.var().values
        prior = len(subset) / len(df)

        model[c] = (mean, var, prior)

    return model


# 🔹 Gaussian
def gaussian(x, mean, var):
    return (1 / np.sqrt(2 * np.pi * var)) * np.exp(-((x - mean) ** 2) / (2 * var))


# 🔹 Predict
def predict(model, row):
    probs = {}

    for c, (mean, var, prior) in model.items():
        var = np.maximum(var, 1e-6)
        likelihood = gaussian(row, mean, var)
        probs[c] = np.prod(likelihood) * prior

    return max(probs, key=probs.get)


# 🔹 Load CSV
df = pd.read_csv("gussiandata.csv")

# 🔹 Train-test split directly on DataFrame
train_df, test_df = train_test_split(df, test_size=0.2, random_state=42)

# 🔹 Train model
model = train(train_df)

# 🔹 Predict
y_pred = []
y_test = test_df.iloc[:, -1].values

for i in range(len(test_df)):
    row = test_df.iloc[i, :-1].values.astype(float)
    y_pred.append(predict(model, row))

# 🔹 Accuracy
accuracy = accuracy_score(y_test, y_pred)

print("Accuracy:", accuracy)