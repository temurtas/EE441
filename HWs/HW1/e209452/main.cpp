#include <iostream>
#include <fstream>
using namespace std;
/////// Stack Class ///////////////
const int MaxStacksize=50;
template <class T>
class Stack // class declaration
{
    private:
        T stacklist[MaxStacksize];
        int top;
    public:
        Stack(void){
            top=-1;} // constructor to initialize top
        // modification operations
        void Push(const T& item) // push
        {
            if (top==MaxStacksize-1) // cannot push if stack exceeded its limit
            {
                cerr<<"Stack overflow"<<endl;
                exit(1);
            }
            top++; // increment top ptr and copy item into list
            stacklist[top]=item;
        }
        T Pop(void) // pop
        {
            T temp;
            if (top==-1) // cannot pop anything if stack empty
            {
                cerr<<"Stack empty"<<endl;
                exit(1);
            }
            temp=stacklist[top]; // record the top element and decrement top
            top--;
            return temp;
        }
        void ClearStack(void){
            top=-1;
        }
        T Peek(void) const{
            return stacklist[top]; } // just copy
        // stack state operations
        int StackEmpty(void) const{
            if(top>-1)
                return 0; // NOT Empty
            else
                return 1; // Empty
        }
        int StackFull(void) const{
            if(top == MaxStacksize-1)
                return 1;
            else
                return 0;
        }
};


/////// Queue Class ///////////////
const int MaxQSize=50;
template <class T>
    class Queue
    {
        private:
            int front, rear, count; // queue array and its parameters
            T qlist[MaxQSize] ;
        public:
            Queue(void){front=0; rear =0; count=0; // constructor initializes empty queue
 } // constructor initialize data members
            void QInsert(const T& item) // queue modification operations
            {
                if (count==MaxQSize) // terminate if queue is full
                {
                    cerr<<"Queue overflow!" <<endl ;
                    exit(1);
                }
                count++; //increment count, assign item to qlist and update rear
                qlist[rear] =item;
                rear=(rear+1)% MaxQSize;
            }
            T QDelete(void) // delete element from the front and return its value
   {
        T temp;
        if (count==0) // if qlist is empty, terminate the program
        {
            cerr<<"Deleting from an empty queue!"<<endl;
        }
        temp=qlist[front] ; count--; //record value at the front of the queue decrease count
        front=(front+1) % MaxQSize; //HERE PROBLEMMMMMMMMMMMM
        return temp; // advance front and return former front
    }
            void ClearQueue(void){
                count = 0;
                front = 0;
                rear = 0;
            }
            T QFront(void) const{ // First Element of Queue
                if(count != 0)
                    return qlist[front];
                else
                return 0;
            }
            T QRear(void) const{    // Last Element of Queue
                if(count != 0)
                    return qlist[rear-1];
                else
                return 0;
            } // queue access
            int QLength(void) const{
                return count;
            } // status check methods
            int QEmpty(void) const{
                if (count == 0) // if count == 0
                    return 1;
                else
                    return 0;
            }
            int QFull(void) const{
                if (count == MaxQSize) // if count == 50
                    return 1;
                else
                    return 0;
            }
    };

