/*
-------------------------------- Program 24 --------------------------------------
Write a program which accept source singly linear linked
list and destination singly linear linked list and
check whether source list is sub list of destination list. Function
returns last position at which sub list found.
Function Prototype :
int SubList(
struct node **Src , struct node **Dest
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

//to get length of list
int getLength(struct node *head) {
        struct node *temp = head;
        int count = 0;
        while(temp != NULL ) {
                count++;
                temp = temp->next;
        }
        return count;

}


// last sub list function 
int SubList(struct node **src, struct node **dest ) {
	
		//temp variable for traversal
		struct node *srcTemp = *src;
		struct node *destTemp = *dest;

		//calculate length of the lists
		int srcLen = getLength(*src);
		int destLen = getLength(*dest);
		
		//if length length if src is less then return
		if(srcLen > destLen)
			return -1;
		int countSub=0,start, count=0;	//countSub of track the matching char

	
		
		while(destTemp!= NULL) {
				count++;
				if(srcTemp == NULL) { 
					srcTemp = *src;
					countSub=0;
				}
				if(srcTemp->no == destTemp->no) {	
					//std::cout << "*****\n";
					countSub++;
					srcTemp = srcTemp->next;	
					if(countSub == 1) 
						start = count;	//to get starting postion of substring
				}else {
					srcTemp =*src;
					countSub=0;
				}
				destTemp = destTemp->next;
		}
			
		//std::cout << "*****\n";
		
		if(countSub == srcLen) 
			return start;
		else
			return 0;
 
}

//display function
void displayList(struct node* head) {
        struct node* temp =head;
	if(head ==NULL) {
		std::cout << "-----------List Is Empty--------------";
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
	int src, dest ,data;

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
	
	//call concta fun
	int status = SubList(&srcHead, &destHead); 
	if(status > 0)  {
		std::cout << "\nSub List is present in the destinaiton list at location " << status << std::endl;
	}
	else if(status == -1)
		std::cout << "\nLength of the source list is greater than the destination. " << std::endl;  
	else 
		std::cout << "source is not sublist of destination" << std::endl;
	
		
}
