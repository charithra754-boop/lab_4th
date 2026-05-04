"""
question 2: logistic regression on customer churn dataset.
this code demonstrates how to use logistic regression to predict a binary outcome
(churn: yes/no) based on input features.
"""

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from sklearn.datasets import make_classification
import numpy as np


class LogisticRegression:
    """
    Simple binary Logistic Regression using gradient descent.
    - fit(X, y): learns weights (including intercept)
    - predict(X): returns 0/1 class predictions
    - predict_proba(X): returns probabilities for the positive class
    Parameters: lr (learning rate), n_iter, l2_reg (regularization)
    """
    def __init__(self, lr=0.1, n_iter=1000, l2_reg=0.0, tol=1e-6, verbose=False):
        self.lr = lr
        self.n_iter = int(n_iter)
        self.l2_reg = float(l2_reg)
        self.tol = float(tol)
        self.verbose = verbose
        self.coef_ = None
        self.intercept_ = 0.0

    def _prepare_X(self, X):
        if isinstance(X, pd.DataFrame):
            return X.values
        return np.asarray(X)

    def _sigmoid(self, z):
        return 1.0 / (1.0 + np.exp(-z))

    def fit(self, X, y):
        X_mat = self._prepare_X(X)
        y_vec = np.asarray(y).reshape(-1)
        n_samples, n_features = X_mat.shape

        # initialize weights
        w = np.zeros(n_features)
        b = 0.0

        for i in range(self.n_iter):
            linear = X_mat @ w + b
            preds = self._sigmoid(linear)
            error = preds - y_vec

            grad_w = (X_mat.T @ error) / n_samples + (self.l2_reg * w)
            grad_b = np.mean(error)

            w_prev = w.copy()
            b_prev = b

            w -= self.lr * grad_w
            b -= self.lr * grad_b

            # convergence check
            if np.linalg.norm(w - w_prev) < self.tol and abs(b - b_prev) < self.tol:
                if self.verbose:
                    print(f"converged at iteration {i}")
                break

        self.coef_ = w
        self.intercept_ = float(b)

    def predict_proba(self, X):
        X_mat = self._prepare_X(X)
        return self._sigmoid(X_mat @ self.coef_ + self.intercept_)

    def predict(self, X, threshold=0.5):
        probs = self.predict_proba(X)
        return (probs >= threshold).astype(int)

def main():
    # step 1: load/generate the dataset
    # using make_classification to simulate a customer churn dataset
    x, y = make_classification(n_samples=1000, n_features=10, n_informative=5, random_state=42)
    feature_names = [f"feature_{i}" for i in range(10)]
    
    # step 2: split the dataset into training and testing sets
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)
    
    # step 3: create and train the logistic regression model
    # logistic regression is used for classification by estimating probabilities using a sigmoid function
    model = LogisticRegression(n_iter=1000)
    model.fit(x_train, y_train)
    
    # step 4: make predictions on the test set
    y_pred = model.predict(x_test)
    
    # step 5: evaluate the model's performance
    # accuracy is the proportion of correctly predicted instances
    acc = accuracy_score(y_test, y_pred)
    print(f"accuracy: {acc}")
    
    # confusion matrix shows true positives, true negatives, false positives, false negatives
    print("\nconfusion matrix:")
    print(confusion_matrix(y_test, y_pred))
    
    # classification report gives precision, recall, and f1-score
    print("\nclassification report:")
    print(classification_report(y_test, y_pred))
    
    # step 6: discuss important factors
    # similar to linear regression, the coefficients indicate importance and direction
    coefficients = pd.Series(model.coef_, index=feature_names)
    print("\nfeature importance (coefficients):")
    print(coefficients.sort_values(ascending=False))

if __name__ == "__main__":
    main()
