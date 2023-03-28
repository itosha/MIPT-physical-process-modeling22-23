import numpy as np
import matplotlib.pyplot as plt
import subprocess

runFile = 'C:\\Users\\Anton\\PycharmProjects\\MIPT-physical-process-modeling22-23\\4sem\\random wander 1\\bin\\Debug\\random wander 1.exe'


def get_res(runFile, ax, people, num_of_saves, save_step):
    with open("data.txt", 'w') as fail:
        fail.write(people + '   ' + num_of_saves + '    ' + save_step)

    process = subprocess.run(runFile)
    resaults = np.loadtxt("table.txt")[0]
    return ax.hist(resaults, 200, range=(0, 200), density=True, histtype='step', label=str)


fig, ax = plt.subplots()

get_res(runFile, ax, 100, 5, 5)

plt.legend()
ax.set_xlabel('Smarts')
ax.set_ylabel('Probability density')
ax.set_title(r'Histogram of IQ: $\mu=$, $\sigma=$')

# Tweak spacing to prevent clipping of ylabel
fig.tight_layout()
plt.show()
