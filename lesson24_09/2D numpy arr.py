import numpy as np

n = 6

arr = np.zeros((n, n))
source = np.array([-1, 2, -1])
arr[0] = np.hstack([source[1:], np.zeros(n-2)])
for i in range(1, n-1, 1):
    arr[i] = np.hstack([np.hstack([np.zeros(i-1), source]), np.zeros(n-2-i)])
arr[n-1] = np.hstack([np.zeros(n-2), source[:-1]])

Y = np.hstack([np.hstack([np.array([100]), np.zeros((n-2))]), np.array([1])]).reshape(n, 1)

matrixEq = np.hstack([arr, Y])
# print(matrixEq)

for i in range(0, n, 1):
    matrixEq[i] = matrixEq[i] / matrixEq[i][i]
    for j in range(0, i, 1):
        matrixEq[j] = matrixEq[j] - matrixEq[j][i] * matrixEq[i]
    for j in range(i + 1, n, 1):
        matrixEq[j] = matrixEq[j] - matrixEq[j][i] * matrixEq[i]
# print(matrixEq)

solution = matrixEq[:, n]
print(solution)
solution = solution.reshape(n, 1)
print(np.dot(arr, solution))
