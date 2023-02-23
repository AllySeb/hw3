#include "llrec.h"
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	Node* temp = head;
  
  if (temp == nullptr){ // base case
    smaller = nullptr;
    larger = nullptr;
		return;
  }

  llpivot(head->next, smaller, larger, pivot);
	if (head->val <= pivot){
    // move ptr to next
    if (smaller == nullptr){
      // beginning smaller
      smaller = temp;
			temp->next = NULL;
			head = nullptr;
    }
    else{
      // when already Node*'s in smaller
      temp->next = smaller;
      smaller = temp;
			head = nullptr;
    }
  }
  else if (head->val > pivot){
    // move ptr to next
    if (larger == nullptr){
      // beginning larger
      larger = temp;
			temp->next = NULL;
			head = nullptr;
    }
    else{
      // when already Node*'s in larger
      temp->next = larger;
      larger = temp;
			head = nullptr;
    }
  }
}


