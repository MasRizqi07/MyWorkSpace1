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
    simpul *awal=NULL,*akhir=NULL,*baru,*bantu,*bantu1;
    int data1, data_sisip; int tekan,jawab;

    do
    {
    cout<<"masukkan data=";
    cin>>data1;

        baru= new simpul;
        baru->data= data1;
        baru->next=NULL;
        baru->prev=NULL;

    if (akhir==NULL)
    {

        awal=baru;
        akhir=baru;
    }
    else
    {

        akhir->next=baru;
        baru->prev=akhir;
        akhir=baru;
    }


    cout<< " ingin tambah akhir tekan 1 = ";

    cin>>tekan;
    }
    while( tekan==1);

        bantu=awal;
        while( bantu != NULL )
        {
        cout <<bantu->data<< " ";
        bantu=bantu->next;
        }
    cout<<" apakah ingin sisip tengah jika iya tekan 1 =";
    cin>>jawab;

    if (jawab==1)
    {
        baru= new simpul;
        cout<<"masukkan data sisip baru=";
        cin>>data1;
        baru->data=data1;
        cout<<"masukkan data setelah apa=";
        cin>>data_sisip;
        bantu=awal;
        while(bantu->data!=data_sisip)
            bantu=bantu->next;

        bantu1=bantu->next;
        bantu1->prev=baru;
        bantu->next=baru;
        baru->prev=bantu;
        baru->next=bantu1;
        }
        bantu=awal;
        while( bantu != NULL )
        {
        cout <<bantu->data<< " ";
        bantu=bantu->next;
        }
    return 0;
}