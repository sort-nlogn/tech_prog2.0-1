#include "Keeper.hpp"

Keeper::Keeper() {
  std::cout << "Keeper defaul constructor has been called" << "\n";
  size = 0;
}

Keeper::~Keeper() {
  std::cout << "Keeper destructor has been called" << "\n";
  delete head;
  delete tail;
}

void Keeper::add(Stuff *stuff){
    Node *temp = new Node;
    temp->stuff = stuff;
    temp->next = NULL;  
    if (head == NULL) {
        head = temp;
        tail = temp;
        temp = NULL;
    }else{
        tail->next = temp;
        tail = temp;
    }
    size++;
    cout << size << "\n";
}

void Keeper::print(){
    if (!size) throw std::runtime_error("The collection is empty");
    Node *temp = new Node;  
    temp = head;
    int counter = 1;
    while(temp != nullptr){
        std::cout << counter++ << ". ";
        temp->stuff->describe(); printf("\n");
        temp = temp->next;
    }
}

void Keeper::remove(int pos) {
    if (!size) throw std::runtime_error("the list of ships is empty");
    if (pos > size || pos < 1) {
      throw std::runtime_error("The number doesn't fall within the range [1; " + std::to_string(size) + "]");
    }
    
    Node *curr = new Node;
    Node *prev = new Node;
    curr = head;
    if (pos == 1) head = head->next;    
    for(int i = 1; i < pos; i++) {
      prev = curr;
      curr = curr->next;
    }
    if (pos == size) {
      tail = prev;
      prev->next = NULL;
      tail->next = NULL;
    } else {
      prev->next = curr->next;
    }
    size--;  
    delete curr->stuff;
}
