import numpy
import numpy as np
import matplotlib.pyplot as plt
import math
import subprocess


Phi0 = 3
PhiV = 1
Y0 = 0
g = 9.8
a = 0.9
nu = 220
L = 2
dt = 0.01
number = 10000

with open("data.txt", 'w') as fail:
    fail.write(str(Phi0) + '\n' + str(PhiV) + '\n' + str(Y0) + '\n' + str(g) + '\n' + str(a)
               + '\n' + str(nu) + '\n' + str(L) + '\n' + str(dt) + '\n' + str(number))

process = subprocess.run('C:\\Users\\Anton\\PycharmProjects\\MIPT-physical-process-modeling22-23\\generic algorithms\\Kapitsa bob\\bin\\Debug\\Kapitsa bob.exe')
print("\n", process)
y = np.zeros(number, float)
phi = np.zeros(number, float)

with open("table.txt", 'r') as f:
    for i in range(len(y)):
        y[i] = float(list(f.readline().split())[0])

with open("Vtable.txt", 'r') as f:
    for i in range(len(phi)):
        phi[i] = float(list(f.readline().split())[0])

t = np.arange(0, len(y) * dt, dt)

xpos = np.zeros(number, float)
ypos = np.zeros(number, float)

xpos = L * numpy.sin(phi)
ypos = y - L * numpy.cos(phi)

plt.plot(xpos, ypos)
plt.xlabel(r'$X(t)$', fontsize=16)
plt.ylabel(r'$Y(t)$', fontsize=16)
plt.grid(True)

"""fig, axs = plt.subplots(2, 2)
ax = axs.reshape(1, 4)

ax[0][0].plot(t, y, label="хитрая симмуляциия")
#ax[0][0].plot(t, y, label="теория")
ax[0][0].legend(loc='best', fontsize=12)
ax[0][0].set_xlabel(r'$t, время$', fontsize=16)
ax[0][0].set_ylabel(r'$Y_подвеса$', fontsize=16)
ax[0][0].grid(True)

ax[0][2].plot(xpos, ypos)
ax[0][2].set_xlabel(r'$X(t)$', fontsize=16)
ax[0][2].set_ylabel(r'$Y(t)$', fontsize=16)
ax[0][2].grid(True)

ax[0][3].plot(phi, y)
ax[0][3].set_xlabel(r'$phi(t)$', fontsize=16)
ax[0][3].set_ylabel(r'$Y(t)$', fontsize=16)
ax[0][3].grid(True)
"""
plt.show()
