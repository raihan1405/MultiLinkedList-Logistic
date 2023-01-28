#ifndef KURIR_H_INCLUDED
#define KURIR_H_INCLUDED

#include<iostream>
using namespace std;

/** Pendefinisian **/
#define nil NULL
#define first(L) L.first
#define next(P) (P)->next
#define paket(Q) (Q)->paket
#define info(P) (P)->info

typedef struct elmKurir *adrKurir;
typedef struct kurir infotypeKurir;

typedef struct elmPaket *adrPaket;
typedef struct paket infotypePaket;

struct kurir{
    string idkurir,nama,kota;
    int umur;
};
struct paket{
    string idpaket,asal,tujuan;
};
struct elmKurir{
    adrKurir next;
    infotypeKurir info;
    adrPaket paket;
};
struct elmPaket{
    adrPaket next;
    infotypePaket info;
};
struct listKurir{
    adrKurir first;
};

void createListKurir(listKurir &L);
adrKurir newElementKurir(infotypeKurir data);
void insertKurir(listKurir &L,adrKurir p); //1.Insert data kurir dari belakang
void showDataKurir(listKurir L); //2.Show all data kurir
int selectMenu();
void hapusKurirPaket(listKurir &L);
adrKurir searchKurir(listKurir L,string nama,string kota,int umur); //4.Mencari data kurir
void connect(listKurir &L,adrPaket p,string idkurir);//5.Insert data paket & 6.	Menghubungkan data kurir ke data paket
void showKurirPaket(listKurir L);//7.Menampilkan seluruh data kurir beserta paketnya
adrPaket newElementPaket(infotypePaket data);
adrPaket SearchPaket(listKurir L,string idpaket,string idkurir);//8.Mencari data paket pada kurir tertentu
void deleteKurirPaket(listKurir &L,adrKurir &p,string idkurir); //3.Menghapus data kurir dan paketnya
infotypeKurir newDataKurir(string idkurir,string nama,string kota,int umur);
infotypePaket newDataPaket(string idpaket,string asal,string tujuan);
void deletePaket(listKurir &L,string idpaket,string idkurir,adrPaket &p);//9.Menghapus data paket pada kurir tertentu
void minimalKurir(listKurir L);//Menampilkan kurir yang memiliki paket paling sedikit
void deleteFirstKurir(listKurir &L,adrKurir &p);
void deleteLastKurir(listKurir &L,adrKurir &p);
void deleteAfterKurir(listKurir &L,adrKurir &p,adrKurir prec);
void deleteFirstPaket(adrPaket &Q,adrPaket &p);
void deleteLastPaket(adrPaket &Q,adrPaket &p);
void deleteAfterPaket(adrPaket &Q,adrPaket &p,adrPaket prec);

#endif // KURIR_H_INCLUDED
