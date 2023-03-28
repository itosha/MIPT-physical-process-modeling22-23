import numpy as np
import matplotlib.pyplot as plt
import subprocess

runFile = 'C:\\Users\\Anton\\PycharmProjects\\MIPT-physical-process-modeling22-23\\4sem\\alpha param\\bin\\Debug\\alpha param.exe'


def get_res_plot(runFile, ax, y0, alpha):
    process = subprocess.Popen([runFile, y0, alpha])
    c = process.communicate()
    resaults = np.loadtxt("table.txt")
    x = np.loadtxt("table2.txt")
    #x = [i for i in range(len(resaults))]
    return plt.plot(x, resaults, label=alpha)


def get_res_scatter(runFile, ax, y0, alpha):
    process = subprocess.Popen([runFile, y0, alpha])
    c = process.communicate()
    resaults = np.loadtxt("table.txt")
    x = np.loadtxt("table2.txt")
    #x = [i for i in range(len(resaults))]
    return plt.scatter(x, resaults, marker=".", linewidths=0.1, label=alpha)


fig, ax = plt.subplots()
#get_res(runFile, ax, '0.1', '1')
#get_res_plot(runFile, ax, '0.1', '3')
get_res_scatter(runFile, ax, '0.1', '3.4')
#get_res(runFile, ax, '0.1', '4')
plt.legend()

ax.set_xlabel('N')
ax.set_ylabel('Y')

# Tweak spacing to prevent clipping of ylabel
fig.tight_layout()
plt.show()
