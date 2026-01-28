import random
n = int(input("enter a matrix size for n x n multiplication"))
matrix1 = [[random.randint(1, 100) for _ in range(n)] for _ in range(n)]
print("----------MATRIX1-----------")
for row in matrix1:
    print(row)
matrix2 = [[random.randint(1, 100) for _ in range(n)] for _ in range(n)]
print("----------MATRIX2-----------")
for row in matrix2:
    print(row)
result = [[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        for k in range(n):
            result[i][j] += matrix1[i][k] * matrix2[k][j]
print("---------RESULT----------")
for row in result:
    print(" ".join(f"{num:6}" for num in row))
print("------------------Problem 2--------------------")
a = input("Please enter a last name to be compared lexicographically")
smallest = a
largest = a
last = a
while True:
    a = input("Please enter a last name to be compared lexicographically")
    if a == "*":
        break
    elif a > largest:
        largest = a
    elif a < smallest:
        smallest = a 
    last = a 
print(f"Largest:  {largest}")
print(f"smallest: {smallest}")
print(f"last:  {last}")
    