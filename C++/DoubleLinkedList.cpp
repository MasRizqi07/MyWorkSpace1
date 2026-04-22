# include <iostream>
# include <conio.h>
# include <stdio.h>

using namespace std;
struct simpul
    {
    int data;
    simpul *next;
    simpul *prev;
    };
int main()
    {
    simpul *awal=NULL,*akhir=NULL,*baru,*bantu;
    int data1,tekan;

    do
    {
    cout<<"masukkan data=";
    cin>>data1;

        baru= new simpul;
        baru->data= data1;
        baru->next=NULL;
        baru->prev=NULL;

    if (awal==NULL)
    {

        awal=baru;
        akhir=baru;
    }
    else
    {

        baru->next=awal;
        awal->prev=baru;
        awal=baru;
    }

    cout<< " ingin tambah akhir lagi tekan 1=";
    cin>>tekan;
    }
    while( tekan==1);

    bantu=awal;
    while( bantu!= NULL )
    {
        cout <<bantu->data<< " ";
        bantu=bantu->next;
    }

return 0;
}