#include"kurir.h"

void createListKurir(listKurir &L){
    /**
    I.S. -
    F.S. telah dibuat sebuah listKurir L dengan first nil
    **/
    first(L) = nil;
}
infotypeKurir newDataKurir(string idkurir,string nama,string kota,int umur){
    /**
    mengembalikan data Kurir baru sesuai inputan user
    **/
    infotypeKurir data;

    data.idkurir = idkurir;
    data.nama = nama;
    data.kota = kota;
    data.umur = umur;

    return data;
}
infotypePaket newDataPaket(string idpaket,string asal,string tujuan){
    /**
    mengembalikan data Paket baru sesuai inputan user
    **/
    infotypePaket data;

    data.asal = asal;
    data.idpaket = idpaket;
    data.tujuan = tujuan;

    return data;
}
adrKurir newElementKurir(infotypeKurir data){
    /**
    Mengembalikan P yang bertipe adrKurir yang berisi input bertipe kurir
    **/
    adrKurir p = new elmKurir;
    info(p) = data;
    next(p) = nil;
    paket(p) = nil;

    return p;
}
adrPaket newElementPaket(infotypePaket data){
    /**
    Mengembalikan P yang bertipe adrPaket yang berisi input bertipe paket
    **/
    adrPaket p = new elmPaket;
    info(p) = data;
    next(p) = nil;

    return p;
}
void insertKurir(listKurir &L,adrKurir p){
    //insertLast CSLL
    /**
    I.S. listKurir L mungkin kosong
    F.S. seorang kurir P telah ditambahkan setelah elemen terakhir
    **/
    adrKurir Q = first(L);
    if(first(L)==nil){
        first(L) = p;
        next(p) = first(L);
    }else{
        next(p) = first(L);
        while(next(Q)!= first(L)){
            Q = next(Q);
        }
        next(Q) = p;
    }
}
void showDataKurir(listKurir L){
    /**
    I.S. terdefinisi sebuah listKurir L, mungkin kosong
    F.S. semua data kurir sudah ditampilkan
    **/
    adrKurir Q = first(L);
    if(first(L)==nil){
        cout<<"List Kosong ";
    }else{
        cout<<"===============Data Kurir==============="<<endl;
        do{
            cout<<"id kurir : "<<info(Q).idkurir<<"|"<<" Nama : "<<info(Q).nama<<"|"<<" Umur : "<<info(Q).umur<<"|"<<" Kota : "<<info(Q).kota;
            Q = next(Q);
            cout<<endl;
        }while(Q !=first(L));
    }
}
adrKurir searchKurir(listKurir L,string idkurir){
    /**
    Mengembalikan pointer alamat adrKurir apabila terdapat seorang kurir sesuai dengan parameter input
    dan mengembalikan nil apabila sebaliknya
    **/
    adrKurir Q = first(L);
    bool found = false;
    do{
        if(info(Q).idkurir == idkurir){
            found = true;
        }else{
            Q = next(Q);
        }
    }while(Q !=first(L)&&!found);
    if(found){
        return Q;
    }else{
        return nil;
    }
}
void connect(listKurir &L,adrPaket p,string idkurir){
    //insertfirst
    /** I.S. terdefinisi Kurir L dan pointer Paket yang akan dimasukkan ke kurir tertentu
    F.S. paket yang tersimpan di pointer P sudah masuk ke salah satu kurir yang dipilih
    **/
    adrKurir Q = searchKurir(L,idkurir);

    if(paket(Q)==nil){
        paket(Q) = p;
    }else{
        next(p) = paket(Q);
        paket(Q) = p;
    }
}
void showKurirPaket(listKurir L){
    /**
    I.S. terdefinisi sebuah listKurir L, mungkin kosong
    F.S. semua data kurir beserta data paketnya ditampilkan
    **/
    adrKurir Q = first(L);
    if(first(L)==nil){
        cout<<"list kosong";
    }
    else{
        do{
        cout<<"Data Kurir"<<endl;
        cout<<"id kurir : "<<info(Q).idkurir<<"|"<<" Nama : "<<info(Q).nama<<"|"<<" Umur : "<<info(Q).umur<<"|"<<" Kota : "<<info(Q).kota<<endl;
        adrPaket p = paket(Q);
        cout<<"Data Paket"<<endl;
        while(p != nil){
            cout<<"id paket : "<<info(p).idpaket<<"|"<<" Asal : "<<info(p).asal<<"|"<<" Tujuan : "<<info(p).tujuan<<endl;
            p = next(p);
        }
        Q = next(Q);
    }while(Q != first(L));
    }
}
adrPaket SearchPaket(listKurir L,string idpaket,string idkurir){
    /**
    Mengembalikan pointer alamat adrPaket apabila data kurir sesuai dengan parameter input dan terdapat paket sesuai dengan parameter input
    dan mengembalikan nil apabila sebaliknya
    **/
    //kode unik
    bool found = false;
    adrKurir Q = searchKurir(L,idkurir);
    adrPaket p  = paket(Q);
    while( p != nil && !found){
        if(info(p).idpaket == idpaket){
            found = true;
        }else{
            p = next(p);
        }
    }
    if(found){
        return p;
    }else{
        return nil;
    }
}
void deleteKurirPaket(listKurir &L,adrKurir &p,string idkurir){
    /** I.S. terdefinisi sebuah listKurir L, mungkin kosong
    F.S. elemen paket sudah terhapus sesuai yang diminta parameter
    **/
    adrKurir prec ;
    adrKurir j = first(L);
    do{
            j = next(j);
        }while(j!=first(L));
    adrKurir Q =  searchKurir(L,idkurir);
    if(Q == nil){
        cout<<"kurir tidak ditemukan"<<endl;
    }
    else if(paket(Q)== nil){
        cout<<"kurir tidak mempunyai paket"<<endl;
    }else{
        }if(info(first(L)).idkurir == info(Q).idkurir){
            deleteFirstKurir(L,p);
        }else if (info(j).idkurir == info(Q).idkurir){
            deleteLastKurir(L,p);
        }else{
            prec = first(L);
            while(next(prec)!= Q){
                prec = next(prec);
            }
            deleteAfterKurir(L,p,prec);

    }
}
void deletePaket(listKurir &L,string idpaket,string idkurir,adrPaket &p){
    /** I.S. terdefinisi sebuah listKurir L yang mempunyai child berupa paket berdasarkan parameter input,paket mungkin kosong
    F.S. elemen child telah terhapus sesuai yang diminta parameter
    **/
    adrPaket y = SearchPaket(L,idpaket,idkurir);
    adrKurir Q = searchKurir(L,idkurir);
    adrPaket x = paket(Q);
    while(next(x)!=nil){
        x = next(x);
    }
    if(Q == nil){
        cout<<"kurir tidak ditemukan"<<endl;
    }
    else if(paket(Q)== nil){
        cout<<"kurir tidak mempunyai paket"<<endl;
    }else{
        if(info(paket(Q)).idpaket == idpaket){
            deleteFirstPaket(paket(Q),p);
        }else if(info(x).idpaket == idpaket){
            deleteLastPaket(paket(Q),p);
        }else{
            adrPaket prec = paket(Q);
            while(next(prec)!= y){
                prec = next(prec);
            }
            deleteAfterPaket(paket(Q),p,prec);
        }

    }
}
void minimalKurir(listKurir L){
   /** I.S. terdefinisi sebuah listKurir L, List tidak kosong
    F.S. data kurir yang memliki paket paling sedikit ditampilkan
    **/
    int jml,Min;
    adrKurir Q = first(L);
    do{
        jml = 0;
        adrPaket P = paket(Q);
        while(P != nil){
            jml++;
            P = next(P);
        }
        if(Min > jml || Min == jml){
            Min = jml;
        }
        Q = next(Q);
    }while(Q!=first(L));

    Q = first(L);
    do{
        jml = 0;
        adrPaket P = paket(Q);
        while(P != nil){
            jml++;
            P = next(P);
        }
        if(Min > jml || Min == jml){
            Min = jml;
            cout<<"id kurir : "<<info(Q).idkurir<<" Nama :"<<info(Q).nama<<" Umur :"<<info(Q).umur<<" Kota :"<<info(Q).kota<<endl;
        }
        Q = next(Q);
    }while(Q!=first(L));

}
void deleteFirstKurir(listKurir &L,adrKurir &p){
    /** I.S. terdefinisi sebuah listPeserta L
    F.S. elemen pertama dari list L telah dihapus dan disimpan dalam pointer alamat P
    **/
    adrKurir Q = first(L);
    if(next(first(L))==first(L)){
        p = first(L);
        next(p) = nil;
        first(L) = nil;
    }else{
       do{
        Q = next(Q);
       }while(Q != first(L));
       p =first(L);
       next(Q) = first(L);
       next(p) = nil;
    }
}
void deleteLastKurir(listKurir &L,adrKurir &p){
    /** I.S. terdefinisi sebuah listPeserta L
    F.S. elemen terakhir dari list L telah dihapus dan disimpan dalam pointer alamat P
    **/
    adrKurir Q = first(L);
    if(next(first(L))==first(L)){
        p = first(L);
        next(p) = nil;
        first(L) = nil;
    }else{
        do{
        Q = next(Q);
        }while(next(Q)!= first(L));
        p = next(Q);
        next(Q) = first(L);
        next(p) = nil;
    }
}
void deleteAfterKurir(listKurir &L,adrKurir &p,adrKurir prec){
    /** I.S. terdefinisi sebuah listPeserta L
    F.S. elemen setelah prec dari list L telah dihapus dan disimpan dalam pointer alamat P
    **/
    if(next(first(L))==first(L)){
        p = first(L);
        next(p) = nil;
        first(L) = nil;
    }else{
        p = next(prec);
        next(prec) = next(p);
        next(p) = nil;
    }
}
void deleteFirstPaket(adrPaket &Q,adrPaket &p){
    /** I.S. terdefinisi sebuah pointer paket yang menunjuk pada child kurir
    F.S. elemen pertama dari child paket telah dihapus dan disimpan dalam pointer alamat P
    **/
    p = Q;
    Q = next(p);
    next(p) = nil;
}
void deleteLastPaket(adrPaket &Q,adrPaket &p){
    /** I.S. terdefinisi sebuah pointer paket yang menunjuk pada child kurir
    F.S. elemen terakhir dari child paket telah dihapus dan disimpan dalam pointer alamat P
    **/
    while(next(Q) != nil){
        p = next(Q);
        next(Q) = nil;
    }
}
void deleteAfterPaket(adrPaket &Q,adrPaket &p,adrPaket prec){
    /** I.S. terdefinisi sebuah pointer paket yang menunjuk pada child kurir
    F.S. elemen setelah prec dari child paket telah dihapus dan disimpan dalam pointer alamat P
    **/
    p = next(prec);
    next(prec) = next(p);
    next(p) = nil;
}
int selectMenu(){
    cout<<"===============Menu==============="<<endl;
    cout<<"1.Insert data kurir dari belakang"<<endl;
    cout<<"2.Show all data kurir "<<endl;
    cout<<"3.insert Data Paket"<<endl;
    cout<<"4.Menampilkan seluruh data kurir beserta paketnya "<<endl;
    cout<<"5.Menghapus data kurir dan paketnya"<<endl;
    cout<<"6.Menghapus data paket pada kurir tertentu"<<endl;
    cout<<"7.Menampilkan kurir yang memiliki paket paling sedikit"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"Pilihan Menu : ";

    int input = 0;
    cin>>input;

    return input;
}
