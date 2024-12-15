#include<iostream>
using namespace std;

#define size 10

class pizza_parlour
{
	private:
		int front;
		int rear;
		int A[size];
	public:
		pizza_parlour()
		{
			front=-1;
			rear=-1;
		}
		bool isEmpty();
		bool isFull();
		void enqueue(int x);
		int dequeue();
		void displayQueue();
};

bool pizza_parlour::isEmpty()
{
	if(front==-1) return 1;
	else return 0;
}

bool pizza_parlour::isFull()
{
	if((front==0&&rear==size-1)||(front==rear+1)) return 1;
	else return 0;
}

void pizza_parlour::enqueue(int x)
{
	if(isFull()) 
	{
		cout<<"Queue is Full."<<endl;
		return;
	}
	
	if(front==-1)
	{
		front=rear=0;
		A[rear]=x;
	}
	else if(rear==size-1&&front!=0)
	{
		rear=0;
		A[rear]=x;
	}
	else
	{
		rear++;
		A[rear]=x;
	}
}

int pizza_parlour::dequeue()
{
	if(isEmpty()) cout<<"Queue is Empty."<<endl;
	int x=A[front];
	A[front]=-1;
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==size-1) front=0;
	else front++;
	return x;
}

void pizza_parlour::displayQueue()
{
	if(isEmpty()) cout<<"Queue is empty."<<endl;
	else if(rear>=front)
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(int i=front;i<size;i++)
		{
			cout<<A[i]<<" ";
		}
		for(int i=0;i<=rear;i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	pizza_parlour p;
	p.displayQueue();
	p.enqueue(10);
	p.enqueue(20);
	p.enqueue(40);
	p.displayQueue();
	p.dequeue();
	p.displayQueue();
}
'''Time Complexity:

O(1) for enqueue and dequeue operations.
O(n) for displayQueue, where n is the number of elements in the queue.
Space Complexity: O(1), as the space used is constant due to the fixed size of the array.'''