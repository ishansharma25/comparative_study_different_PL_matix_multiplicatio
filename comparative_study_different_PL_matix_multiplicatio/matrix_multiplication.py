import numpy as np
import time
n= int(input("Enter row: "))
m = int(input("Enter col: "))

# Take user input for matrix A
print("Enter elements for matrix A (3x3):")
A = []
for i in range(n):
    row = []
    for j in range(m):
        element = int(input(f"Enter element ({i+1},{j+1}): "))
        row.append(element)
    A.append(row)

# Take user input for matrix B
print("Enter elements for matrix B (3x4):")
B = []
for i in range(n):
    row = []
    for j in range(m):
        element = int(input(f"Enter element ({i+1},{j+1}): "))
        row.append(element)
    B.append(row)

# Perform matrix multiplication
start_time = time.time()
result = np.dot(A, B)
end_time = time.time()

# Print the result
print("Result:")
for row in result:
    print(row)

execution_time = end_time - start_time
print("Execution time:", execution_time)
