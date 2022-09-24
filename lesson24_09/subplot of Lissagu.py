import matplotlib.pyplot as plt
import numpy as np
import math as m
fig, axs = plt.subplots(2, 2)
t = np.arange(0, 200, 0.1)
phase_shift = m.pi
ax = axs.reshape(1, 4)
for i in range(1, 5, 1):
    a = i
    b = i + 1
    x = np.sin(a*t + phase_shift)
    y = np.sin(b*t)
    ax[0][i-1].plot(x, y)
plt.show()

