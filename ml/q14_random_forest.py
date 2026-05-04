"""
question 14: random forest classifier on loan dataset.
this script builds a random forest classifier to predict loan defaults,
evaluates the model, and discusses the importance of different features.
we use the sklearn library as permitted by the instructions.
"""

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report
import csv

def main():
    # step 1: create a dummy loan dataset
    # features might include income, credit score, loan amount, employment years
    csv_file = 'loan_data.csv'
    with open(csv_file, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['income', 'credit_score', 'loan_amount', 'employment_years', 'default'])
        writer.writerow([50000, 700, 10000, 5, 0])
        writer.writerow([30000, 600, 20000, 1, 1])
        writer.writerow([80000, 750, 15000, 10, 0])
        writer.writerow([40000, 620, 18000, 2, 1])
        writer.writerow([120000, 800, 30000, 15, 0])
        writer.writerow([25000, 580, 5000, 0, 1])
        writer.writerow([60000, 680, 12000, 4, 0])
        writer.writerow([45000, 640, 25000, 3, 1])
        writer.writerow([90000, 780, 10000, 8, 0])
        writer.writerow([35000, 590, 15000, 1, 1])
        
    # step 2: load the dataset
    df = pd.read_csv(csv_file)
    
    # step 3: separate features (x) and the target variable (y)
    # the target is 'default' (1 = default, 0 = no default)
    x = df.drop('default', axis=1)
    y = df['default']
    feature_names = x.columns
    
    # step 4: split the dataset into training and test sets
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=42)
    
    # step 5: build the random forest classifier
    # random forest is an ensemble of decision trees
    # it builds multiple trees and merges them together for a more accurate and stable prediction
    # n_estimators specifies the number of trees in the forest
    model = RandomForestClassifier(n_estimators=100, random_state=42)
    model.fit(x_train, y_train)
    
    # step 6: evaluate the model's performance
    y_pred = model.predict(x_test)
    accuracy = accuracy_score(y_test, y_pred)
    
    print(f"random forest classification results:")
    print(f"accuracy: {accuracy * 100:.2f}%")
    print("\nclassification report:")
    print(classification_report(y_test, y_pred, zero_division=0))
    
    # step 7: discuss feature importance
    # random forest calculates how much each feature decreases the impurity across all trees
    # higher values indicate more important features
    importances = model.feature_importances_
    
    print("\nfeature importance discussion:")
    print("the importance score tells us how useful a specific feature is for predicting the target variable.")
    print("the higher the score, the more important the feature is in the decision-making process of the forest.\n")
    
    # map features to their importances and sort them
    feature_importance_df = pd.DataFrame({'feature': feature_names, 'importance': importances})
    feature_importance_df = feature_importance_df.sort_values(by='importance', ascending=False)
    
    for index, row in feature_importance_df.iterrows():
        print(f"feature: '{row['feature']}', importance score: {row['importance']:.4f}")

if __name__ == "__main__":
    main()
