import numpy as np
import matplotlib.pyplot as plt
import subprocess

runFile = 'C:\\Users\\Anton\\PycharmProjects\\MIPT-physical-process-modeling22-23\\4sem\\random3\\bin\\Debug\\random3.exe'


def get_res(runFile, ax, str):
    with open("data.txt", 'w') as fail:
        fail.write(str)

    process = subprocess.run(runFile)
    resaults = np.loadtxt("table.txt")
    return ax.hist(resaults, 200, range=(0, 200), density=True, histtype='step', label=str)


fig, ax = plt.subplots()

get_res(runFile, ax, '0 0 0')
get_res(runFile, ax, '0 1 1')
get_res(runFile, ax, '1 0 1')

plt.legend()
ax.set_xlabel('Smarts')
ax.set_ylabel('Probability density')
ax.set_title(r'Histogram of IQ: $\mu=$, $\sigma=$')

# Tweak spacing to prevent clipping of ylabel
fig.tight_layout()
plt.show()
