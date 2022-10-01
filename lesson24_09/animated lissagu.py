import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation

fig, ax = plt.subplots()
xdata, ydata = [], []
ln, = plt.plot([], [], 'ro')
phase_shift = np.pi
a = 3
b = 4


def init():
    ax.set_xlim(-1, 1)
    ax.set_ylim(-1, 1)
    return ln,


def update(frame):
    xdata.append(np.sin(a*frame + phase_shift))
    ydata.append(np.sin(b*frame))
    ln.set_data(xdata, ydata)
    return ln,


ani = FuncAnimation(fig, update, frames=np.linspace(0, 10, 1001), init_func=init, blit=True, interval=10)
plt.show()
