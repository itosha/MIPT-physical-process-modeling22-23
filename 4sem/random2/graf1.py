import numpy
import numpy as np
import matplotlib.pyplot as plt
import math
import subprocess

runFile = 'C:\\Users\\Anton\\PycharmProjects\\MIPT-physical-process-modeling22-23\\4sem\\random2\\bin\\Debug\\random2.exe'

length = 101
N = np.arange(0, length, 1)
probobility = np.zeros(length)

for i in range(length):
    with open("data.txt", 'w') as fail:
        fail.write(str(N[i]))
    process = subprocess.run(runFile)
    with open("table.txt", 'r') as f:
        string = list(f.readline().split())
        res1 = float(string[0])
        res2 = float(string[1])
        probobility[i] = res1 / res2

plt.plot(N, probobility)
plt.xlabel(r'$N$', fontsize=16)
plt.ylabel(r'$P$', fontsize=16)
plt.grid(True)

plt.show()
