def accept_data(A):
	n=int(input("\nEnter number of students : "))
	for i in range(n):
		marks=input("Enter marks(out of 30) of student %d : "%(i+1))
		if(marks=='AB'):
			A.append(-1)
		else:
			marks=int(marks)
			if(marks>0 and marks<=30):
				A.append(marks)
			else:
				print("You entered marks greater than 30 or less than 0")
		
def display_data(A):
	n=len(A)
	for i in range(n):
		if A[i]==-1:
			print("AB")
		else:
			print("Student",(i+1)," : ",A[i])
	
def avg(A):
	n=len(A)
	sum=0
	for i in range(n):
		if A[i]!=-1:
			sum=sum+A[i]
	avg=sum/n
	print("\nAverage score of class is : ",avg)
		
def highestnlowest(A):
	max=0
	for i in range(len(A)):
		if(max<A[i]):
			max=A[i]
	print("\nHighest score of class is : ",max)
	min=A[0]
	for i in range(len(A)):
		if(A[i]<min):
			min=A[i]
	print("\nLowest score of class is : ",min)

def absent_students(A):
	count=0
	for i in range(len(A)):
		if A[i]==-1:
			count=count+1
	print("\nTotal number of absent students are : ",count)

def highest_freq(A):
	freq=0
	for i in range(len(A)):
		count=0
		for j in range(len(A)):
			if A[i]==A[j]:
				count=count+1
		if freq<count:
			freq=count
			marks=A[i]
	print("\nMarks with highest frequecy are : ",marks," scores by ",freq," students.")

def main():
	students=[]
	while True:
		print("\n1.Accept Information.")
		print("\n2.Average score of class.")
		print("\n3.Highest and Lowest marks of class.")
		print("\n4.Count of students who where absent for test.")
		print("\n5.Display marks with highest frequency.")
		print("\n6.Exit.")
	
		choice=int(input("\nEnter your choice : "))
	
		if choice==1:
			accept_data(students)
			display_data(students)
		elif choice==2:
			avg(students)
		elif choice==3:
			highestnlowest(students)
		elif choice==4:
			absent_students(students)
		elif choice==5:
			highest_freq(students)
		elif choice==6:
			print("\nEnd of program.")
			break;
		else:
			print("\nINVALID INPUT.\n")

main()

'''time comp- best O(n) same space comp '''
