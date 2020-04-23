#include <iostream>
using namespace std;
//----------------------------------------------------------------	
class list{ 
public:	
 int data; 
 list *next;    
 void ekle(int);
 void listele();
 bool ElemanVar(list*head,int);
};
list *head; 
//--------------------------------------------------------------
void list::ekle(int sayi){
 list *newlist=new list;     // eklenecek nesne için yer açýlýr.
 newlist->data=sayi;         // data ve next pointerlar atanýr.
 newlist->next=0;
 list *p=head;             // listede dolaþýcak bir pointer ayarlanýr.
 if(p==0) 
  head=newlist;
 else
 {
  while(p->next!=0)
     p=p->next;
  p->next=newlist;    // en sona gelindiðinde eleman eklenmiþ olur.
  p->next->next=NULL;
 }
}
//---------------------------------------------------------------
void list::listele()
{
 list *p=head;
 int i=1;
 if(p==0)
  cout<<"liste boss."<<endl;
 else      
 {
 	cout<<endl;
  while(p)        // NULL elemana kadar gidip ekrana yazdýrýlýyor.
  {
   cout<<p->data<<"  ";
   p=p->next;
  }                           
 }
}
//---------------------------------------------------------------
bool list::ElemanVar(list *head,int aranacakDeger){
 list *p=head;
 while(p){
     if(p->data==aranacakDeger)
      return p->data;
     else
	  return ElemanVar(p->next,aranacakDeger);	 
}
 return false;
}
//----------------------------------------------------------------	
int main(){
 list BA;
 int sayi,elemanSayisi,aranacakDeger;
cout<<"Bagli liste kac elemandan olusacak?"; cin>> elemanSayisi; 

for(int i=1;i<=elemanSayisi;i++){
    cout<<i<<". elemanin sayi degerini giriniz:"; cin>> sayi;
    BA.ekle(sayi);
}
BA.listele(); 
cout<<endl<<endl<< "listede aranacak degeri giriniz:"; cin>> aranacakDeger;
 
 if(BA.ElemanVar(head,aranacakDeger)== false)
     cout<<endl<<" Aranan sayi bagli listede bulunmamaktadir!!!";
     else{	
	  	list*p=head;
	  	cout<<endl<<"Listedeki elemanlarin pozitif tam sayi bölenler: "<<endl;
	  	for(int k=0;k<elemanSayisi;k++){
	  		
	  		cout<<endl<<p->data << " sayisinin pozitif tam sayi bolen sayisi--> ";
	        for (int i=1; i<=p->data; i++){
	            if(p->data%i==0)
	              cout<<'\t'<<i;     
		        else
		         continue;
            }
         p=p->next;
       }
   }
return 0;
}
