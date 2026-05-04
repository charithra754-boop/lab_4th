import pandas as pd

def find_s(training_data):
    hypothesis = None

    for example in training_data:
        features = example[:-1]
        label = example[-1]

        if label == "Yes":
            if hypothesis is None:
                hypothesis = features.copy()
            else:
                for i in range(len(hypothesis)):
                    if hypothesis[i] != features[i]:
                        hypothesis[i] = "?"

    return hypothesis


# 🔹 Read CSV using Pandas
df = pd.read_csv("findsfinal.csv")

# 🔹 Convert DataFrame to list of lists
training_data = df.values.tolist()

# 🔹 Run Find-S
result = find_s(training_data)

print("Final Hypothesis:", result)