#include <iostream>

using namespace std;

#define SIZE 10

class Node{
    public:
    int data;
    Node* next;
    Node(int data = 0){
        this->data = data;
        next = NULL;
    }
};

class Stack{
    public:
    Node* root; // Top pointer
    int cnt;
    Stack(){
        root = NULL;
        cnt = 0;
    }
    bool isEmpty(){
        return root == NULL;
    }
    bool isFull(){
        return cnt == SIZE;
    }
    void push(int value){
        if(isEmpty()){
            root = new Node(value);
            cnt++;
        }
        else{
            if(isFull()){
                cout << "Stack overflow error." << endl ;
            }
            else{
                Node* temp = new Node(value);
                temp->next = root;
                root = temp;
                cnt++;
                //cout << "Item added to Stack." << endl ;
            }
        }
    }
    void pop(){
        if(isEmpty()){
            cout << "The item to be deleted is not found." << endl ;
        }
        else{
            Node* temp = root;
            root = root->next;
            delete temp;
            cnt--;
            cout << "Item deleted from Stack." << endl ;
        }
    }
    void print(){
        if(isEmpty()){
            cout << "NO ITEM." << endl ;
        }
        else{
            Node* temp = root;
            cout << "TOP" << endl ;
            while(temp != NULL){
                cout << temp->data << endl ;
                temp = temp->next;
            }
            cout << "BOTTOM" << endl ;
        }
    }
    void top(){
        if(isEmpty()){
            cout << "NO ITEM." << endl ;
        }
        else{
            cout << "Top: " << root->data << endl ;
        }
    }
    void sizeStack(){
        cout << "Size: " << cnt << endl ;
    }

};

void func(Stack a, Stack b){
    Stack c;
    int sizeArr = a.cnt + b.cnt;
    int arr[sizeArr];
    Node* temp = a.root;
    for(int i = 0; i <a.cnt; i++){
        arr[i] = temp->data;
        temp = temp->next;
    }
    Node* temp2 = b.root;
    for(int i = a.cnt; i<sizeArr; i++){
        arr[i] = temp2->data;
        temp2 = temp2->next;
    }
    /*for(int i = 0; i<sizeArr ; i++) // Algorithm works crystal clearly.
        cout << i << ": " << arr[i] << endl ;*/
    int index;
    int max1 = arr[0];
    for(int j = 0; j<sizeArr; j++){
        for(int i = 0; i<sizeArr; i++){
            if(max1 < arr[i]){
            max1 = arr[i];
            index = i;
        }
    }
    c.push(max1);
    arr[index] = -1;
    max1 = -1;
}
    cout << endl << "*NEW STACK*" << endl ;
    c.print();

}
void func2(Stack a, Stack b){
    Stack c;
    Stack tmp;
    Node* temp = a.root;
    for(int i = 0; i<a.cnt ; i++){
        tmp.push(temp->data);
        temp = temp->next;
    }
    Node* temp2 = b.root;
    for(int i = 0; i<b.cnt; i++){
        tmp.push(temp2->data);
        temp2 = temp2->next;
    }
    //tmp.print();
    // We create temporary stack and it keeps datas from 2 sorted stacks.
    Node* temp3 = tmp.root;
    int max1 = temp3->data;
    Node* temp4;
    for(int j = 0; j<tmp.cnt; j++){
        for(int i = 0; i<tmp.cnt; i++){
            if(max1 < temp3->data){
                max1 = temp3->data;
                temp4 = temp3;
            }
            temp3 = temp3->next;
    }
    c.push(max1);
    temp4->data = -1;
    max1 = -1;
    temp3 = tmp.root;
    }
    cout << endl;
    c.print();



}

int main()
{
    Stack a;
    Stack b;

    a.push(50);
    a.push(40);
    a.push(30);
    a.push(20);

    b.push(35);
    b.push(25);
    b.push(15);
    b.push(10);

    system("cls"); // Outputs Stack "a" and "b" items separately.
    a.print();
    cout << endl ;
    b.print();

    func2(a, b);


    return 0;
}
