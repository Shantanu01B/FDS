def accept(A):
	n = int(input("\nEnter number of people in phonebook : "))
	for i in range(n):
		name = input("\nEnter the name(in alphabetical order): ")
		mobile = int(input("\nEnter the mobile number : "))
		l = [name,mobile]
		A.append(l)
	print("\nData entered successfully.")
	
def display(A):
	n=len(A)
	print("\nPhoneBook\n")
	print("\nSr. No\tName\tMobile No.\n")
	for i in range(n):
		print("\n%d\t%s\t%d\n"%(i+1,A[i][0],A[i][1]))

def BinarySearch(A,key):
	l=0
	h=len(A)-1
	while(l<=h):
		mid=int((l+h)/2)
		if(key==A[mid][0]):
			return mid
		elif(key<A[mid][0]):
			h=mid-1
		else:
			l=mid+1
	return -1
	
def RBinarySearch(A,l,h,key):
	if(l<=h):
		mid=int((l+h)/2)
		if(key==A[mid][0]):
			return mid;
		elif(key<A[mid][0]):
			return RBinarySearch(A,l,mid-1,key)
		else:
			return RBinarySearch(A,mid+1,h,key)
	return -1;

def fibonacci(A,key):
	f2=0
	f1=1
	f3=f1+f2
	n=len(A)
	
	while(f3<n):
		f1=f2
		f2=f3
		f3=f1+f2
	offset=-1
		
	while(f3>0):
		i=min(offset+f1,n-1)
		if(A[i][0]==key):
			return i
		elif(A[i][0]>key):
			f3=f1
			f2=f2-f1
			f1=f3-f2
		else:
			f3=f2
			f2=f1
			f1=f3-f2
			offset=i
	return -1

def insert(A,name):
	n=len(A)
	mobile=int(input("\nEnter mobile number : "))
	L=[name,mobile]
	A.append(L)
	j=n-1
	while(j>=0):
		if(name>=A[j][0]):
			break
		else:
			A[j+1]=A[j]
		j=j-1
	A[j+1]=L

def main():
	PB=[]
	while True:
		print("\n1.Accept data.")
		print("\n2.Display data.")
		print("\n3.Search(non-recursively).")
		print("\n4.Search(recursively).")
		print("\n5.Fibonacci search.")
		print("\n6.Exit.")
	
		ch = int(input("\nEnter your choice : "))
	
		if(ch==1):
			accept(PB)
			
		elif(ch==2):
			display(PB)
			
		elif(ch==3):
			key=input("\nEnter the name to be search : ")
			flag=BinarySearch(PB,key)
			if(flag==-1):
				print("\nName to be searched not found")
				insert(PB,key)
			else:
				print("\nName found at ",flag)
				print("\nName : ",PB[flag][0])
				print("\nMobile : ",PB[flag][1])
			
		elif(ch==4):
			ele=input("\nEnter the name to be search : ")
			index=RBinarySearch(PB,0,len(PB),ele)
			if(index==-1):
				print("\nName to be searched  not found.")
				insert(PB,ele)
			else:
				print("\nName found at ",index)
				print("\nName : ",PB[index][0])
				print("\nMobile : ",PB[index][1])

		elif(ch==5):
			e=input("\nEnter the name to be search : ")
			index = fibonacci(PB,e)
			if(index==-1):
				print("\nName to be searched not found.")
				insert(PB,e)
			else:
				print("\nName found at ",index)
				print("\nName : ",PB[index][0])
				print("\nMobile : ",PB[index][1])
			
		elif(ch==6):
			print("\nEnd of program.")
			break
		else:
			print("\nYou entered wrong choice.")
	
	
	
	
main()
	
'''best-O(1)
worst-O(logn)
space-O(1)'''
'''fibon-time-O(logn)'''