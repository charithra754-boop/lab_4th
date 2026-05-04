"""
question 10: k-nearest neighbour (knn) algorithm.
this script implements the knn algorithm to classify the iris dataset.
it prints both correct and wrong predictions as requested.
we use the sklearn library as permitted by the instructions.
"""

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score

def main():
    # step 1: load the iris dataset
    # iris is a classic dataset containing features of iris flowers (sepal length/width, petal length/width)
    iris = load_iris()
    x = iris.data
    y = iris.target
    class_names = iris.target_names
    
    # step 2: split the data into training and test sets
    # using a smaller test set to easily print the correct and wrong predictions
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)
    
    # step 3: initialize the knn classifier
    # k=3 means we look at the 3 nearest neighbors to determine the class
    k = 3
    knn = KNeighborsClassifier(n_neighbors=k)
    
    # step 4: train the classifier using the training data
    knn.fit(x_train, y_train)
    
    # step 5: make predictions on the test set
    predictions = knn.predict(x_test)
    
    # step 6: evaluate the predictions and print correct/wrong ones
    print(f"knn classification results (k={k}):\n")
    correct_count = 0
    wrong_count = 0
    
    for i in range(len(y_test)):
        actual_class = class_names[y_test[i]]
        predicted_class = class_names[predictions[i]]
        
        # compare predicted vs actual
        if predictions[i] == y_test[i]:
            print(f"correct prediction: actual={actual_class}, predicted={predicted_class}")
            correct_count += 1
        else:
            print(f"wrong prediction:   actual={actual_class}, predicted={predicted_class}")
            wrong_count += 1
            
    # calculate and print overall accuracy
    accuracy = accuracy_score(y_test, predictions)
    print(f"\nsummary:")
    print(f"total correct: {correct_count}")
    print(f"total wrong: {wrong_count}")
    print(f"accuracy: {accuracy * 100:.2f}%")

if __name__ == "__main__":
    main()
