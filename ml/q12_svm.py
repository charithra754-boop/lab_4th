"""
question 12: support vector machine (svm) on mnist dataset.
this script builds an svm classifier to classify handwritten digits from a subset of the mnist dataset,
and compares different kernels.
"""

from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, classification_report
import time

def main():
    # step 1: load the digits dataset
    # we use sklearn's digits dataset, which is a smaller, lower-resolution version of mnist
    # this allows the code to run quickly for the lab experiment
    digits = datasets.load_digits()
    x = digits.data
    y = digits.target
    
    # step 2: split the data into training and testing sets
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=42)
    
    # step 3: experiment with different kernels
    # kernels transform the data into a higher dimension where it might be linearly separable
    # 'linear' is a straight line/plane
    # 'rbf' (radial basis function) is non-linear and handles complex boundaries well
    # 'poly' is a polynomial kernel
    kernels = ['linear', 'poly', 'rbf']
    results = {}
    
    for kernel in kernels:
        print(f"\ntraining svm with '{kernel}' kernel...")
        start_time = time.time()
        
        # initialize and train the svm classifier
        # c is the regularization parameter. smaller c = wider margin but more misclassifications
        # gamma defines how far the influence of a single training example reaches
        model = SVC(kernel=kernel, C=1.0, gamma='scale', random_state=42)
        model.fit(x_train, y_train)
        
        # make predictions and evaluate
        y_pred = model.predict(x_test)
        accuracy = accuracy_score(y_test, y_pred)
        training_time = time.time() - start_time
        
        # store results
        results[kernel] = {
            'accuracy': accuracy,
            'time': training_time
        }
        
        print(f"accuracy: {accuracy * 100:.2f}% ভিট")
        print(f"training time: {training_time:.2f} seconds")
        
    # step 4: discuss the results
    print("\n--- conclusion & discussion ---")
    print("impact of different kernels on classification accuracy:")
    for kernel, data in results.items():
        print(f"- {kernel} kernel: achieved {data['accuracy']*100:.2f}% accuracy.")
        
    print("\ndiscussion:")
    print("the rbf (radial basis function) kernel usually performs best on complex image data like mnist ")
    print("because it can map non-linear relationships by creating a non-linear decision boundary.")
    print("the linear kernel works well only if the classes are linearly separable in the original space, ")
    print("which is often not the case for images. the poly kernel is another non-linear option but ")
    print("can be sensitive to the choice of its degree parameter.")

if __name__ == "__main__":
    main()
