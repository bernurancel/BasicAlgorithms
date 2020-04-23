#include<iostream>
#include <cstdlib>
using namespace std;
//----------------------------------------------------------------	
class Node { 
public:
   int data;
   Node *next;
};
class Queue{
	public:
		Node* front;
		Node* rear;
		Node* temp;
    	Queue(){ front= NULL; rear= NULL; }
    	void enqueue(int);
    	void display();
};
//----------------------------------------------------------------	
void swap(int* xp, int* yp){
	int temp = *xp;
	*xp = *yp; 
	*yp = temp;
}
//----------------------------------------------------------------	
void Queue::enqueue(int val) {
   
   if (rear == NULL) {
      rear = (struct Node *)malloc(sizeof(struct Node));
      rear->next = NULL;
      rear->data = val;
      front = rear;
   } else {
      temp=(struct Node *)malloc(sizeof(struct Node));
      rear->next = temp;
      temp->data = val;
      temp->next = NULL;
      rear = temp;
   }
}
//----------------------------------------------------------------	
void RecursiveSort(int array[], int n) {
		if (n == 1) return;
		for (int i = 0; i < n - 1; i++)
			if (array[i] > array[i + 1])
				swap(&array[i], &array[i + 1]);
		RecursiveSort(array, n - 1);
}
//----------------------------------------------------------------	
void nonRecursiveSort(int array[], int n) {
		int i, j;
		for (i = 0; i < n - 1; i++) {
			for (j = 0; j < n - i - 1; j++) {
				if (array[j] > array[j + 1])
					swap(&array[j], &array[j + 1]);
			}
		}
}
//----------------------------------------------------------------
void printSort(int array[], int n) {
	cout << "Siralanmis hal--->  ";
	for (int i = 0; i < n; i++) {
		cout << array[i] << "  ";
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
cout<< "Hangi sekilde siralamak istersimiz?" <<endl << "1.RECURSIVE SORT" <<endl << "2.NONRECURSIVE SORT";
 cout<<endl <<endl<<"  SECIMINIZ= ";
 int secim;
 cin>>secim;
  switch(secim) {
  case 1 :
       cout<<endl<< "RESURCIVE SORT " << endl;
       nonRecursiveSort(array,size);
       	printSort(array, size);
       break;
 case 2:
 	   cout << "NONRESURCIVE SORT " << endl;
 	   RecursiveSort(array,size);
 	   	printSort(array, size);
       break;
  default :
       cout << "sadece 1 veya 2 ye basiniz..." << endl;
  }
}
//----------------------------------------------------------------	
void Queue::display() {
 temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<endl;
   while (temp != NULL) {
      cout<<'\t'<<temp->data<<" "<<endl;
      temp = temp->next;
   }
   cout<<endl;
}
//----------------------------------------------------------------
int main(){
	Queue BA;
	int SOS,eleman,secim;  // size of queue
	cout<<"kuyruga kac eleman ekleyeceksiniz ? ";
	cin>>SOS;
	for(int i=0;i<SOS;i++){
		cout <<i+1<<". elemani girin-->   ";
		cin>>eleman;
		BA.enqueue(eleman);		
	}
	cout<<"siralama yapilmadan onceki hali; ";
	BA.display();
	copyArray(BA.front,SOS);
 return 0;
}
