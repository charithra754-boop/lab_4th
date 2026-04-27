import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv("kmeans.csv.csv")
X = df.iloc[:, :2].values

k = 3
centroids = X[:k]


for _ in range(10):
    clusters = [[] for _ in range(k)]

   
    for x in X:
        distances = [np.linalg.norm(x - c) for c in centroids]
        cluster_index = np.argmin(distances)
        clusters[cluster_index].append(x)

    new_centroids = []
    for cluster in clusters:
        new_centroids.append(np.mean(cluster, axis=0))
    centroids = np.array(new_centroids)


for i, cluster in enumerate(clusters):
    cluster = np.array(cluster)
    plt.scatter(cluster[:, 0], cluster[:, 1])


plt.scatter(centroids[:, 0], centroids[:, 1], marker='X', s=200)
plt.title("K-Means Clustering")
plt.xlabel("Feature 1")
plt.ylabel("Feature 2")
plt.show()