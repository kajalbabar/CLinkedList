/*

Write a program which add new node in singly linear
linked list at specified position.
Function Prototype :
int InsertAtPosition(
struct node **Head, int no, int pos
);
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

//to get lenght of list
int getLength(struct node *head) {
	struct node *temp = head;
	int count = 0;
	while(temp != NULL ) {
		count++;
		temp = temp->next;
	}
	return count;

}

//Insert at specific position
int insertAtPosition(struct node** head, int no, int pos) {
		
			
		int count=1;
	
		//allocate memory to new node
		struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
		struct node* temp = *head; 		//for traversing
	 
		newNode->no = no;	//copy data accpeted  from user
		newNode->next = NULL;
		
		int len = getLength(temp);
		//check user enterd wrong pos value or nor
		if(pos > len+1 || count > pos)
                       return -1;
		
		if(*head ==NULL && pos == 1)		
			*head=newNode; 
		else { 
		//travers upto one before position 
		while (count < pos-1) {
			//std::cout << "****"<<std::endl;  
			temp = temp->next;
			count++;	
		}
		//add node 
		newNode->next = temp->next;
		temp->next = newNode;
		}
		return 0;
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

	//accept new data
	std::cout << "\nEnter data for insertion: ";
	std::cin >> data;
	
	std::cout <<"Enter position for insertion: ";
	std::cin >> pos;

	//call function for insertion
	status = insertAtPosition(&head, data, pos);
	
	//check inserted or not
	if(status == 0) {
		std::cout << "\n\t*********Inserted Successfully******" <<std::endl;
		std::cout << "\nAfter insertion at specific position:" <<std::endl;
		displayList(head);
	}else { 
		std::cout << "\t******** Wrong postion entered ***********" <<std::endl;
	}

	return 0;
}
