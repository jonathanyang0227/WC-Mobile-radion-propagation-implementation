from matplotlib import pyplot as plt

b = open("best.txt", "r")
t = open("threshold.txt", "r")
e= open("entropy.txt", "r")
myPolicy = open("my.txt", "r")

x = []
y = []

for i in b:
    dot = i.split()
    x.append(int(dot[0]))
    y.append(int(dot[1]))

plt.plot(x, y, color="r", label="my poloicy")

# x = []
# y = []

# for i in t:
#     dot = i.split()
#     x.append(int(dot[0]))
#     y.append(int(dot[1]))

# plt.plot(x, y, color="g", label="threshold policy")

# x = []
# y = []

# for i in e:
#     dot = i.split()
#     x.append(int(dot[0]))
#     y.append(int(dot[1]))

# plt.plot(x, y, color="y", label="entropy policy")

# x = []
# y = []

# for i in myPolicy:
#     dot = i.split()
#     x.append(int(dot[0]))
#     y.append(int(dot[1]))

# plt.plot(x, y, color="k", label="my policy")
plt.xlabel("second")
plt.ylabel("#handoff")
plt.legend(loc="best")
plt.show()