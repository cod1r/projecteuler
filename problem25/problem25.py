import math
x = 1
y = 1
counter = 2
while math.log10(y) < 999:
    counter += 1
    z = x + y
    x = y
    y = z
print(counter)
print(math.log10(y))
