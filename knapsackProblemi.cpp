#include<iostream>
#include<stdlib.h>
using namespace std;

const int objesay = 5;

class obje {
public:
	int value, weight;
	char sembol;
	obje*next;
	void fill_obj(obje *gelen,int ,char);
	void printobje(obje *gelen,char);
};

void obje::fill_obj(obje *gelen, int K,char name) {
cout<<endl;
	 class obje *ptr =(class obje*) malloc(sizeof(class obje));
	 ptr = gelen;
	 ptr->sembol=name;
	
	while(1){
		cout<<(char)name <<endl ;
		cout << "Enter the Value values :";
	    cin >> ptr->value;
		if(ptr->value>=1 && ptr->value<=25){
			break;
		}
		else
		cout<<"Value value must be  range of 1 and 25 .." <<endl;
		continue;
	}
	while(1){
	cout << "Enter the weight values: ";
	cin >> ptr->weight;
	if(ptr->weight>=1 && ptr->weight<=K)
	{
		break;
	}else
	 cout<<"weight value is range of  1 and  "<<K<<endl;
		continue;
	}
}

void obje::printobje(obje *gelen,char name) {
	cout<<(char)name <<"-> " << "value:" << gelen->value;
	cout << " weight" << gelen->weight << endl;
}

int max(int a, int b){
	return (a > b) ? a : b;
}// C kapasiteli bir knapsack koyulabilecek maximum degeri döndürür

int knapSack(int V[],int W[],int K) {

	int capasity[objesay + 1][K + 1];
cout<<endl;
char k=63;
	for (int i = 0; i <=objesay; i++){ 
	 k++;
	 cout<<endl;
		for (int j = 0; j <= K; j++){
			if (i == 0 || j == 0)
				capasity[i][j] = 0;
			else if (W[i - 1] <= j) {
				capasity[i][j] = max( V[i - 1] + capasity[i - 1][j - W[i - 1]], capasity[i - 1][j]);
			    	cout<<"I am in " << (char)k << " object " <<"  and I have total  "<< j << " weight so " << "--> value = " << capasity[i][j] << endl;
			}
			else{
			capasity[i][j] = capasity[i - 1][j];
			}
		}
	}
	return capasity[objesay][K];
}

int main(){
	
int K;//kapasitiy;
cout << "***K kapasiteli bir canta W agirlikli ve V degerler kumesine sahip Knapsack Probleminin tasarlanmasi***" << endl;
	while (1){
		cout << " Enter the capacity of bag :";
		cin >> K;
		if (K >= 5 && K <= 25){
			break;
		}
		else
			cout << "(Capacity must be range of 5 and 25 ):" << endl;
		continue;
	}
	//obje A;
	obje *A = new obje;
	obje *B = new obje;
	obje *C = new obje;
	obje *D = new obje;
	obje *E = new obje;

	//A.fill_obj(A, K); A.printobje(A);
	A->fill_obj(A, K,'A');  A->printobje(A,'A'); //A->printobje(*A);
	B->fill_obj(B, K,'B'); B->printobje(B,'B');
	C->fill_obj(C, K,'C'); C->printobje(C,'C');
	D->fill_obj(D, K,'D'); D->printobje(D,'D');
	E->fill_obj(E, K,'E'); E->printobje(E,'E');

	int value[5] = {  A->value ,  B->value,  C->value,  D->value ,  E->value };
	int weight[5] = { A->weight ,  B->weight, C->weight , D->weight, E->weight };
	char name[5]={A->sembol , B->sembol , C->sembol , D->sembol , E->sembol};
	cout<<endl;
	for (int i = 0; i < objesay; i++){
		cout<<" ["<< name[i]<<"]->"<<"value:"<<value[i]<<" weight:"<<weight[i]<<" ";
	}

     cout << endl <<"*** MAX VALUE IS = "<<knapSack(value,weight, K)<<" *** ";

	return 0;
}
