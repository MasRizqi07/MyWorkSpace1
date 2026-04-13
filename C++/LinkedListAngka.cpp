# include <iostream>
# include <conio.h>
# include <stdio.h>
using namespace std;

struct simpul
   {
   int data;
   simpul *next;
   };
int main()
 {
   simpul *awal = NULL,*akhir = NULL,*baru,*bantu;
   int data1; int tekan,jawab,hapus;

   do
   {
     cout<<"masukkan data=";
     cin>>data1;
      baru= new simpul;
      baru->data= data1;
      baru->next=NULL;
     if (awal==NULL)
     {

        awal=baru;
        akhir=baru;
     }
    else
     {

        akhir->next=baru;
        akhir=baru;
     }

    cout<< " ingin tambah Akhir tekan 1=";
    cin>>tekan;
   }
     while( tekan==1);

      bantu=awal;

    while( bantu != NULL )
     {
        cout <<bantu->data<< " ";
        bantu=bantu->next;
     }
     cout<<"  hapus Awal jk ia tekan 1=";
     cin>>jawab;
     if (jawab==1)
      {
       do
        {
        if (awal==NULL)
           cout<<"maaf list kosong";
         else if (awal==akhir)
             { 
               awal=NULL;
               akhir=NULL;
              }
                else
                 {
                     bantu=awal;
                     awal=bantu->next;
                     bantu=NULL;                  
                  }
                 cout<<" ingin hapus  lagi tekan 1=";
                 cin>>hapus;
               }
                 while(hapus==1);
           }
    bantu=awal;
    while( bantu != NULL )
     {
        cout <<bantu->data<< " ";
        bantu=bantu->next;
     }
 return 0;
 }