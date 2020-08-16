/*
-------------------------------- Program 14 --------------------------------------
Write a program which accepts two singly linear linked
list from user and concat last N elements of source linked list after
destination linked list.
Function Prototype :

int ConcatLastN( struct node **Src ,struct node **Dest, int no );
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




//concatenation of the n nodes of source list to the dest list
int concateLastN(struct node** srcHead, struct node** destHead, int no) {
		
		struct node *tempDest = *destHead;				//pointing to destination list 
		struct node *tempSrc = *srcHead, *tempLast = *srcHead;		//pointing to the src list 
		struct node *temp = NULL;					

		//if src list is NULL then return
		if(*srcHead ==  NULL) 
			return 0;
		
		//get length
		int len = getLength(*srcHead);
		int pos = len - no;
		int count = 0;
			
		//if destination list is empty then directly add src list to the head
		if(*destHead == NULL ) {
				
			while(tempLast !=NULL) {
			     count++;
			     if(count-1 == pos) {
					if(*destHead == NULL) {
						*destHead = tempLast;  	//attach first node to the link list
					}
					
				}
			    tempLast = tempLast->next;		//move next 

			  }
			return 0;
		} 
		//else part
		else {	
				std::cout << "******\n";
				//traverse upto end of dest list	
				while(tempDest->next !=NULL) 
					tempDest = tempDest->next;
				
			   	 while(tempLast !=NULL) {
					count++;
			
				   //attach only n nodes 
				   if(count-1 == pos) {
					tempDest->next = tempLast;	//copy address of nth last  node of srcList into the 
										//	last node of dest list
					//tempDest = tempDest->next;		//move to the next node of dest node
					//no--;
				   }
				   tempLast = tempLast->next;		//move next 
			         }
			    return 0;
		}
}

//display function
void displayList(struct node* head) {
        struct node* temp =head;
	if(head ==NULL) {
		std::cout << "-----------List Is Empty--------------" << std::endl;
	}
	else {
        	//last node condition
        	while(temp !=NULL) {
                	std::cout <<"|"<<temp->no <<"|";
                	temp = temp->next;
                	if(temp !=NULL)
                        	std::cout << " --> ";

        	}
        	std::cout << std::endl;
	}
}


//main function
int main() {

	//head of src and dest link list
	struct node *srcHead= NULL;
	struct node *destHead = NULL;
	int src, dest ,data, n;

	std::cout << "Enter number of nodes in the source list: " ;
	std::cin >> src;
	
	//accept source list	
	for(int i=0; i<src; i++) {
		std::cout <<"Enter data "<< i+1 << ": ";
		srcHead = createNode(srcHead);
	}
	
	std::cout << std::endl << "Enter number of nodes in the destination list: " ;
	std::cin >> dest;

	//accept destination list	
	for(int i=0; i<dest; i++) {
		std::cout <<"Enter data "<< i+1 << ": ";
		destHead = createNode(destHead);
	}
	
	//display src and dest lists
	std::cout << "\nSource List-----------------" << std::endl;
	displayList(srcHead);

	std::cout << "\nDestination List-----------------" << std::endl;
	displayList(destHead);
	
	//accept n
	std::cout << "Enter number of nodes for concatenation:  "; 
	std::cin >> n;

	//call concta fun
	int status = concateLastN(&srcHead, &destHead,n); 
	if(status == 0)  {
		std::cout << "\nConcatenation of two List-------------- " << std::endl;  	
		displayList(destHead);
	}
	else
		std::cout << "\nFailed------------ " << std::endl;  	
		
}
