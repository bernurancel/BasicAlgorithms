#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//----------------------------------------------------------------
void computeLPSArray(string* pat, int M, int* lps); 
//----------------------------------------------------------------
void KMPSearch(int m,int n,string* pat, string* txt) { // Prints occurrences of txt[] in pat[] 
    int M = m; 
    int N = n; 
    int lps[M];  // create lps[] that will hold the longest prefix suffix values for pattern 
  
    computeLPSArray(pat, M, lps); // Preprocess the pattern (calculate lps[] array) 
    int count=0;
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
        if (j == M) { 
            cout<<endl;
            printf("eslesme index %d de yapildi ", i - j); cout<<endl;
            j = lps[j - 1]; 
            count++;
        }  
        else if (i < N && pat[j] != txt[i]) { // mismatch after j matches
            if (j != 0)   // Do not match lps[0..lps[j-1]] characters,they will match anyway 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    cout<<endl<<"ESLESME "<<count<<" KERE BULUNDU...";
} 
//----------------------------------------------------------------
void computeLPSArray(string* pat, int M, int* lps){ // Fills lps[] for given patttern pat[0..M-1] 
    int len = 0; // length of the previous longest prefix suffix 
    lps[0] = 0; // lps[0] is always 0 
  
    int i = 1; // the loop calculates lps[i] for i = 1 to M-1 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. AAACAAAA and i = 7. The idea is similar to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
                // Also, note that we do not increment i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
//----------------------------------------------------------------
int main(){
	int n,m;
	srand( (unsigned)time( NULL ) );
	cout<<"lutfen A dizisinin eleman sayisini giriniz = " ; cin>>n;
	cout<<"lutfen B dizisinin eleman sayisini giriniz = " ; cin>>m;
string A[n],B[m]; 

cout<<endl<<endl<<n<<" elemanli random A dizisi olusturuldu."<<endl<<"-----------------------------------------"<<endl;
for(int i=0;i<n;i++){
	A[i]=rand()%2+48;
	cout<<A[i]<<" ";
}
cout<<endl<<endl<<m<<" elemanli random B dizisi olusturuldu."<<endl<<"---------------------------------------"<<endl;
for(int i=0;i<m;i++){
	B[i]=rand()%2+48;
	cout<<B[i]<<" ";
}
cout<<endl<<endl;
 KMPSearch(m,n,B,A); 
return 0;
}
