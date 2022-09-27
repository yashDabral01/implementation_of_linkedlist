#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};
class singlyLinkedList{
public:
node * head = NULL;
void insertAttail(int val){
        node *newnode = new node(val);
        node *temp = head;
        if(head == NULL){
            head = newnode;
            return;
        }
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
void insertAthead(int val){
        node *newnode = new node(val);
        newnode->next = head;
        head = newnode;
    }
void display(){
        node *temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
int search(int key){
    node *temp = head;
    int pos = 1;
    while(temp->next!=NULL){
        if(temp->data == key){
            return pos;
        }
        pos++;
        temp = temp->next;
    }
    return -1;
}
// void deleteNode( int pos){
//     node *temp = head;
//     node* todelete;
//     int count = 1;
//     while(temp!=NULL && (pos-1)!=count){
//         count++;
//         temp=temp->next;
//     }
//     todelete = temp->next;
//     temp->next = temp->next->next;
//     delete todelete;
// }
void deleteAthead(){
    node *todelete = head;
    head = head->next;
    delete todelete;
}
void deletion(int val){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        deleteAthead();
        return;
    }
    node *temp = head;
    while(temp->next->data!= val){
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
};

int main()
{   singlyLinkedList ls;
    int choice ;
    while(true){
    cout<<"Press 0 to exit program"<<endl;
    cout<<"Press 1 to insert an node at tail in linked list"<<endl;
    cout<<"Press 2 to insert an node at head in linked list"<<endl;
    cout<<"Press 3 to search an node in linked list"<<endl;
    cout<<"Press 4 to delete an element or node from linked list"<<endl;
    cout<<"Press 5 to display linked list"<<endl;
    cout<<"Ente your choice : ";
    cin>>choice;
    switch (choice)
    {
    case 0:
        return 0;
        break;
    case 1:
        int value1;
        cout<<"Enter the value to insert in node : ";
        cin>>value1;
        ls.insertAttail(value1);
        break;
    case 2:
        int value2;
        cout<<"Enter the value to insert in node : ";
        cin>>value2;
        ls.insertAthead(value2);
        break;
    case 3: 
        int searchVal;
        cout<<"Enter the value to search in linked list : ";
        cin>>searchVal;
        cout<<"Value present at position : "<<ls.search(searchVal)<<endl;
        break;
    case 4:
        int position;
        cout<<"Enter the position form which you want to delete the node : ";
        cin>>position;
        ls.deleteNode(position);
    case 5:
        ls.display();
        break;
    default:
        cout<<"Enter a valid choice!!"<<endl;
        break;
    }
    }
   
}