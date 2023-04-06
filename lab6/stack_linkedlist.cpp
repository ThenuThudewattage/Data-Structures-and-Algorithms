#include <iostream>
#include<chrono>
#include<cstdlib>

using namespace std;
using namespace std::chrono;

void push(int y);
void pop();
void display();

int main(){ 
    //for linked list implementation
    int n;
    cout << "-----Implementation using linked list-----" << endl;
    cout << "Enter the number of elements you want in the stack: ";
    cin >> n;
    srand(time(0));
    auto start = high_resolution_clock::now();
    for(int i=0; i<n; i++){
        push(rand()%10);
    }
    cout << "\n";
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
    cout << "Time taken for push operation using linked list: " << duration.count() << " microseconds." << endl;
    
    return 0;
}

struct Node {
   int data;
   struct Node *after;
};

struct Node* top = NULL;

void push(int y) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = y;
   newnode->after = top;
   top = newnode;
}

void pop() {
    if(top==NULL){
        cout<<"Stack Underflow"<<endl;
    } else {
        cout<<"The popped element is "<< top->data <<endl;
        top = top->after;
    }
}

void display() {
    struct Node* ptr;
    if(top==NULL){
        cout<<"stack is empty";
    } else {
        ptr = top;
        cout<<"Stack elements are: ";
        while (ptr != NULL) {
            cout<< ptr->data <<" ";
            ptr = ptr->after;
        }
    }
    cout<<endl;
}