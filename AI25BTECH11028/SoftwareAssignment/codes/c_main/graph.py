import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("singular_values.txt")
ranks = data[:, 0]
values = data[:, 1]

plt.plot(ranks, values, marker='o')
plt.xlabel("Rank (i)")
plt.ylabel("Singular value σᵢ")
plt.title("Singular Value Decay")
plt.grid(True)
plt.show()
