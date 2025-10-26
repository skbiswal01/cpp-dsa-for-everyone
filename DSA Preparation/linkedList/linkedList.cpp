//
//  linkedList.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 10/06/25.
//

#include "linkedList.hpp"
#include <iostream>

using namespace std;


LinkedList::LinkedList(int A[], int n){
    Node *last,*t;
    int i=0;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
};

LinkedList::~LinkedList(){
    if (detectLoop()) {
        cout << "Loop detected — cannot safely delete" << endl;
        return;
    }
    
    Node *p=first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}

void LinkedList::Display()
{
Node *p=first;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
cout<<endl;
}

int LinkedList::count(){
    int c = 0;
    Node* temp = first;
    while(temp != 0){
        temp = temp->next;
        c += 1;
    }
    
    return c;
}

int LinkedList::add(){
    Node* temp = first;
    int sum = 0;
    while(temp !=0){
        sum += temp->data;
        temp = temp->next;
    }
    
    return sum;
}

int LinkedList::max(){
    Node* temp = first;
    int max = INT32_MIN;
    while(temp ){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}


Node* LinkedList::Search(int key){
    Node* temp  = first;
    while(temp != 0){
        if(temp -> data == key){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
};

Node* LinkedList::ImproSearch(int key){
    Node* temp = first;
    Node* prev = nullptr;
    //If the key is in the first node, return it directly
        if(temp != nullptr && temp->data == key) {
            return temp;
        }

        while(temp != nullptr){
            if(temp->data == key){
                // Unlink the node and move to front
                if(prev != nullptr) {
                    prev->next = temp->next;
                    temp->next = first;
                    first = temp;
                }
                return temp;  // This is the new head now
            }
            prev = temp;
            temp = temp->next;
        }

        return NULL;
}

void LinkedList::Insert(int index, int x){
    Node* t, *p = first;
    if(index <0 || index > count()){
        return;
    }
    
    t = new Node;
    t->data = x;
    t->next=NULL;
    
    if(index == 0){
        t->next = first;
        first = t;
    }else {
        for(int i = 0; i < index-1; i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

bool LinkedList::checkSorted(){
    int x = INT_MIN;
    Node *p = first;
    while(p != NULL){
        if(p->data < x){
            return false;
        }
        x = p -> data;
        p = p -> next;
    }
    return true;
}

void LinkedList::DeleteDuplicate(){
    Node *p  = first;
    Node *q = p -> next;
    while(q != NULL){
        if(p -> data != q -> data){
            p = q;
            q = q -> next;
        }else {
            p -> next = q -> next;
            free(q);
            q = p->next;
        }
    }
}

void LinkedList::ReverseLinkedList(){
    int* A = new int[count()];
    int i = 0;
    Node *q = first;
    
    while(q != NULL){
        A[i] = q -> data;
        q = q -> next;
        i++;
    }
    
    i--;
    
    q = first;
    while(q != NULL){
        q -> data = A[i];
        i--;
        q = q -> next;
    }
    
}

void LinkedList::Reverse2(){
    Node *q = NULL;
    Node *r = NULL;
    Node *p = first;
    while(p != NULL){
        r = q;
        q = p;
        p = p -> next;
        q -> next = r;
    }
    first = q;
}

void LinkedList::RecReverseLinkedList(){
    RecReverse(first, nullptr);
    
}

void LinkedList::RecReverse(Node* current, Node* prev) {
    if (current == nullptr) {
        first = prev; // 🔁 Update head when recursion hits the end
        return;
    }

    Node* next = current->next;  // Store next node
    RecReverse(next, current);   // Recurse to end of list
    current->next = prev;        // Reverse pointer
}

void LinkedList::concatenate(LinkedList &Second){
    Node *p = first;
    while( p->next != NULL){
        p = p -> next;
    }
    
    p -> next = Second.first;
    Second.first = nullptr;
}

LinkedList LinkedList::Merge(const LinkedList &second) const {
    Node* p = this->first;
    Node* q = second.first;

    LinkedList result;
    Node* last = nullptr;

    // Handle first node creation
    if (p && (!q || p->data <= q->data)) {
        result.first = new Node(p->data);
        p = p->next;
    } else if (q) {
        result.first = new Node(q->data);
        q = q->next;
    }
    last = result.first;

    // Merge remaining nodes
    while (p && q) {
        if (p->data <= q->data) {
            last->next = new Node(p->data);
            p = p->next;
        } else {
            last->next = new Node(q->data);
            q = q->next;
        }
        last = last->next;
    }

    // Append leftovers
    while (p) {
        last->next = new Node(p->data);
        p = p->next;
        last = last->next;
    }
    while (q) {
        last->next = new Node(q->data);
        q = q->next;
        last = last->next;
    }

    return result;
}

void LinkedList::createLoop(int value) {
    Node* temp = first;
    Node* loopStart = nullptr;

    // Find loop start node
    while (temp->next != nullptr) {
        if (temp->data == value) {
            loopStart = temp;
        }
        temp = temp->next;
    }

    // Make last node's next point to loop start
    if (loopStart != nullptr) {
        temp->next = loopStart;
    }
}

bool LinkedList::detectLoop(){
    Node *fast = first;
    Node *slow = first;
    
    while(fast && fast -> next ){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    
    return false;
}


circularLinkedList::circularLinkedList(int A[], int n){
    
    if (n == 0) {
            first= nullptr;
            return;
    }
    
    // Step 1: Create first node
        first= new Node;
        first->data = A[0];
        first->next = first; // Points to itself
        Node* last = first;
    
     
    for (int i = 1; i < n; i++) {
            Node* t = new Node;
            t->data = A[i];
            t->next = first;// t->next = head
            last->next = t;       // link last node to new node
            last = t;             // move last pointer
        }
}

void circularLinkedList::Display(){
    Node *p = first;
    if(p == nullptr) return;
    do {
        cout << p->data << " ";
        p = p -> next;
    }while(p != first);
    
    cout << endl;
}


circularLinkedList::~circularLinkedList() {
    // even empty is fine
}

void circularLinkedList::Insert(int index, int x){
    Node* t;
    Node* p = first;
    
    t = new Node;
    t -> data = x;
    
    //insertion at head
    if(index == 0){
        if(!first){
            first = t;
            first -> next = first;
        }else{
            while(p ->next != first) p = p -> next;
            p -> next = t;
            t -> next = first;
            first = t;
        }
    }else {
        for(int i = 0; i < index -1 && p -> next != first; i++){
            p = p->next;
        }
        t -> next = p -> next;
        p -> next = t;
        
    }
}

void circularLinkedList::Delete(int index){
    if(!first){
        return;
    }
    
    Node* p = first;
    if(index == 1){
        if(first -> next == first){
            delete first;
            first = nullptr;
        }else {
            while(p->next !=  first) p = p ->next;
            p->next = first->next;
            delete first;
            first = p->next;
        }
    }else {
        Node* q = nullptr;
        for (int i = 0; i < index - 2 && p->next != first; i++) {
            p = p->next;
        }
        q = p -> next;
        p -> next = q -> next;
        delete q;
    }
}


DoublyLinkedList::DoublyLinkedList(int A[], int n){
    if (n == 0) {
        first= nullptr;
        return;
    }
    
    first = new doublyNode(A[0]);
    doublyNode* last = first;
    
    for(int i = 1;  i < n; i++){
        doublyNode* t = new doublyNode(A[i]);
        t -> prev = last;
        last -> next = t;
        last = t;
    }
    
}

void DoublyLinkedList::Display(){
    doublyNode* p = first;
    
    while(p){
        cout << p->data << " ";
        p = p -> next;
    }
    cout << endl;
}

DoublyLinkedList::~DoublyLinkedList() {
   doublyNode* p = first;
    while (first){
        first= first->next;
        delete p;
        p = first;
    }
}

int DoublyLinkedList::Length() {
    int length = 0;
    doublyNode* p = first;
    while (p != nullptr){
        length++;
        p = p->next;
    }
    return length;
}
 
 

void DoublyLinkedList::insert(int index, int val) {
    if (index < 0 || index > Length()) return; // invalid index

    doublyNode* t = new doublyNode(val);

    // Insert at head
    if (index == 0) {
        t->next = first;
        if (first) first->prev = t;
        first = t;
        return;
    }

    // Insert in middle or tail
    doublyNode* p = first;
    for (int i = 0; i < index - 1; i++)
        p = p->next;

    t->next = p->next;
    t->prev = p;
    if (p->next) p->next->prev = t;
    p->next = t;
}


void DoublyLinkedList::Delete(int index){
    int len = Length();
    
    if (!first|| index<= 0 || index> len) return;
    
    doublyNode* temp = first;
    //case:1 delete node at the head
    if(index == 1){
        first = first -> next;
        if(first) first -> prev = NULL;
        delete temp;
        return;
    }
    
    //traverse the node at the position
    for(int i  = 1; i < index; i++){
        temp = temp->next;
    }
    
    if(!temp->next){
        temp->prev->next = NULL;
        delete temp;
        return;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    
}

void DoublyLinkedList::reverse(){
    if(!first) return;
    
    doublyNode* current = first;
    doublyNode* temp = NULL;
    
    while(current){
        temp = current -> prev;
        current -> prev= current -> next;
        current -> next = temp;
        current = current -> prev;
    }
    
    if (temp){
        first = temp -> prev;
    }
}




