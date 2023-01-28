#include <iostream>
#include"kurir.h"

using namespace std;

int main()
{
    listKurir L;
    int pilihan;

    string nama,kota,idkurir;
    int umur;

    string idpaket,asal,tujuan;

    adrKurir K;
    adrPaket P;

    pilihan = selectMenu();
    createListKurir(L);

    insertKurir(L,newElementKurir(newDataKurir("100","Jaka","Bandung",20)));
    insertKurir(L,newElementKurir(newDataKurir("101","Putri","Bandung",21)));
    insertKurir(L,newElementKurir(newDataKurir("102","Denis","Bandung",19)));
    insertKurir(L,newElementKurir(newDataKurir("103","Hawari","Bandung",19)));
    insertKurir(L,newElementKurir(newDataKurir("104","Rafli","Bandung",18)));

    P = newElementPaket(newDataPaket("A01","Jakarta","Bekasi"));
    connect(L,P,"100");
    P = newElementPaket(newDataPaket("A05","Jakarta","Bekasi"));
    connect(L,P,"100");
    P = newElementPaket(newDataPaket("A06","Jakarta","Bekasi"));
    connect(L,P,"100");
     P = newElementPaket(newDataPaket("A08","Jakarta","Bekasi"));
    connect(L,P,"100");

    P = newElementPaket(newDataPaket("A02","Karawang","Bogor"));
    connect(L,P,"101");
    P = newElementPaket(newDataPaket("A03","Surabaya","Magelang"));
    connect(L,P,"102");
    P = newElementPaket(newDataPaket("A04","Surabaya","Magelang"));
    connect(L,P,"103");
    P = newElementPaket(newDataPaket("A05","Surabaya","Magelang"));
    connect(L,P,"104");




    while(pilihan != 0){
        switch(pilihan){
        case 1:{
            cout<<"idkurir : ";
            cin>>idkurir;
            cout<<"Nama : ";
            cin>>nama;
            cout<<"Kota : ";
            cin>>kota;
            cout<<"Umur : ";
            cin>>umur;

            insertKurir(L,newElementKurir(newDataKurir(idkurir,nama,kota,umur)));
        }break;
        case 2:{
            showDataKurir(L);
        }break;
        case 3:{
            cout<<"idpaket : ";
            cin>>idpaket;
            cout<<"asal : ";
            cin>>asal;
            cout<<"tujuan : ";
            cin>>tujuan;

            cout<<"idkurir : ";
            cin>>idkurir;

            P = newElementPaket(newDataPaket(idpaket,asal,tujuan));
            connect(L,P,idkurir);

        }break;
        case 4:{
            showKurirPaket(L);
        }break;
        case 5:{
            cout<<"idkurir : ";
            cin>>idkurir;

            deleteKurirPaket(L,K,idkurir);
        }break;
        case 6:{
            cout<<"idkurir : ";
            cin>>idkurir;
            cout<<"idpaket : ";
            cin>>idpaket;

            deletePaket(L,idpaket,idkurir,P);
        }break;
        case 7:{
            minimalKurir(L);
        }break;


    }
    pilihan = selectMenu();

    }
}

