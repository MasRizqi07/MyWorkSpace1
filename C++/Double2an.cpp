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
    simpul *awal = NULL,*akhir = NULL,*baru,*bantu,*bantu1;
    int data1; int tekan,jawab,hapus;

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


    cout<< " ingin tambah akhir tekan 1=";
    cin>>tekan;
    }
    while( tekan==1);

    bantu=awal;

    while( bantu != NULL )
    {
        cout <<bantu->data<< " ";
        bantu=bantu->next;
    }

    cout<<" apakah ingin hapus data awal jika ya tekan 1=";
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
                    bantu=awal->next;
                    bantu->prev=NULL;
                    awal=bantu;
                    akhir->prev=bantu;
                    bantu->next=NULL;
                    akhir=bantu;
					}
                cout<<" ingin hapus  lagi=";
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