/*
Progam 2:Write a program which add new node in singly linear
linked list at last position.
Function Prototype :
int InsertLast(
struct node **Head, int no);
______________________________________________________________________________________________________________________________________
*/

#include <iostream>
#include <malloc.h>

//structure declareation
struct node {
	int no;
	// Data element
	struct node *next; // Address of next node
};


//Insert at last  
int insertLast(struct node** head, int no) {
			
		//allocate memory to new node
		struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
		
		struct node* temp = *head; 		//for traversing
	 
		newNode->no = no;	//copy data accpeted  from user
		newNode->next = NULL;
		
		//if head is null then directly insert
		if(*head ==NULL) {		
			*head =newNode;
			return 0;
		}else {
		
			//traverse upto last
			while(temp->next !=NULL) {
				temp= temp->next;
			}
			//insert at last
			temp->next = newNode; 
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
	
	int n , data , status;
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

	//accept new data
	std::cout << "\nEnter data for insertion at the last pos: ";
	std::cin >> data;
	
	//call function for insertion
	status = insertLast(&head, data);
	
	//check inserted or not
	if(status == 0) {
		std::cout << "\n\t*********Inserted Successfully******" <<std::endl;
	}else { 
		std::cout << "\t*********Insertion Failed***********" <<std::endl;
	}

	std::cout << "\n*****After insertion at last position: ******" <<std::endl;
	displayList(head);
	return 0;
}
