import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit


def getfunc(x, a, b, yerr):
    return a * x + b * np.ones(len(x)) + yerr


def func(x, a, b):
    return a * x + b


np.random.seed(19680801)

mu = 10
sigma = 5
x = np.arange(50)
yerr = mu + sigma * np.random.randn(len(x))

y = getfunc(x, 2, -1, yerr)

plt.errorbar(x, y, fmt='ro', xerr=0, yerr=0)
popt, pcov = curve_fit(func, x, y)

print("Коэфициенты:  ", popt[0], popt[1])

perr = np.sqrt(np.diag(pcov))

print(perr)

y2 = popt[0] * x + popt[1] * np.ones(len(x))
plt.plot(x, y2)
plt.show()
