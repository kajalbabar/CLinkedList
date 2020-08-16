/*

--------------------Program 1-------------------------
Program 1. Write a program which add new node in singly linear
linked list at first position.
Function Prototype :
int InsertFirst(struct node **Head, int no);
__________________________________________________________________________________________________________________________________
*/


#include <iostream>
#include <malloc.h>

//structure declareation
struct node {
	int no;
	// Data element
	struct node *next; // Address of next node
};


//insert first function
int insertAtFirst(struct node **head , int no) {

		struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
		struct node* temp = *head;
		newNode->no = no;	//copy data from user
		newNode->next = NULL;

		if(*head ==NULL) {
			*head == newNode;
			return 0;
		}else {

			newNode->next = *head ;
			*head = newNode;
			return 0;
		}

} //end of function



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
}

//display function
void displayList(struct node* head) {
	struct node* temp =head;
	
	//last node condition
	while(temp !=NULL) {
		std::cout <<"|"<<temp->no <<"|"; 
		temp = temp->next;
		if(temp !=NULL) 	
			std::cout << " --> ";	

	}
	std::cout << std::endl;
}


//main function
int main() {
	struct node *head=NULL;
	
	int n,data;
	std::cout << "Enter number of nodes for the list: " ;
	std::cin >> n;
	
	//first create a list	
	for(int i=0; i<n; i++) {
		std::cout <<"Enter data "<< i+1 << ": ";
		head = createNode(head);
	}
	
	//display function
	std::cout << "************Original List:************" <<std::endl;
	displayList(head);
	
	std::cout << "Enter new data to insert: ";
	std::cin >> data;
	
	
	int status = insertAtFirst(&head, data);
	if(status == 0) {
			std::cout << "\n************* Inserted Successfully *************\n " <<std::endl;
			displayList(head);
	} else {
			std::cout << "\n************* Failed  *************\n " <<std::endl;
	}
	return 0;
}
