import matplotlib.pyplot as plt
import numpy as np


def get_points(filename):
    x = []
    y = []
    file = open(filename, 'r')
    data = file.read()

    data = data.replace('\n', ' ')
    data = data.split(" ")
    data.pop(len(data) - 1)
    data.pop(0)
    for i in range(len(data)):
        data[i] = float(data[i])
        if i % 2 == 0:
            x.append(data[i])
        else:
            y.append(data[i])
    file.close()
    return [x, y]


data1 = get_points('/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test1.txt')
data2 = get_points('/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test2.txt')
data3 = get_points('/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test3.txt')
data4 = get_points('/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test4.txt')
data5 = get_points('/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test5.txt')
# print(data1[0], data1[1])
fig = plt.figure()
# k1 = np.polyfit(data1[0], data1[1], 1)
# k2 = np.polyfit(data2[0], data2[1], 1)
# y1 = np.polyval(k1, data1[0])
# y2 = np.polyval(k2, data2[0])
plt.plot(data1[0], data1[1], 'b-')
plt.plot(data2[0], data2[1], 'r-')
# plt.plot(data3[0], data3[1], 'b-')
# plt.plot(data4[0], data4[1], 'b-')
# plt.plot(data5[0], data5[1], 'b-')
plt.grid()
plt.title('STL forward_list VS subforwardlist in push_front()')
plt.xlabel('Size')
plt.ylabel('Average time, mcrs')
plt.legend(['STL forward_list', 'Subforwardlist'])
plt.show()
fig.savefig('test1.png')
