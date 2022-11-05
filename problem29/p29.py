p = set()
for i in range(2, 101):
    for j in range(2, 101):
        p.add(i ** j)
print(len(p))
