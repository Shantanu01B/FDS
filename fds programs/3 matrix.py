def main():
    while True:
        print("Matrix Operations Menu:")
        print("1. Accept Matrices")
        print("2. Display Matrices")
        print("3. Add Matrices")
        print("4. Subtract Matrices")
        print("5. Multiply Matrices")
        print("6. Transpose Matrices")
        print("7. Exit")
        
        choice = int(input("Enter your choice: "))

        if choice == 1:
            row1 = int(input("Enter total number of rows for matrix 1: "))
            col1 = int(input("Enter total number of columns for matrix 1: "))
            m1 = []
            print("First matrix:")
            res = accept(row1, m1, col1)
            
            row2 = int(input("Enter total number of rows for matrix 2: "))
            col2 = int(input("Enter total number of columns for matrix 2: "))
            m2 = []
            print("Second matrix:")
            res1 = accept(row2, m2, col2)
            
        elif choice == 2:
            print("Matrix 1:")
            display(row1, res, col1)
            print("Matrix 2:")
            display(row2, res1, col2)
            
        elif choice == 3:
            add(row1, res, col1, res1, row2, col2)
            
        elif choice == 4:
            sub(row1, res, col1, res1, row2, col2)
            
        elif choice == 5:
            mul(row1, col1, row2, col2, res, res1)
            
        elif choice == 6:
            print("Transpose of Matrix 1:")
            transpose(res)
            print("Transpose of Matrix 2:")
            transpose(res1)
            
        elif choice == 7:
            print("Exiting program.")
            break
            
        else:
            print("Invalid choice. Please enter a valid option.")


def accept(row, m, col):
    for i in range(0, row):
        x = []
        for j in range(0, col):
            x.append(int(input("Enter element: ")))
        m.append(x)
    return m


def display(row, res, col):
    print("\n")
    for i in range(0, row):
        for j in range(0, col):
            print(res[i][j], end=" ")
        print("\n")


def add(row1, res, col1, res1, row2, col2):
    if row1 == row2 and col1 == col2:
        print("Addition of two matrices:")
        for i in range(0, row1):
            for j in range(0, col1):
                print(res[i][j] + res1[i][j], end=" ")
            print("\n")
    else:
        print("Number of rows and columns are different, so addition is not possible.")


def sub(row1, res, col1, res1, row2, col2):
    if row1 == row2 and col1 == col2:
        print("Subtraction of two matrices:")
        for i in range(0, row1):
            for j in range(0, col1):
                print(res[i][j] - res1[i][j], end=" ")
            print("\n")
    else:
        print("Number of rows and columns are different, so subtraction is not possible.")


def mul(row1, col1, row2, col2, res1, res2):
    if col1 == row2:
        result = []
        print("Multiplication of matrices:")
        for i in range(0, row1):
            row = []
            for k in range(0, col2):
                element = 0
                for j in range(0, col1):
                    element += res1[i][j] * res2[j][k]
                row.append(element)
            result.append(row)

        for row in result:
            for element in row:
                print(element, end=" ")
            print()
    else:
        print("Multiplication is not possible due to incompatible dimensions.")


def transpose(matrix):
    tran = []
    for i in range(len(matrix[0])):
        r = []
        for j in range(len(matrix)):
            r.append(matrix[j][i])
        tran.append(r)
    
    print("Transpose of the matrix:")
    for row in tran:
        for element in row:
            print(element, end=" ")
        print()


# Call the main function to run the program
main()


'''time-O(r1*c1*c2)
space-O(r1*c1+r2*c2+r1*c2)'''