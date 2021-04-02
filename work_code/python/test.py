import matplotlib.pyplot as plt
import numpy

fig = plt.figure()
x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]
plt.plot(x, y)
plt.plot(y, x)
plt.show()