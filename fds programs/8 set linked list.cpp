#include <iostream>
using namespace std;

struct node
{
	node *prev;
	bool data;
	node *next;
};

typedef struct node node;

class binary
{
private:
	node *head;
	node *last;
	bool carry;

public:
	binary()
	{
		head = NULL;
		last = NULL;
		carry = 0;
	}
	~binary();
	void create_binary();
	void display_binary();
	void add_node_at_end(bool);
	void ones_complement();
	void add_node_at_start(bool);
	void binary_addition(binary &b);
	void twos_complement();
};

binary::~binary()
{
	node *temp1, *temp2;
	temp1 = head;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
	}
	cout << "Destructor called." << endl;
}

void binary::add_node_at_end(bool b)
{
	node *n = new node;
	node *temp;
	n->data = b;
	n->prev = NULL;
	n->next = NULL;
	if (head == NULL)
	{
		head = n;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;
		n->prev = temp;
	}
}

void binary::twos_complement()
{
	binary b;
	node *temp=last;
	int carry=1;
	while(temp!=NULL)
	{
		if(carry==1)
		{
			if(temp->data==0)
				b.add_node_at_start(0);
			else
			{
				b.add_node_at_start(1);
				carry=0;
			}
		}
		else
		{
			if(temp->data==1)
				b.add_node_at_start(0);
			else
				b.add_node_at_start(1);
		}
		temp=temp->prev;
	}
	cout<<"Two's Complement is : ";
	b.display_binary();
}

void binary::binary_addition(binary &b)
{
	binary new_binary;
	bool bit;
	node *temp1 = last;
	node *temp2 = b.last;
	while (temp1 != NULL&&temp2 != NULL)
	{
		if (carry == 0)
		{
			if (temp1->data == 0 && temp2->data == 0)
			{
				bit = 0;
			}
			else if (temp1->data == 1 && temp2->data == 1)
			{
				bit = 0;
				carry = 1;
			}
			else
			{
				bit = 1;
			}
		}

		else
		{
			if (temp1->data == 0 && temp2->data == 0)
			{
				bit = 1;
				carry = 0;
			}
			else if (temp1->data == 1 && temp2->data == 1)
			{
				bit = 1;
			}
			else
			{
				bit = 0;
			}
		}

		new_binary.add_node_at_start(bit);
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	while(temp1!=NULL){
		if(carry==1){
			if(temp1->data==0)
				new_binary.add_node_at_start(1);
			else{
				new_binary.add_node_at_start(0);
				carry=1;
			}
		}
		else{
			bit=temp1->data;
			new_binary.add_node_at_start(bit);
		}
		temp1=temp1->prev;
	}
	while(temp2!=NULL){
		if(carry==1){
			if(temp2->data==0)
				new_binary.add_node_at_start(1);
			else{
				new_binary.add_node_at_start(0);
				carry=1;
			}
		}
		else{
			bit=temp2->data;
			new_binary.add_node_at_start(bit);
		}
		temp2=temp2->prev;
	}
	if(carry){
		new_binary.add_node_at_start(1);
	}
	cout<<"\nAddition of binary numbers is : ";
	new_binary.display_binary();
}

void binary::ones_complement()
{
	binary b2;
	node *temp = head;
	while (temp != NULL)
	{
		if (temp->data == 1)
			b2.add_node_at_end(0);
		else
			b2.add_node_at_end(1);
		temp = temp->next;
	}
	cout << "One's complement of binary number is : ";
	b2.display_binary();
}

void binary::add_node_at_start(bool b)
{
	node *n = new node;
	n->prev = NULL;
	n->next = head;
	n->data = b;
	if (head != NULL)
	{
		head->prev = n;
	}
	else
	{
		last = n;
	}
	head = n;
}

void binary::create_binary()
{
	int n;
	cout << "\nEnter number of bits of binary number : ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		node *newnode = new node;
		cout << "Enter bits of binary number one by one : ";
		cin >> newnode->data;
		newnode->prev = NULL;
		newnode->next = NULL;
		if (head == NULL)
		{
			head = newnode;
			last = newnode;
		}
		else
		{
			last->next = newnode;
			newnode->prev = last;
			last = newnode;
		}
	}
}

void binary::display_binary()
{
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	binary b1;
	b1.create_binary();
	b1.display_binary();
	b1.twos_complement();
	return 0;
}


'''Time Complexity: O(n) for most operations (where n is the number of bits in the binary number), and O(max(n, m)) for binary addition.
Space Complexity: O(n), where n is the number of bits in the binary number'''