#include <bits/stdc++.h> 
using namespace std;

class node
{
    public:
        int key;
        int data;
        node * next;

        node()
        {
            key = 0;
            data = 0;
            next = NULL;
        }

        node(int k, int d)
        {
            key = k;
            data = d;
        }
};

class SinglyLinkedList
{
    public:
        node * head;

        SinglyLinkedList()
        {
            head = NULL;
        }

        // 1. CHECK IF NODE EXIST USING KEY VALUE
        node * nodeExists(int k)
        {
            node * temp = NULL;
            node * ptr = head;
            if(ptr == NULL)
                return temp;
            else
            {
                do
                {
                    if(ptr->key == k)
                        temp = ptr;

                    ptr = ptr->next;
                }while(ptr != head);
                return temp;
            }
        }

        // 2. APPEND A NODE TO THE LIST
        void appendNode(node * n)
        {
            if(nodeExists(n->key) != NULL)
                cout << "Node already exist with key value ("<<n->key<<"). Enter another node with different key value.\n";
            else
            {
                if(head==NULL)
                {
                    head = n;
                    cout << "Node Appended.\n";
                    n->next = head;
                }
                else
                {
                    node * ptr = head;
                    while(ptr->next != head)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    n->next = head;
                    cout << "Node Appended.\n";
                }
            }
        }

        // 3. PREPEND A NODE TO THE LIST
        void prependNode(node * n)
        {
            if(nodeExists(n->key) != NULL)
                cout << "Node already exist with key value ("<<n->key<<"). Enter another node with different key value.\n";
            else
            {
                if(head==NULL)
                {
                    head = n;
                    n->next = head;
                    cout << "Node Prepended.\n";
                }
                else
                {
                    node * ptr = head;
                    while(ptr->next != head)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    n->next = head;
                    head = n;
                    cout << "Node Prepended.\n";
                }
                
            }
        }

        // 4. INSERT A NODE AFTER A PERTICULAR NODE
        void insertNode(int k, node * n)
        {
            node * ptr = nodeExists(k);
            if(ptr == NULL)
                cout << "Node doesn't exist with key value ("<<n->key<<"). Enter another node with different key value.\n";
            else
            {
                n->next = ptr->next;
                ptr->next = n;
            }

        }

        // 5. DELETING A NODE BY KEY
        void deleteNode(int k)
        {
            if(head == NULL)
                cout << "list already empty. Can't delete.\n";
            else if(head != NULL)
            {
                if(head->key == k)
                {
                    node * temp = head;
                    
                    node * ptr = head;
                    do
                    {
                        ptr = ptr->next;
                    }while(ptr->next != head);
                    head = head->next;
                    ptr->next = head;
                    temp->next = NULL;
                    cout << "value deleted! key ("<<temp->key<<") and value ("<<temp->data<<").\n";
                    free(temp);
                }
                else
                {
                    node * temp = NULL;
                    node * prev_ptr = head;
                    node * cur_ptr = head->next;
                    int f=0;
                    while(cur_ptr != NULL)
                    {
                        if(cur_ptr->key == k)
                        {
                            temp = cur_ptr;
                            prev_ptr->next = cur_ptr->next;
                            temp->next = NULL;
                            cout << "value deleted! key ("<<temp->key<<") and value ("<<temp->data<<").\n";
                            free(temp);
                            f = 1;
                            break;
                        }
                        else
                        {
                            prev_ptr = prev_ptr->next;
                            cur_ptr = cur_ptr->next;
                        } 
                    }
                    if(f == 0)
                        cout << "node with key value doesn't exist.\n";
                }
            }
        }

        //6. UPDATE A NODE
        void updateNode(int k, int d)
        {
            node * ptr = nodeExists(k);
            if(ptr != NULL)
            {
                ptr->data = d;
                cout <<"node with key ("<<ptr->key<<") updated\n";
            }
            else
                cout << "node with key value doesn't exist.\n";
            
        }

        // 7. DISPLAY LIST
        void printList()
        {
            if(head == NULL)
                cout << "list is empty.\n";
            else
            {
                node * temp = head;
                do
                {
                    cout << "["<<temp->key<<","<<temp->data<<"]-->";
                    temp = temp->next;
                }while(temp != head);
                cout << "["<<temp->key<<","<<temp->data<<"]\n\n";
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
    //----------------------------------------------------------------
    SinglyLinkedList s;
    int option, key1, k1, data1;

    do
    {
        cout << "\nSelect operation :          Enter 0 to exit."<<endl;
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
            cout << "enter key & value to be appended : " <<endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            break;
        case 2: 
            cout << "enter key & value to be prepended : " <<endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;
        case 3:
            cout << "enter key after which value to be inserted : " <<endl;
            cin >> k1;
            cout << "enter key & value to be inserted : " <<endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNode(k1, n1);
            break;
        case 4:
            cout << "enter key for node deletion :" <<endl;
            cin >> k1;
            s.deleteNode(k1);
            break;
        case 5:
            cout << "enter key for node updation :" <<endl;
            cin >> key1;
            cin >> data1;
            s.updateNode(key1, data1);
            break;
        case 6:
            s.printList();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter a proper operation number." <<endl;
            break;
        }
    } while (option != 0);

    return 0 ;

}

/*
INPUT :
1
1 2
2
2 1
1
3 4
3
2 4 3
6
4
1
6
4
2
6
5
3 9
6
0
*/