#include <cstdlib> // standard library
#include <iostream>

#include "List.h" // include the header file

using namespace std;

List::List(){ // class_name::constructor

	head = NULL;
	curr = NULL;
	temp = NULL;

}

void List::AddNode(int addData){
	
	nodePtr n = new node;// this is the end node
	n->next = NULL;
	n->data = addData;

	if(head != NULL){
		
		curr = head;// make current pointer points to the head

		while(curr->next != NULL){ // make current pointer to the last
			curr = curr->next;
		}

		curr->next = n; // make sure current pointer is point to n now

	} else{

		head = n; // create a new list if there's no list

	}
}

void List::DeleteNode(int delData){
	
	nodePtr delPtr = NULL; // create a node pointer points nothing
	temp = head;
	curr = head;
	
	while(curr != NULL && curr->data != delData){// if current is the last one, then it didn't find the delete-required data

		// pass the value before delete value to temp and delete value to curr
		temp = curr;
		curr = curr->next;

	}

	if(curr == NULL){ // passed the entire list and didn't find the data we want to delete

		cout << delData << " was not in the list.\n";
		delete delPtr; // free the pointer

	} else{

		delPtr = curr; // deletion pointer is pointing to the data we want to delete
		curr = curr->next; // make current pointer points to next
		temp->next = curr; // make the link to next
	
		if(delPtr == head){
			
			head = head->next;
		//	temp = temp->next; // this line is the same as the next line, at this time, it doesn't matter where temp points to
		//	temp = NULL; // we can just skip this

		}

		delete delPtr; // free the pointer
		cout << "The value " << delData << " was deleted.\n";

	}

}

void List::PrintList(){
	
	curr = head;

	while(curr != NULL){ // as long as it is not the last element in the list

		cout << curr->data << endl; 
		curr = curr->next;

	}
}