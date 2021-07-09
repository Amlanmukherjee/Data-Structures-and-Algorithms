#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

//QUEUE
class Queue{
    private:
        int front, rear, arr[5];

    public:
        Queue ()
        {
            front = rear = -1;
            for(int i=0; i<5; i++)
            {
                arr[i] = 0;
            }
        }
        bool isEmpty()
        {
            if(front == -1 && rear == -1)
                return true;
            else
                return false;
        }

        bool isFull()
        {
            if(rear == 4)
                return true;
            else
                return false;
            
        }

        void enqueue(int val)
        {
            if(isFull())
            {
                cout << "The queue is full" << endl;
                return;
            }
            else if(isEmpty())
            {
                front = rear = 0;
            }
            else
            {
                rear++;
            }
            arr[rear] = val;
        }

        int dequeue()
        {
            int temp;
            if(isEmpty())
            {
                cout << "The queue is empty" << endl;
                temp = -1;
            }
            else if(front == rear)
            {
                temp = arr[front];
                arr[front] = -1;
                front = rear = -1;
            }
            else
            {
                temp = arr[front];
                arr[front] = -1;
                front++;
            }
            return temp;
        }
        void display()
        {
            for(int i=front; i<=rear; i++)
            {
                cout << "---+";
            }
            cout << endl;
            for(int i=front; i<=rear; i++)
            {
                cout << " " << arr[i] <<" |";
            }
            cout << endl;
            for(int i=front; i<=rear; i++)
            {
                cout << "---+";
            }
            cout << endl;
        }
};

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    //----------------------------------------------------
    Queue q1;
    int option, value;
    do
    {
        cout << "Select operation :          Enter 0 to exit."<<endl;
        cout << "1. Enqueue()"<<endl;
        cout << "2. Dequeue()"<<endl;
        cout << "3. isEmpty()"<<endl;
        cout << "4. isFull()"<<endl;
        cout << "5.Display()"<<endl;
        cout << "6.Clear Screen"<<endl<<endl;

        cin >> option;
        switch (option)
        {
        case 0:
            cout << "EXIT";
            break;
        case 1: 
            cout << "enter value to enqueue : " <<endl;
            cin >> value;
            q1.enqueue(value);
            break;
        case 2: 
            cout << "dequeued value was : " << q1.dequeue() <<endl;
            break;
        case 3:
            cout << q1.isEmpty() <<endl;
            break;
        case 4:
            cout << q1.isFull() <<endl;
            break;
        case 5:
            q1.display();
            break;
        case 6:
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
1 2
5
1 3
5
1 4
5
1 5
5
2
5
2
5
0
*/
