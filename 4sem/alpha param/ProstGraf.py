import numpy as np
import matplotlib.pyplot as plt
import subprocess

runFile = 'C:\\Users\\Anton\\PycharmProjects\\MIPT-physical-process-modeling22-23\\4sem\\alpha param\\bin\\Debug\\alpha param.exe'


def get_res_plot(runFile, y0, alpha):
    process = subprocess.Popen([runFile, y0, alpha])
    c = process.communicate()
    resaults = np.loadtxt("table.txt")
    x = np.loadtxt("table2.txt")
    plt.plot(x, resaults, label=alpha)
    plt.legend()
    return 0


def get_res_scatter(runFile, y0, alpha):
    process = subprocess.Popen([runFile, y0, alpha])
    c = process.communicate()
    resaults = np.loadtxt("table.txt")
    x = np.loadtxt("table2.txt")
    #x = [i for i in range(len(resaults))]
    plt.scatter(x, resaults, marker=".", linewidths=0.1, label=alpha)
    plt.legend()
    return 0


def get_res_scatter_2(runFile, y0, y_num, alpha_0, alpha_end, step, y_graf_start, y_graf_stop, color='blue'):
    process = subprocess.Popen([runFile, y0, y_num, alpha_0, alpha_end, step])
    c = process.communicate()
    resaults = np.loadtxt("Alp_table.txt")
    resaults = resaults.transpose()
    x = resaults[0]
    for i in range(y_graf_start, y_graf_stop):
        plt.scatter(x, resaults[i], marker=".", linewidths=0.1, color=color)


fig, ax = plt.subplots()
#get_res(runFile, '0.1', '1')
#get_res_plot(runFile, '0.1', '3')
#get_res_scatter(runFile, '0.1', '3.3')
get_res_scatter_2(runFile, '0.1', '2000', '3', '4', '0.01', 1800, 1900)


ax.set_xlabel('N')
ax.set_ylabel('Y')

# Tweak spacing to prevent clipping of ylabel
fig.tight_layout()
plt.show()
