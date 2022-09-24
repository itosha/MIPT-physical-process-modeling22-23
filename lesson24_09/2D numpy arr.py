import numpy as np

n = 7

arr = np.zeros((n, n), int)
source = np.array([-1, 2, -1])
arr[0] = np.hstack([source[1:], np.zeros(n-2)])
for i in range(1, n-1, 1):
    arr[i] = np.hstack([np.hstack([np.zeros(i-1), source]), np.zeros(n-2-i)])
arr[n-1] = np.hstack([np.zeros(n-2), source[1:]])
print(arr)
