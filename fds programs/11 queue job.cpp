#include<iostream>
using namespace std;

#define size 10

class queue
{
	private:
		int front;
		int rear;
		int A[size];
	public:
		queue()
		{
			front=-1;
			rear=-1;
		}
		void enqueue(int x);
		int dequeue();
		bool isFull();
		bool isEmpty();
		void displayQueue();
};

bool queue::isFull()
{
	if(rear==size-1) return 1;
	else return 0;
}

bool queue::isEmpty()
{
	if(front==-1) return 1;
	else return 0;
}

void queue::enqueue(int x)
{
	if(isFull()) cout<<"Queue is full."<<endl;
	else if(rear==-1 && front==-1)
	{
		rear++;
		front=0;
		A[rear]=x;
	}
	else
	{
		rear++;
		A[rear]=x;
	}
}

int queue::dequeue()
{
	if(isEmpty()) cout<<"Queue is empty."<<endl;
	else if(front==rear)
	{
		int x=A[front];
		front=-1;
		rear=-1;
		return x;
	}
	else
	{
		int x=A[front];
		front++;
		return x;
	}
}

void queue::displayQueue()
{
	if(isEmpty()) cout<<"Queue is empty."<<endl;
	else
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	queue q;
	int n;
	int jobId;
	while(true)
	{
		cout<<"1.Add Job Id."<<endl;
		cout<<"2.Delete Job Id."<<endl;
		cout<<"3.Display Data."<<endl;
		cout<<"4.Exit."<<endl;
		cout<<endl;
		cout<<"Enter your choice : ";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the job id : ";
				cin>>n;
				q.enqueue(n);
				break;
			case 2:
				jobId=q.dequeue();
				cout<<jobId<<" deleted successfully."<<endl;
				break;
			case 3:
				q.displayQueue();
				break;
			case 4:
				cout<<"End of program."<<endl;
				return 0;
			default:
				cout<<"You entered wrong choice."<<endl;
		}
	}
}
'''Time Complexity:
O(1) for enqueue and dequeue.
O(n) for displayQueue, where n is the number of elements in the queue.
Space Complexity: O(1), as the space used by the array and other variables is constant.
'''