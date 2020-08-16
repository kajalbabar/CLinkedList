/*
------------------------------ PROGRAM 5 ---------------------------------
Program 5. Write a program which remove last node from singly
linear linked list.
Function Prototype :
int DeleteLast(
struct node **Head
);
______________________________________________________________________________________________________________________________________
*/

#include <iostream>
#include <stdlib.h>

//structure declareation
struct node {
	int no;
	// Data element
	struct node *next; // Address of next node
};


//delete first node 
int deleteLastNode(struct node** head) {
		
		struct node *temp = *head;
		if(head == NULL) {	
			return 0;
		}else {
			while(temp->next->next !=NULL) {
				temp = temp->next;
			}	
						
			free(temp->next);
			temp->next = NULL;
			return 0;
		}
			
	
}

//create node function
struct node* createNode(struct node* head) {
		//allocate memory
		struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
		struct node* temp = head;
		std::cin >> newNode->no;	//accpet data from user
		newNode->next = NULL;

		if(head == NULL){
			head = newNode;
		}else {
			
			while(temp->next != NULL) 	//traverse upto the last node
				temp=temp->next;
			temp->next = newNode;	
		}
	
		return head;
}//end of function


//display function
void displayList(struct node* head) {
	
	struct node* temp =head;
	
	if(temp == NULL) {
		std::cout << "\t******* List is Empty *******" << std::endl;
	}else {
		//last node condition
		while(temp !=NULL) {
			std::cout <<"|"<<temp->no <<"|"; 
			temp = temp->next;
			if(temp !=NULL) 	
				std::cout << " --> ";	

		}
	}
	std::cout << std::endl;
}

int main() {
	struct node * head= NULL;
	
	int n , data , status, pos;

	std::cout << "Enter number of nodes for the list: " ;
	std::cin >> n;
	
	//first create a list	
	for(int i=0; i<n; i++) {
		std::cout <<"Enter data "<< i+1 << ": ";
		head = createNode(head);
	}

	//display function
	std::cout << "\nOriginal List:" <<std::endl;
	displayList(head);



	//call function for insertion
	status = deleteLastNode(&head);
	
	//check inserted or not
	if(status == 0) {
		std::cout << "\n\t*********deleted Successfully******" <<std::endl;
		std::cout << "\nAfter deletion of last node:" <<std::endl;
		displayList(head);
	}else { 
		std::cout << "\t******** deletion failed ***********" <<std::endl;
	}

	return 0;
}
