#include  <iostream>
using namespace std;
 
class queue
{   
    int *arr;
    int qfront;
    int rear;
    int size;

    public:
        queue(){
            size=1000001;
            arr=new int[size];
            qfront=0;
            rear=0;
        }

        bool empty(){
            if(qfront==rear){
                return true;
            }
            else return false;
        }
        void push(int data){
            if(rear!=size){
                arr[rear]=data;
                rear++;
            }
            else return;
        }
        int pop(){
            if(qfront==rear){
                return -1;
            }
            else{
                int ans=arr[qfront];
                arr[qfront]=-1;
                qfront++;
                if(qfront==rear){
                    qfront=0;
                    rear=0;
                }
                return ans;
            }
        }

        int front(){
            if(qfront==rear){
                return -1;
            }
            else{
                arr[qfront];
            }
        }


};

int main()
{
    queue q;
    q.push(15);
    q.push(17);
    q.push(19);
    cout<<q.pop()<<endl;
    if(q.empty()){
         cout<<"Empty";
    }
    else{
        cout<<"Not Empty";
    }
    return 0;
}