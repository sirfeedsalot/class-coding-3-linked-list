//04_simple linked list
//!!!SOLUTION!!

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

/**
 * This is only for the 1st Node
 * @param head - pointer to the head of the list
 * @param n - data that the first element should hold
 */
void initNode(struct Node *head, int n) {
  //TODO: Initiliaze the node data to n and the next pointer to..?
    head->data = n;
    head->next = nullptr;
}

/**
 * This funtion addes a node to the end of the list.
 * @param head - pointer to the head of the list
 * @param n - data that the new node should hold
 */
void addNode(struct Node *head, int n) {
  //TODO - Implement this function.
    Node *current;
    Node *new_Node = new Node();

    new_Node -> data = n;// new_Node data stores n
    current = head;// current points to head node
    while(current -> next != nullptr){// iterate until end of linked list
        current = current -> next;
    }
    current -> next = new_Node;// link at end of linked list points to new_Node
    new_Node -> next = nullptr;// new_Node tail points to nullptr
}

/**
 * This funtion adds a node to the front of the list.
 * @param head - pointer to the head of the list
 * @param n - data that the new node should hold
 */
void insertFront(struct Node **head, int n) {
  //TODO
    Node *new_head = new Node();
    new_head -> data = n;
    new_head ->next = *head;
    *head = new_head;
}

/**
 * This function displays the nodes in the list
 * @param head  - pointer to the head of the list
 */
void display(struct Node *head) {
  //TODO
    Node *current = head;

    if(head == nullptr){
        cout<<"No nodes to display: empty list.";
        return;
    }
    do{
        cout<< current-> data << " ";
        current = current -> next;
    }while(current != nullptr);
    cout<< endl;
}

/**
 * This function searches for a node holding n and returns a pointer to it.
 * @param head - pointer to the head of the list
 * @param n - data to search nodes for
 * @return - pointer to the node found.
 */
struct Node *searchNode(struct Node *head, int n) {
    //TODO
    Node *current = head;
    Node *found;

    while (current != nullptr) {
        if (current -> data == n) {
            found = current;
            break;
        }else{
            current = current -> next;
        }
    }
    return found;
}

/**
 * This function deletes a node
 * @param head - pointer to the head of the list
 * @param ptrDel - pointer to the node that is to be deleted
 * @return - boolean that indicates if the deletion was successful
 */
bool deleteNode(struct Node **head, Node *ptrDel) {
  //TODO
    bool tf = false;

    if(*head == ptrDel){// if address in **head is == to ptrDel move to conditional
        *head = ptrDel -> next;// address inherits next node
    }

    Node *current = *head;// current points to address stored in **head
    while(current != nullptr){
        if(current == ptrDel){// if current == to ptrDel node, move to conditional
            current = current -> next;// current inherits next node
            tf = true;
        }else{
         current = current -> next;
        }
    }
  return tf;
}

/* reverse the list */
struct Node *reverse(struct Node **head) {
  Node *parent = *head;
  Node *me = parent->next;
  Node *child = me->next;

  /* make parent as tail */
  parent->next = NULL;
  while (child) {
    me->next = parent;
    parent = me;
    me = child;
    child = child->next;
  }
  me->next = parent;
  *head = me;
  return *head;
}

/* Creating a copy of a linked list */
void copyLinkedList(struct Node *node, struct Node **pNew) {
  if (node != NULL) {
    *pNew = new Node;
    (*pNew)->data = node->data;
    (*pNew)->next = NULL;
    copyLinkedList(node->next, &((*pNew)->next));
  }
}

/* Compare two linked list */
/* return value: same(1), different(0) */
int compareLinkedList(struct Node *node1, struct Node *node2) {
  static int flag;

  /* both lists are NULL */
  if (node1 == NULL && node2 == NULL) {
    flag = 1;
  }
  else {
    if (node1 == NULL || node2 == NULL)
      flag = 0;
    else if (node1->data != node2->data)
      flag = 0;
    else
      compareLinkedList(node1->next, node2->next);
  }

  return flag;
}

void deleteLinkedList(struct Node **node) {
  struct Node *tmpNode;
  while (*node) {
    tmpNode = *node;
    *node = tmpNode->next;
    delete tmpNode;
  }
}

int main() {
  struct Node *newHead;
  struct Node *head = new Node;



  initNode(head,10);
  display(head);

  addNode(head,20);
  display(head);

  addNode(head,30);
  display(head);

  addNode(head,35);
  display(head);

  addNode(head,40);
  display(head);

  insertFront(&head,5);
  display(head);

  int numDel = 5;
  Node *ptrDelete = searchNode(head,numDel);
  if(deleteNode(&head,ptrDelete))
      cout << "Node "<< numDel << " deleted!\n";
  display(head);

  cout << "The list is reversed\n";
  reverse(&head);
  display(head);

  cout << "The list is copied\n";
  copyLinkedList(head,&newHead);
  display(newHead);

  cout << "Comparing the two lists...\n";
  cout << "Are the two lists same?\n";
  if(compareLinkedList(head,newHead))
      cout << "Yes, they are same!\n";
  else
      cout << "No, they are different!\n";
  cout << endl;

  numDel = 35;
  ptrDelete = searchNode(newHead,numDel);
  if(deleteNode(&newHead,ptrDelete)) {
      cout << "Node "<< numDel << " deleted!\n";
      cout << "The new list after the delete is\n";
      display(newHead);
  }
  cout << "Comparing the two lists again...\n";
  cout << "Are the two lists same?\n";
  if(compareLinkedList(head,newHead))
      cout << "Yes, they are same!\n";
  else
      cout << "No, they are different!\n";

  cout << endl;
  cout << "Deleting the copied list\n";
  deleteLinkedList(&newHead);
  display(newHead);

  return 0;
}