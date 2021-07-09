#include <iostream> 
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

// STACK CLASS
class Stack{
    private:
        int top;
        int arr[5];
    public:
        Stack ()
        {
            top = -1;
            for(int i=0; i<5; i++)
            {
                arr[i] = 0;
            }
        }

        bool isEmpty()
        {
            if(top == -1)
                return true;
            else
                return false;
        }

        bool isFull()
        {
            if(top == 4)
                return true;
            else
                return false;
            
        }

        void push(int val)
        {
            if(isFull())
                cout << "Stack Overflow"<<endl;
            else
            {
                top++;
                arr[top] = val;
            }
            
        }

        int pop()
        {
            if(isEmpty())
            {
                cout << "Stack Underflow"<<endl;
                return -1;
            }
            else
            {
                int popval = arr[top];
                arr[top] = 0;
                top--;
                return popval;
            }
        }

        int count()
        {
            return (top + 1);
        }

        int peek(int pos)
        {
            if(isEmpty())
            {
                cout << "Stack Underflow"<<endl;
                return -1;
            }
            else
            {
                return arr[pos];
            }  
        }
        void display()
        {
            cout << "The Stack is :"<<endl;
            for (int i = top; i >= 0; i--)
            {
                cout << "|  " << arr[i] << "  |" << endl;
                cout << "-------"<<endl;
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
    //----------------------------------------------------
    Stack s1;
    int option, position, value;
    do
    {
        cout << "Select operation :          Enter 0 to exit."<<endl;
        cout << "1. Push()"<<endl;
        cout << "2. Pop()"<<endl;
        cout << "3. isEmpty()"<<endl;
        cout << "4. isFull()"<<endl;
        cout << "5.Peek()"<<endl;
        cout << "6.Count()"<<endl;
        cout << "7.Display()"<<endl;
        cout << "8.Clear Screen"<<endl<<endl;

        cin >> option;
        switch (option)
        {
        case 1: 
            cout << "enter value to be pushed : " <<endl;
            cin >> value;
            s1.push(value);
            break;
        case 2: 
            cout << "value poped was : " << s1.pop() <<endl;
            break;
        case 3:
            cout << s1.isEmpty() <<endl;
            break;
        case 4:
            cout << s1.isFull() <<endl;
            break;
        case 5:
            cout << "the count is : " << s1.count() <<endl;
            break;
        case 6:
            cout << "Enter position : "<<endl;
            cin >> position;
            cout << "The value is : " << s1.peek(position) <<endl;
            break;
        case 7:
            s1.display();
            break;
        case 8:
            system("cls");
            break;
        default:
            cout << "Enter a proper operation number." <<endl;
            break;
        }
    } while (option != 0);
    


    return 0 ;

}
