#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node * previous;
        node * next;

        node()
        {
            data = 0;
            previous = NULL;
            next = NULL;
        }

};

class DoublyLinkedList
{
    public:
        node * head;
        node * tail;

        DoublyLinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        // 1. APPEND
        void nodeAppend(node * n)
        {
            if(head == NULL)
            {
                head = n;
                tail = n;
                cout << "Node appended.\n";
            }
            else
            {
                node * temp = tail;
                tail->next = n;
                tail = tail->next;
                tail->previous = temp;
                cout << "Node appended.\n";
            } 
        }

        // 2. PREPEND
        void nodePrepend(node * n)
        {
            if(head == NULL)
            {
                head = n;
                tail = n;
                cout << "Node prepended.\n";
            }
            else
            {
                node * temp = head;
                head->previous = n;
                head = head->previous;
                head->next = temp;
                cout << "Node prepended.\n";
            }
            
        }

        // 6. PRINT LIST USING HEAD
        void printList()
        {
            if(head == NULL)
                cout << "list is empty.\n";
            else
            {
                cout<<endl;
                node * temp = head;
                while(temp != NULL)
                {
                    cout << "[" << temp->data << "]<-->";
                    temp = temp->next;
                }
                cout <<"[NULL]\n\n";
            }
        }

        // 7. PRINT LIST USING TAIL
        void printListR()
        {
            if(head == NULL)
                cout << "list is empty.\n";
            else
            {
                cout<<endl;
                node * temp = tail;
                while(temp != NULL)
                {
                    cout << "[" << temp->data << "]<-->";
                    temp = temp->previous;
                }
                cout <<"[NULL]\n\n";
            }
        }
};

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    //---------------------------------------------
    DoublyLinkedList d1;
    int data1, option;

    do
    {
        cout << "Select operation :          Enter 0 to exit."<<endl;
        cout << "1. Append a node()"<<endl;
        cout << "2. Prepend a node()"<<endl;
        cout << "3. Insert a node after a node(key)"<<endl;
        cout << "4. Delete node by key()"<<endl;
        cout << "5. Update node by key()"<<endl;
        cout << "6. Print list()"<<endl;
        cout << "7. Clear Screen"<<endl<<endl;

        cin >> option;
        node * n1 = new node();
        switch (option)
        {
        case 0:
            cout << "EXIT";
            break;
        case 1: 
            cout << "enter value to be appended : " <<endl;
            cin >> data1;
            n1->data = data1;
            d1.nodeAppend(n1);
            break;
        case 2: 
            cout << "enter value to be prepended : " <<endl;
            cin >> data1;
            n1->data = data1;
            d1.nodePrepend(n1);
            break;

        case 6:
            d1.printList();
            break;
        case 7:
            d1.printListR();
            break;
        default:
            cout << "Enter a proper operation number." <<endl;
            break;
        }
    } while (option != 0);

    return 0 ;

}