import pandas as pd

def ce(data):
    S = None
    G = [["?"] * (len(data[0]) - 1)]

    for row in data:
        x = row[:-1]
        y = row[-1]

        if y == "Yes":
            if S is None:
                S = x.copy()
            else:
                for i in range(len(S)):
                    if S[i] != x[i]:
                        S[i] = "?"

            G = [g for g in G if all(g[i] == x[i] or g[i] == "?" for i in range(len(g)))]

        else:
            new_G = []
            for g in G:
                for i in range(len(g)):
                    if g[i] == "?":
                        if S is not None and S[i] != "?":
                            new_h = g.copy()
                            new_h[i] = S[i]
                            if new_h not in new_G:
                                new_G.append(new_h)
            G = new_G

    return S, G


df = pd.read_csv("findsfinal.csv")
data = df.values.tolist()

s, g = ce(data)

print("S:", s)
print("G:", g)