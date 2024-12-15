#include <iostream>
#include <string>
using namespace std;

struct node {
    string name;
    string prn;
    node *next;
};

class club {
private:
    node *sec;
    int count;

public:
    node *pres;
    club() {
        pres = NULL;
        sec = NULL;
        count = 0;
    }
    ~club();
    void create();
    void display();
    void insert();
    void count_mem();
    void concat(club &);
    void delete_mem();
    void reverse(node *);
};

club::~club() {
    node *temp;
    while (pres != NULL) {
        temp = pres;
        pres = pres->next;
        delete temp;
    }
    cout << "Destructor called." << endl;
}

void club::create() {
    node *newnode;

    // Create president
    newnode = new node;
    cout << "Enter president name: ";
    cin >> newnode->name;
    cout << "Enter president PRN: ";
    cin >> newnode->prn;
    newnode->next = NULL;
    pres = newnode;

    // Create secretary
    newnode = new node;
    cout << "Enter secretary name: ";
    cin >> newnode->name;
    cout << "Enter secretary PRN: ";
    cin >> newnode->prn;
    newnode->next = NULL;
    sec = newnode;

    pres->next = sec;

    // Create members
    cout << "Enter number of club members: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        newnode = new node;
        cout << "Enter member name: ";
        cin >> newnode->name;
        cout << "Enter member PRN: ";
        cin >> newnode->prn;
        newnode->next = pres->next;
        pres->next = newnode;
    }
}

void club::display() {
    node *temp = pres;
    cout << "\nNAME\t\tPRN" << endl;
    while (temp != NULL) {
        cout << temp->name << "\t\t" << temp->prn;
        if (temp == pres)
            cout << "\t--PRESIDENT";
        if (temp == sec)
            cout << "\t--SECRETARY";
        cout << endl;
        temp = temp->next;
    }
}

void club::count_mem() {
    node *temp = pres;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    cout << "\nTotal members of the club are: " << cnt << endl;
}

void club::insert() {
    node *newnode = new node;
    cout << "\nEnter member name: ";
    cin >> newnode->name;
    cout << "Enter member PRN: ";
    cin >> newnode->prn;
    newnode->next = NULL;

    if (pres == NULL) {
        pres = sec = newnode;
    } else {
        node *temp = pres;
        while (temp->next != sec) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = sec;
    }
}

void club::concat(club &l) {
    if (sec != NULL) {
        sec->next = l.pres;
        sec = l.sec;
    } else {
        pres = l.pres;
        sec = l.sec;
    }
    l.pres = l.sec = NULL;
}

void club::delete_mem() {
    string student_prn;
    cout << "Enter PRN to be deleted: ";
    cin >> student_prn;

    node *temp = pres;
    node *prev = NULL;

    while (temp != NULL && temp->prn != student_prn) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Member not found." << endl;
        return;
    }

    if (temp == pres) {
        pres = pres->next;
    } else if (temp == sec) {
        sec = prev;
        prev->next = NULL;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << student_prn << " deleted successfully." << endl;
}

void club::reverse(node *p) {
    if (p == NULL)
        return;
    reverse(p->next);
    cout << p->name << "\t" << p->prn << endl;
}

int main() {
    club c1, c2;
    while (true) {
        int ch;
        cout << "\n1. Create Club" << endl;
        cout << "2. Display Club" << endl;
        cout << "3. Add member to club." << endl;
        cout << "4. Count members of the club." << endl;
        cout << "5. Delete member from club" << endl;
        cout << "6. Combine two divisions." << endl;
        cout << "7. Reverse the club members." << endl;
        cout << "8. Exit." << endl;
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            c1.create();
            break;
        case 2:
            c1.display();
            break;
        case 3:
            c1.insert();
            c1.display();
            break;
        case 4:
            c1.count_mem();
            break;
        case 5:
            c1.delete_mem();
            c1.display();
            break;
        case 6:
            c2.create();
            c1.concat(c2);
            c1.display();
            break;
        case 7:
            cout << "\nReversed Club Members:" << endl;
            c1.reverse(c1.pres);
            break;
        case 8:
            cout << "\nEnd of Program." << endl;
            return 0;
        default:
            cout << "\nYou entered an invalid choice." << endl;
        }
    }
}


'''Time Complexity: O(m) for most operations, where m is the total number of nodes (president + secretary + members).
Space Complexity: O(m) for storing the list of nodes and recursion stack in the reverse() method'''