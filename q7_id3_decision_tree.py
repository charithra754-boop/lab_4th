import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score

df = pd.read_csv("decisiontree.csv")
X, y = df.iloc[:, :-1], df.iloc[:, -1]

le = LabelEncoder()
X = X.apply(le.fit_transform)
y = le.fit_transform(y)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

model = DecisionTreeClassifier().fit(X_train, y_train)

print("Accuracy:", accuracy_score(y_test, model.predict(X_test)))

plt.figure(figsize=(15, 10))
plot_tree(model, feature_names=df.columns[:-1],
          class_names=[str(i) for i in set(y)], filled=True)
plt.show()