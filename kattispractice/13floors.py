def floors(x):
    if x <= 12:
        return x
    else:
        return x + 1
y = int(input())
print(floors(y))