////////////// Main Func /////////
int main()
{
////////////// Good Old Hello World!
//
//    cout << "Hello world!" << endl;
//
//////////////////////////////////////////////
    char mainarray[6]={'A','B','C','D','E','F'};  // Array to be printed
/////////////// Read .txt file ///////////////
    string myarray_str;
    ifstream ipfile("EE441HW1.txt", ifstream::in); // read input file
    int myarray[6][6];  // for BFT
    int myarray2[6][6]; // for modified BFT
    int myarray3[6][6]; // for DFT
    int myarray4[6][6]; // for modified DFT
    int i=0;

    while (ipfile >> skipws >> myarray_str)
    {
        for(int j=0; j<6; j++){
            myarray[i][j] = myarray_str[j]-48; // character to integer
            myarray2[i][j]=myarray[i][j];
            myarray3[i][j]=myarray[i][j];
            myarray4[i][j]=myarray[i][j];
        }
        i++;
    }
//////////////////////////////////////////////
    char istenen; // Store the destination point;
    cout << "Desired Destination Point(Please use one of A,B,C,D,E,F): ";
    cin >> istenen;
    cout<< "\n" <<"Desired Destination is " <<istenen<<"."<<"\n"<<endl;
/////////////// ---BFT--- //////////////////////////

    Queue <int> visitedq;

    visitedq.QInsert(char(mainarray[0]));
    cout<<"BFT Result is "<<char(visitedq.QRear())<<" ";
    for (int r=0;r<6;r++) {
        myarray[r][0]=0;
        }

    int h=0;
    while(h<6){

        for(int t=0; t<6; t++){
            if (myarray[h][t]!=0){
                visitedq.QInsert(mainarray[t]);
                cout<<char(visitedq.QRear())<<" ";
                for (int r2=0;r2<6;r2++){
                    myarray[r2][t]=0;
                }
                continue;
            }
            else{continue;}
        }
        h++;
    }
    cout<<"\n"<<endl;
////////////----Modified BFT---//////////////NOT WORKING
//    Queue <int> visitedq_mod;
//
//    visitedq_mod.QInsert(char(mainarray[0]));
//    cout<<"BFT Result is "<<char(visitedq_mod.QRear())<<" ";
//    for (int r=0;r<6;r++) {
//        myarray2[r][0]=0;
//        }
//
//    int h2=0;
//    while(h2<6){
//        int t2=0;
//        while(t2<6){
//            if (myarray2[h2][t2]!=0){
//                visitedq_mod.QInsert(mainarray[t2]);
//                cout<<char(visitedq_mod.QRear())<<" ";
//                for (int r22=0;r22<6;r22++){
//                    myarray2[r22][t2]=0;
//                }
//                t2++;
//                continue;
//            }
//            else{
//                t2++;
//                continue;}
//            cout<<t2<<endl;
//        }
//        if (istenen == char(mainarray[t2]))
//            {
//            break;
//        }
//        else{
//            continue;
//            h2++;
//            }
//
//    }
//    cout<<"\n"<<"seeeen"<<endl;
//
////////////////// DFT ///////////
//    Stack <int> visiteds;
//
//    visiteds.Push(mainarray[0]);
//    cout<<"DFT Result is "<<char(visiteds.Peek())<<" ";
//    for (int r3=0;r3<6;r3++) {
//        myarray[r3][0]=0;
//        }
//
//    int h3=0;
//    while(h3<6){
//
//        for(int t=0; t<6; t++){
//            if (myarray3[h][t]!=0){
//                visiteds.Push(mainarray[t]);
//                cout<<char(visiteds.Peek())<<" ";
//                for (int r2=0;r2<6;r2++){
//                    myarray3[r2][t]=0;
//                }
//                continue;
//            }
//            else{continue;}
//        }
//        h3++;
//    }
//    cout<<"\n"<<endl;
//
///////////////-----DFT--------//////////////// NOT QUITE WORKS

    Queue <int> visiteds;
    int hafiza[6];
    visiteds.QInsert(char(mainarray[0]));
    cout<<"DFT Result is "<<char(visiteds.QRear())<<" ";
    for (int r3=0;r3<6;r3++) {
        myarray3[r3][0]=0;
        }
    hafiza[0]=1;


    int h3=0;
    while(h3<6){
            int hf=0;
        for(int t3=0; t3<6; t3++){
            if (myarray3[h3][t3]!=0){
                visiteds.QInsert(mainarray[t3]);
                cout<<char(visiteds.QRear())<<" ";
                    if (hafiza[hf]!=1){
                        hafiza[hf]=t3;
                        cout<<hafiza[hf];
                    }
//                    else{
//                        cout<<hafiza[hf];
//                    }
                for (int r4=0;r4<6;r4++){
                    myarray3[r4][t3]=0;
                }
                continue;
            }
            else{
                if (hafiza[hf]!=1){
                        hafiza[hf]=t3;
                        cout<<hafiza[hf];
                    }
//                    else{
//                        cout<<hafiza[hf];
//                    }
                continue;
            }
        }
        h3++;
        hf++;
    }
    cout<<"\n"<<endl;




    return 0;
}
