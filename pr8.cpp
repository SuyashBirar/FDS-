#include <iostream>
using namespace std;

struct node {
    int roll;
    struct node *next;
};

class data {
    node *head1 = NULL, *head2 = NULL, *head3 = NULL, *h1 = NULL, *head = NULL;

public:
    node *create();
    void insert(node *&head);
    void allstud();
    void vanila();
    void butters();
    void uice();
    void nice();
    void notice();
    void ovanila();
    void obutters();
    void display(node *head);
};

node *data::create() {
    node *p = new node;
    cout << "Enter student Rollno: ";
    cin >> p->roll;
    p->next = NULL;
    return p;
}

void data::insert(node *&head) {
    node *p = create();
    if (head == NULL)
        head = p;
    else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void data::display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->roll << " ";
        temp = temp->next;
    }
    cout << endl;
}

void data::allstud() {
    int k;
    cout << "Enter total number of students: ";
    cin >> k;
    h1 = NULL;
    for (int i = 0; i < k; i++) {
        insert(h1);
    }
    display(h1);
}

void data::vanila() {
    int k;
    cout << "Enter number of students who like vanilla ice cream: ";
    cin >> k;
    head1 = NULL;
    for (int i = 0; i < k; i++) {
        insert(head1);
    }
    display(head1);
}

void data::butters() {
    int j;
    cout << "Enter number of students who like butterscotch ice cream: ";
    cin >> j;
    head2 = NULL;
    for (int i = 0; i < j; i++) {
        insert(head2);
    }
    display(head2);
}

void data::uice() {
    cout << "Students who like vanilla or butterscotch ice cream: ";
    head3 = NULL;
    node *temp1 = head1, *temp2 = head2;

    // Add all vanilla students to the union list
    while (temp1 != NULL) {
        insert(head3);
        temp1 = temp1->next;
    }

    // Add only unique butterscotch students to the union list
    temp2 = head2;
    while (temp2 != NULL) {
        bool found = false;
        temp1 = head1;
        while (temp1 != NULL) {
            if (temp1->roll == temp2->roll) {
                found = true;
                break;
            }
            temp1 = temp1->next;
        }
        if (!found) {
            insert(head3);
        }
        temp2 = temp2->next;
    }
    display(head3);
}

void data::ovanila() {
    cout << "Students who like only vanilla ice cream: ";
    node *temp1 = head1;
    while (temp1 != NULL) {
        node *temp2 = head2;
        bool found = false;
        while (temp2 != NULL) {
            if (temp1->roll == temp2->roll) {
                found = true;
                break;
            }
            temp2 = temp2->next;
        }
        if (!found) {
            cout << temp1->roll << " ";
        }
        temp1 = temp1->next;
    }
    cout << endl;
}

void data::obutters() {
    cout << "Students who like only butterscotch ice cream: ";
    node *temp2 = head2;
    while (temp2 != NULL) {
        node *temp1 = head1;
        bool found = false;
        while (temp1 != NULL) {
            if (temp2->roll == temp1->roll) {
                found = true;
                break;
            }
            temp1 = temp1->next;
        }
        if (!found) {
            cout << temp2->roll << " ";
        }
        temp2 = temp2->next;
    }
    cout << endl;
}

void data::nice() {
    cout << "Students who like both vanilla and butterscotch ice cream: ";
    node *temp1 = head1;
    while (temp1 != NULL) {
        node *temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->roll == temp2->roll) {
                cout << temp1->roll << " ";
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    cout << endl;
}

void data::notice() {
    cout << "Students who like neither vanilla nor butterscotch ice cream: ";
    node *temp = h1;
    while (temp != NULL) {
        node *temp3 = head3;
        bool found = false;
        while (temp3 != NULL) {
            if (temp->roll == temp3->roll) {
                found = true;
                break;
            }
            temp3 = temp3->next;
        }
        if (!found) {
            cout << temp->roll << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    data s;
    int choice;
    char ch;

    do {
        cout << "\nOptions Menu";
        cout << "\n1. Enter all students' roll numbers";
        cout << "\n2. Enter roll numbers of students who like vanilla";
        cout << "\n3. Enter roll numbers of students who like butterscotch";
        cout << "\n4. Display students who like vanilla or butterscotch";
        cout << "\n5. Display students who like only vanilla";
        cout << "\n6. Display students who like only butterscotch";
        cout << "\n7. Display students who like both vanilla and butterscotch";
        cout << "\n8. Display students who like neither vanilla nor butterscotch";
        cout << "\nChoose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: s.allstud(); break;
        case 2: s.vanila(); break;
        case 3: s.butters(); break;
        case 4: s.uice(); break;
        case 5: s.ovanila(); break;
        case 6: s.obutters(); break;
        case 7: s.nice(); break;
        case 8: s.notice(); break;
        default: cout << "\nUnknown choice\n";
        }
        
        cout << "\nDo you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
