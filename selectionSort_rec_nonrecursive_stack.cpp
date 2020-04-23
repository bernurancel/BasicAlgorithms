#include<iostream>
#include <cstdlib>
using namespace std;
//----------------------------------------------------------------	
class Node { 
public:
	int data;
   Node *next; 
};  
class Stack {
	public:
		Node*top;
		Stack(){top=NULL;}
		void push(int);
		void display();
};
//----------------------------------------------------------------	
void Stack::push(int val) {
   class Node* newnode = (class Node*) malloc(sizeof(class Node)); 
   newnode->data = val; 
   newnode->next = top; 
   top = newnode; 
}
//----------------------------------------------------------------	
void recursiveSort(int array[], int i ,int n) {
	int min = i;
	for (int j = i + 1; j < n; j++)
	{
		if (array[j] < array[min])
			min = j;
	}
int temp = array[min];
	array[min] = array[i];
	array[i] = temp;
	if (i + 1 < n) {
		recursiveSort(array, i + 1, n);
	}
}
//----------------------------------------------------------------
void copyArray(Node*top,int size){
	Node*temp=top;
	int array[size];
	for (int i = 0; i <size; i++) {
		array[i] = temp->data;
		temp= temp->next;
	}
    recursiveSort(array, 0, size);  // call the function of recursive sort...
	for (int i = 0; i < size; i++) { // write to array...
		cout <<'\t'<<array[i] <<endl;
	}	
}
//----------------------------------------------------------------	
void Stack::display() {
   class Node* ptr;
   if(top==NULL)
      cout<<"stack is empty";
   else {   
      ptr = top; 
      cout<<endl;
      while (ptr != NULL) { 
         cout<<'\t'<< ptr->data <<" "<<endl; 
         ptr = ptr->next; 
      } 
   }
   cout<<endl;
}
//----------------------------------------------------------------	
void nonRecursiveSort(Node*top){ 
   Node *temp=top;
   while(temp){
   	Node*min=temp;
   	Node*r=temp->next;
   	while(r){
   		if(min->data>r->data)
   	    	min=r;
   	    r=r->next;
	   }
	   int x =temp->data;
	   temp->data=min->data;
	   min->data=x;
	   temp=temp->next;
   }
}  
//----------------------------------------------------------------
int main(){
	Stack BA;
	int SOS,eleman,secim;  // size of stack
	cout<<"yigina kac eleman ekleyeceksiniz ? ";
	cin>>SOS;
	for(int i=0;i<SOS;i++){
		cout <<i+1<<". elemani girin-->   ";
		cin>>eleman;
		BA.push(eleman);		
	}
	cout<<endl<<"siralama yapilmadan onceki hali; ";
	BA.display();
	
 cout<< "Hangi sekilde siralamak istersimiz?" <<endl <<'\t'<<"1.RECURSIVE SORT" <<endl <<'\t'<< "2.NONRECURSIVE SORT";
 cout<<endl<<endl<<"  SECIMINIZ= ";
 cin>>secim;
 cout<<endl;
 
  switch(secim) {
  case 1 :
       cout << "RESURCIVE SORT " << endl;
       copyArray(BA.top,SOS);
       break;
 case 2:
 	   cout << "NONRESURCIVE SORT " << endl;
 	   nonRecursiveSort(BA.top);
 	   BA.display();
       break;
  default :
       cout << "sadece 1 veya 2 ye basiniz..." << endl;
   }
 return 0;
}
