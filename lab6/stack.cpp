#include<iostream>
#include<chrono>
#include<cstdlib>

using namespace std;
using namespace std::chrono;

// using array
int top = -1;
int i, x;
int n = 10;
int stack[10];

void push(int x);
void pop();
void display();
int stackTop();
bool isEmpty();
bool isFull();

int main(){     
    cout << "-----Implementation using array----" << endl;
    cout << "Enter the number of elements you want in the stack: 10" << endl;
    srand(time(0));
    auto start = high_resolution_clock::now();
    for(int i=0; i<10; i++){
        push(rand()%10);
    }
    
    display();
    cout << "\n";
    cout << "Popping three elements from the stack" << endl;
    for (int j = 0; j<3; j++){
        pop();
    }

    cout << "\n";
    display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n";
    cout << "Time taken for push operation using array: " << duration.count() << " microseconds." << endl;

    return 0;
}

void push(int x){  
    if(isFull()){          
        cout<<"Stack overflow"<<endl;
    } else{
        top=top+1;
        stack[top]=x;
    }
}

void pop(){
    if(isEmpty()){                
        cout<<"Stack underflow"<<endl;
    }else{
        cout << "Popped element is " << stack[top] << endl;
        top--;
    }
}

bool isEmpty(){
    return top < 0;
}

bool isFull(){
    return top >= n - 1;
}

int stackTop(){
    if(isEmpty()){
        cout << "Stack is Empty\n";
        return -1;
    }
    return stack[top];
}

void display(){
    if(top>=0){
        cout<<"Elements in the stack are :";
        for(i=top;i>=0;i--){
            cout<<stack[i]<<" ";
        }
        cout << '\n';
    }else{
        cout<<"Stack is empty."<<endl;
    }
}