def accept(A):
    n=int(input("Enter total no. of students : "))
    for i in range(n):
        x = float(input("Enter percent od student %d :"%(i+1)))
        A.append(x)
    print("Data accepted successfully!")

def display(A):
    n=len(A)
    if(n==0):
        print("No data")
    else:
        print("Marks : ",end=' ')
        for i in range(n):
            print(A[i],end=' ')
        print("\n")

def Selection_sort(A):
    n = len(A)
    for i in range(n-1):
        min_ind = i
        for j in range(i+1,n):
            if(A[j]<A[min_ind]):
                min_ind=j
        if(min_ind!=i):
            temp = A[i]
            A[i] = A[min_ind]
            A[min_ind] = temp

def Bubble_sort(A):
    n = len(A)
    for i in range(1,n):
        flag=0
        for j in range(n-i):
            if(A[j]<A[j+1]):
                temp = A[j]
                A[j] = A[j+1]
                A[j+1] = temp
                flag=1
        if(flag!=1):
            break

def Main():
    A = []
    while True:
        print("1.Accept and display marks.")
        print("2.Selection sort (Ascending order).")
        print("3.Bubble sort(Descending order) and display top 5 scores.")
        print("4.Exit")

        ch = int(input("Enter your choice : "))
        if(ch==1):
            accept(A)
            display(A)
        elif(ch==2):
            print("Marks before sorting")
            display(A)
            Selection_sort(A)
            print("Marks after sorting")
            display(A)
        elif(ch==3):
            print("Marks before sorting")
            display(A)
            Bubble_sort(A)
            print("Marks after sorting")
            display(A)
            if(len(A)>=5):
                print("Top five scores are : ")
                for i in range(5):
                    print(A[i])
        elif(ch==4):
            print("End of program.")
            break
        else:
            print("You entered wrong choice.")

Main()

'''time-O(n^2)
space-O(n)'''