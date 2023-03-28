import numpy as np
import matplotlib.pyplot as plt
import math
import subprocess


def func(x, a, b, c):
    return 1
    # return a * math.cos(c*x) + b * math.sin(c*x)


X0 = 0
V0 = 3
T0 = 0
omega = 0.5
gamma = 0.1
A = 1
omega2 = 1.5
dt = 0.01
number = 100000

with open("data.txt", 'w') as fail:
    fail.write(str(X0) + '\n' + str(V0) + '\n' + str(T0) + '\n' + str(omega)
               + '\n' + str(gamma) + '\n' + str(A) + '\n' + str(omega2) + '\n' + str(dt) + '\n' + str(number))

process = subprocess.run('C:\\Users\\Anton\\PycharmProjects\\MIPT-physical-process-modeling22-23\\generic algorithms\\damped bob 2\\bin\\Debug\\damped bob 2.exe')
print("\n", process)
z = np.zeros(number, float)
v = np.zeros(number, float)
energy = np.zeros(number, float)

with open("table.txt", 'r') as f:
    for i in range(len(z)):
        z[i] = float(list(f.readline().split())[0])

with open("Vtable.txt", 'r') as f:
    for i in range(len(v)):
        v[i] = float(list(f.readline().split())[0])

with open("EnergyTable.txt", 'r') as f:
    for i in range(len(energy)):
        energy[i] = float(list(f.readline().split())[0])

t = np.arange(0, len(z) * dt, dt)

# print(len(z), len(t), type(t[0]), type(z[0]))

# z = z[:20000]
# t = t[:20000]

# popt, pcov = curve_fit(func, x, y)

y = [func(i, X0, V0, omega) for i in t]

errorBar = np.abs(z - y)

fig, axs = plt.subplots(2, 2)
ax = axs.reshape(1, 4)

ax[0][0].plot(t, z, label="хитрая симмуляциия")
#ax[0][0].plot(t, y, label="теория")
ax[0][0].legend(loc='best', fontsize=12)
ax[0][0].set_xlabel(r'$t, время$', fontsize=16)
ax[0][0].set_ylabel(r'$X$', fontsize=16)
ax[0][0].grid(True)


#ax[0][1].plot(t, errorBar)
#ax[0][1].set_xlabel(r'$t, время$', fontsize=16)
#ax[0][1].set_ylabel(r'$|X - X_{теор}|$', fontsize=16)
ax[0][1].grid(True)

ax[0][2].plot(z, v)
ax[0][2].set_xlabel(r'$X(t)$', fontsize=16)
ax[0][2].set_ylabel(r'$V(t)$', fontsize=16)
ax[0][2].grid(True)

ax[0][3].plot(t, energy)
ax[0][3].set_xlabel(r'$t$', fontsize=16)
ax[0][3].set_ylabel(r'$E_{пол}$', fontsize=16)
ax[0][3].grid(True)
plt.show()
