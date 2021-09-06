#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iterator>
using namespace std;


void dividir(int a[], int inicial, int final);

void Fusionar(int a[], int pinicial, int pfinal, int medio);



int main()
{
  fstream archivo;

  archivo.open("Mergesort.txt",ios::out);
 int num1,num2,num3,num4;
 
 int A[]={2,3,50,6};
  
  for(int i=0;i<4;i++){
    archivo<<" ["<<A[i]<<"] ";

  }

    dividir(A, 0, 3);
    archivo<<endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "|" << A[i] << "|";
        archivo << "|" << A[i] << "|";


    }

     
    return 0;
}




void dividir(int a[], int inicial, int final)
{

    if (inicial >= final)
    {
        return;
    }
    int m = inicial + (final - inicial) / 2;
    dividir(a, inicial, m);
    dividir(a, m + 1, final);
    Fusionar(a, inicial, m, final);
}


void Fusionar(int arr[], int pinicial, int medio, int pfinal)
{
    int n1 = medio - pinicial + 1;
    int n2 = pfinal - medio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[pinicial + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[medio + 1 + j];


    int i = 0;

    int j = 0;

    int k = pinicial;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
