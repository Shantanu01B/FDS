def accept_data(A,str):
    n=int(input("Enter number of students who play %s : "%str))
    for i in range(n):
        name=input("Enter the name of student %d : "%(i+1))
        A.append(name)


def show_data(A,str):
    n=len(A)
    print("Students who play %s : {"%str,end="")
    if (n==0):
        print("None}")
    else:
        for i in range(n-1):
            print(A[i],end=",")
        print("%s}"%A[n-1])
    
def intersection(A,B,C):
    for i in range(len(A)):
        flag=search(A[i],B)
        if flag==1:
            C.append(A[i])

    
def union(A,B,C):
    for i in range(len(A)):
        C.append(A[i])
    n=len(B)
    for i in range(n):
        flag=search(B[i],A)
        if flag==0:
            C.append(B[i])

def subtraction(A,B,C):
    for i in range(len(A)):
        flag=search(A[i],B)
        if flag==0:
            C.append(A[i])
    
        
def search(key,A):
    n=len(A)
    for i in range(n):
        if key==A[i]:
            return 1
    return 0


def main():
    group_A=[]
    group_B=[]
    group_C=[]
    CnB=[]
    CuB=[]
    CrB=[]
    CuF=[]
    nCnB=[]
    CFnB=[]
    while True:
        print("1.Accept Information")
        print("\n2.List of student who play both cricket and badminton.")
        print("\n3.List of student who either play cricket or badminton but not both")
        print("\n4.List of student who neither play cricket nor badminton")
        print("\n5.Number of student who play cricket and football but not badminton")
        print("\n6.Exit")
        
        ch = int(input("Enter your choice : "))
        
        if(ch==1):
            accept_data(group_A,"cricket")
            show_data(group_A,"cricket")
            
            accept_data(group_B,"badminton")
            show_data(group_B,"badminton")
            
            accept_data(group_C,"football")
            show_data(group_C,"football")
        elif(ch==2):
            intersection(group_A,group_B,CnB)
            show_data(CnB,"both cricket and badminton.")
        elif(ch==3):
            intersection(group_A,group_B,CnB)
            union(group_A,group_B,CuB)
            subtraction(CuB,CnB,CrB)
            show_data(CrB,"either play cricket or badminton but not both")
        elif(ch==4):
            union(group_A,group_B,CuB)
            subtraction(group_C,CuB,nCnB)
            show_data(nCnB,"neither play cricket or badminton")
        elif(ch==5):
            union(group_A,group_C,CuF)
            subtraction(group_B,CuF,CFnB)
            show_data(CFnB,"play cricket and football but not badminton")
        elif(ch==6):
            print("End of program.")
            break;
        else:
            print("you entered wrong choice")
            
main()
        
'''O(n1+n2*k+n3*k)best'''
'''O(n^2)'''