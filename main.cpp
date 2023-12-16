#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>

using namespace std;
    int main(){
        int pilihan, admin;

        // variable Login pengelola
        string username="1", password="1", menu, inputUsername, inputPassword;
        int loginCounter=0;

        //  variable Fitur Pengelola
        int pilPengelola ;
        int jmlTambah,  jmlMenu=0, maxMenu=20, pilHapus, pilUbah;


        // variable data menu makanan
        string namaMenu[(maxMenu+1)];
        int hargaMenu[maxMenu+1];

        //variable menu pembelian
        int pilPembeli, pilMakan, jmlPembelian;
        int pilPesanan;
        int jmlPesanan[maxMenu], hargaPesanan[maxMenu], menuPesanan=0, totalHarga=0;
        string namaPesanan[maxMenu];
        char konf, konfBatal;

        // laporan pembelian
        string lapNama[100];
        int lapHarga[100],lapTotal[100], jmlLap=0, totalKeuntungan=0;

        menuAwal:
        do{
            cout<<"======= Menu Awal =======\n";
            cout<<"1.Pengelola"<<endl;
            cout<<"2.Pembeli"<<endl;
            cout<<"3.Exit"<<endl;
            cout<<"Masukan Pilihan : ";
            // while ini buat ngecek tipe data dari input user
            while(!(cin>>pilihan)){
                cin.clear();// buat ngeclear error, kalo ada error, erornya gak dianggap
                cin.ignore(numeric_limits<streamsize>::max(),'\n');//buat nge ignore/skip baris inputan
                system("cls"); // buat nge clear/kosongin command prompt
                cout << "Pilihan tidak valid!" << endl<<endl;
                goto menuAwal;
            }
            cout <<endl;

            // PILIHAN MENU AWAL
            switch (pilihan){
                case 1:
                    // Input Login Pengelola
                    system("cls");
                    do{
                        inputUsername="";
                        inputPassword="";
                        cout<<"Silahkan Login Sebagai Pengelola!"<<endl;
                        cout<<"Username :";
                        cin>>inputUsername;
                        cout<<"Password :";
                        cin>>inputPassword;
                        cout << endl;

                        if (username!=inputUsername || password!=inputPassword){
                            cout<<"Username atau Password Salah! ["<<loginCounter+1<<"/3]"<<endl<<endl;
                            loginCounter++;
                            if(loginCounter==3){
                                system("cls");
                                cout<<"Login gagal!"<<endl;
                                cout << "Kembali ke Menu Awal"<<endl<<endl;
                                goto menuAwal;
                            }

                        }else {
                            system("cls");
                            cout<<"Login Berhasil!"<<endl << endl;
                        }
                    }while (username!=inputUsername || password!=inputPassword);
                    // Akhir Login Pengelola

                    // Awal Menu Pengelola
                    menuPengelola:
                    do{
                        cout<<"======= Menu Pengelola ========="<<endl;
                        cout<<"1.Tambah Menu Makanan (Maks."<<maxMenu<<", ["<<jmlMenu<<"/"<<maxMenu<<"])"<<endl;
                        cout<<"2.Ubah Nama/Harga Menu Makanan"<<endl;
                        cout<<"3.Hapus Menu Makanan"<<endl;
                        cout<<"4.Tampilkan Menu Makanan"<<endl;
                        cout<<"5.Tampilkan Laporan Pembelian"<<endl;
                        cout<<"6.Log Out"<<endl;
                        cout<<"Masukan Pilihan : ";
                        while(!(cin>>pilPengelola)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            system("cls");
                            cout <<"Pilihan tidak valid!" << endl <<endl;
                            goto menuPengelola;
                        }

                        cout<<endl;
                        switch(pilPengelola){
                            case 1:
                                // Awal Fitur Tambah Menu Makanan
                                if (jmlMenu==maxMenu){
                                    system("cls");
                                    cout <<"Jumlah Menu Sudah Maksimal ("<<jmlMenu<<"/"<<maxMenu<<")"<<endl;
                                    cout <<"Tidak Dapat Menambah Menu Lain!"<<endl<<endl;
                                    break;
                                }else{
                                    cout << "Masukan jumlah menu yang akan ditambahkan"<<endl;
                                    cout << "Masukan 0 untuk membatalkan"<<endl;
                                    cout << "Jumlah : ";
                                    while(!(cin>>jmlTambah) || jmlTambah < 0){
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        system("cls");
                                        cout << "Jumlah tidak valid!" << endl;
                                        cout << "Tambah menu dibatalkan!" << endl <<endl;
                                        goto menuPengelola;
                                    }
                                    cout <<endl;
                                    if(jmlMenu+jmlTambah>maxMenu){
                                        system("cls");
                                        cout<<"Jumlah menu tidak boleh melebihi "<<maxMenu<<"! ("<<jmlMenu<<"/"<<maxMenu<<")"<<endl;
                                        cout<<"Tambah menu dibatalkan!"<<endl<<endl;
                                        break;
                                    }else{
                                        if(jmlMenu==0){
                                            for(int i=1; i<=jmlTambah; i++){
                                                cout << "Masukan Nama Menu : ";
                                                getline(cin>>ws, namaMenu[i]);
                                                cout<<"Masukan Harga Menu : ";
                                                while(!(cin>>hargaMenu[i]) || hargaMenu[i]<0){
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                                    cout << "Harga tidak valid!" << endl;
                                                    cout << "Masukan Ulang Harga : ";
                                                }
                                                cout <<endl;
                                            }
                                        }else{
                                            for(int i=jmlMenu+1; i<=(jmlMenu+jmlTambah); i++){
                                                cout << "Masukan Nama Menu : ";
                                                getline(cin>>ws, namaMenu[i]);
                                                cout<<"Masukan Harga Menu : ";
                                                while(!(cin>>hargaMenu[i]) || hargaMenu[i]<0){
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                                    cout << "Harga tidak valid!" << endl;
                                                    cout << "Masukan Ulang Harga : ";
                                                }
                                                cout <<endl;
                                            }
                                        }
                                    }

                                    jmlMenu += jmlTambah;
                                    system("cls");
                                    if(jmlTambah==0){
                                        cout<<"Tambah menu dibatalkan!"<<endl;
                                    }else{
                                        cout<<"Berhasil menambahkan menu!"<<endl;
                                        cout << "Daftar Menu Makanan "<<endl;
                                        cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                        cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(10) << "Harga"<< endl;
                                        cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                        for(int i=1; i<=jmlMenu; i++){
                                            cout<<" "<<left<< setw(3) << i<<"| "<<left<< setw(30)<< namaMenu[i]<< "| Rp. "<<hargaMenu[i]<<endl;
                                        }
                                        cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    }
                                    cout <<endl;
                                }
                                // Akhir Fitur Tambah Menu Makanan

                                break;
                            case 2: //ubah
                                system("cls");
                                menuUbah:
                                cout << "Jumlah Menu : ("<<jmlMenu<<"/"<<maxMenu<<")"<< endl;
                                if(jmlMenu==0){
                                    system("cls");
                                    cout << "Daftar Menu Makanan"<<endl;
                                    cout<<"Menu masih kosong!"<<endl<<endl;
                                    goto menuPengelola;
                                }else{
                                    cout << "Daftar Menu Makanan"<<endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(10) << "Harga"<< endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    for(int i=1; i<=jmlMenu; i++){
                                        cout<<" "<<left<< setw(3) << i<<"| "<<left<< setw(30)<< namaMenu[i]<< "| Rp. "<<hargaMenu[i]<<endl;
                                    }
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    cout<<endl;
                                    cout<<"Pilih nomor menu yang akan diubah"<<endl;
                                    cout<<"Pilih 0 untuk kembali"<<endl;
                                    cout<<"Pilihan : ";
                                    while(!(cin>>pilUbah)){
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout <<endl<< "Pilihan tidak valid!" << endl <<endl;
                                        cout<<"Pilih Ulang Menu"<<endl;
                                        cout <<"Pilihan : ";
                                    }
                                    cout<<endl;
                                    if(pilUbah==0){
                                        system("cls");
                                        cout<<"Ubah menu dibatalkan!"<<endl<<endl;
                                        goto menuPengelola;
                                    }else if(pilUbah>jmlMenu || pilUbah<0){
                                        system("cls");
                                        cout<<"Menu tidak ditemukan!"<<endl<<endl;
                                        goto menuUbah;
                                    }else{
                                        int i;
                                        for(i=1; i<=jmlMenu; i++){
                                            if(pilUbah == i){
                                                break;
                                            }
                                        }
                                        cout<<"Masukan Nama Baru : ";
                                        getline(cin>>ws, namaMenu[i]);
                                        cout<<"Masukan Harga Baru : ";
                                        while(!(cin>>hargaMenu[i]) || hargaMenu[i]<0){
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                            cout << "Harga tidak valid!" << endl;
                                            cout << "Masukan Ulang Harga : ";
                                        }
                                        system("cls");
                                        cout <<"Menu nomor "<<pilUbah<<" berhasil diubah!"<<endl<<endl;
                                        goto menuUbah;

                                    }
                                }

                                break;
                            case 3 : //hapus
                                system("cls");
                                menuHapus:
                                cout << "Jumlah Menu : ("<<jmlMenu<<"/"<<maxMenu<<")"<< endl;
                                if(jmlMenu==0){
                                    system("cls");
                                    cout << "Daftar Menu Makanan"<<endl;
                                    cout<<"Menu masih kosong!"<<endl<<endl;
                                goto menuPengelola;
                                }else{
                                    cout << "Daftar Menu Makanan"<<endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(10) << "Harga"<< endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    for(int i=1; i<=jmlMenu; i++){
                                        cout<<" "<<left<< setw(3) << i<<"| "<<left<< setw(30)<< namaMenu[i]<< "| Rp. "<<hargaMenu[i]<<endl;
                                    }
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    cout<<endl;
                                    cout<<"Pilih nomor menu yang akan dihapus"<<endl;
                                    cout<<"Pilih 0 untuk kembali"<<endl;
                                    cout<<"Pilihan : ";
                                    while(!(cin>>pilHapus)){
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout <<endl<< "Pilihan tidak valid!" << endl <<endl;
                                        cout<<"Pilih Ulang Menu"<<endl;
                                        cout <<"Pilihan : ";
                                    }
                                    if(pilHapus==0){
                                        system("cls");
                                        cout<<"Hapus menu dibatalkan!"<<endl<<endl;
                                        goto menuPengelola;
                                    }else if(pilHapus>jmlMenu || pilHapus<0){
                                        system("cls");
                                        cout<<"Menu tidak ditemukan!"<<endl<<endl;
                                        goto menuHapus;
                                    }else{
                                        int i;
                                        for(i=1; i<=jmlMenu; i++){
                                            if(pilHapus == i){
                                                break;
                                            }
                                        }

                                        if(i<=jmlMenu){
                                            for(int j=i; j<jmlMenu; j++){
                                                namaMenu[j]= namaMenu[j+1];
                                                hargaMenu[j]= hargaMenu[j+1];
                                            }
                                            jmlMenu--;
                                        }
                                    }
                                }
                                system("cls");
                                cout << "Berhasil menghapus data!"<<endl<<endl;
                                goto menuHapus;
                                break;
                            case 4 : // tampilkan
                                system("cls");
                                menuTampilkan:
                                cout << "Jumlah Menu : ("<<jmlMenu<<"/"<<maxMenu<<")"<< endl;

                                if(jmlMenu==0){
                                    cout<<"Menu masih kosong!"<<endl;
                                }else{
                                    cout << "Daftar Menu Makanan "<<endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(10) << "Harga"<< endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    for(int i=1; i<=jmlMenu; i++){
                                        cout<<" "<<left<< setw(3) << i<<"| "<<left<< setw(30)<< namaMenu[i]<< "| Rp. "<<hargaMenu[i]<<endl;
                                    }
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                }
                                cout <<endl;
                                break;
                            case 5:// Laporan /riwayat pembelian
                                system("cls");
                                menuLaporan:
                                totalKeuntungan=0;
                                    if(jmlLap==0){
                                        system("cls");
                                        cout<<"Laporan masih Kosong!"<<endl<<endl;
                                        break;
                                    }else{
                                        for(int i=0; i<jmlLap;i++){
                                            totalKeuntungan+=(lapHarga[i]*lapTotal[i]);
                                        }
                                        cout<<setw(16)<<""<<"- Laporan Pembelian -"<<endl;
                                        cout << setfill('=') << setw(60) << "" << setfill(' ') << endl;
                                        cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(12) << "Harga"<<"| "<< left << setw(10) << "Jumlah "<< endl;
                                        cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
                                        for(int i=0;i<jmlLap;i++){
                                            cout<<" "<<left<< setw(3) << i+1<<"| "<<left<< setw(30)<< lapNama[i]<< "| Rp. "<<setw(8)<< lapHarga[i]<<"| "<<left<<setw(10)<<lapTotal[i]<<endl;
                                        }
                                        cout << setfill('=') << setw(60) << "" << setfill(' ') << endl;
                                        cout <<" Total Keuntungan :"<<right<<setw(36)<<"Rp. "<< totalKeuntungan<<endl;
                                        cout << setfill('=') << setw(60) << "" << setfill(' ') << endl;
                                    }
                                    cout<<endl;

                                break;
                            case 6:
                                char logout;
                                cout <<"Yakin akan logout? (y/n)"<<endl;
                                cout <<"Jawaban : ";
                                if(!(cin>>logout)){
                                        cin.clear();
                                        cin.ignore(numeric_limits<char>::max(),'\n');
                                        system("cls");
                                        cout << "Jawaban Tidak Valid"<<endl;
                                        cout << "Logout dibatalkan!"<< endl<<endl;
                                        goto menuPengelola;
                                    }

                                cout <<endl;
                                switch(logout){
                                case 'y':
                                    system("cls");
                                    cout << "Berhasil logout!"<< endl<<endl;
                                    goto menuAwal;
                                    break;
                                case 'n':
                                    system("cls");
                                    cout << "Logout dibatalkan!"<< endl<<endl;
                                    goto menuPengelola;
                                    break;
                                default:
                                    system("cls");
                                    cout << "Jawaban Tidak Valid"<<endl;
                                    cout << "Logout dibatalkan!"<< endl<<endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<char>::max(),'\n');
                                    goto menuPengelola;
                                    break;
                                }
                            default :
                                system("cls");
                                cout<<"Pilihan Tidak Tersedia"<<endl<<endl;
                                break;
                        }
                    }while (pilPengelola !=6);

                    // Akhir Menu Pengelola
                    break;
                case 2:
                    // Awal Menu Pembelian

                    system("cls");
                    menuPembeli:
                    do{
                        cout<<setw(17)<<""<<"> Menu Makanan <"<<endl;
                        cout << setfill('=') << setw(50) << "" << setfill(' ') << endl;
                        cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(10) << "Harga"<< endl;
                        cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;

                        if(jmlMenu==0){

                            cout<<setw(16)<<""<<"Menu Masih Kosong!"<<setw(20)<<""<<endl;
                        }else{
                            for(int i=1; i<=jmlMenu; i++){
                                cout<<" "<<left<< setw(3) << i<<"| "<<left<< setw(30)<< namaMenu[i]<< "| Rp. "<<hargaMenu[i]<<endl;
                            }
                        }
                        cout << setfill('=') << setw(50) << "" << setfill(' ') << endl<<endl;

                        cout <<"1. Beli Makanan"<<endl;
                        cout <<"2. Kembali ke Menu Awal"<<endl;
                        cout <<"Pilihan :";
                        if(!(cin>>pilPembeli)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            system("cls");
                            cout<<"Pilihan tidak valid!"<<endl<<endl;
                            goto menuPembeli;
                        }

                        cout<<endl;
                        switch(pilPembeli){
                        case 1:
                            if(jmlMenu==0){
                                system("cls");
                                cout<<"Menu belum ditambahkan"<<endl;
                                cout<<"Tidak dapat melakukan pembelian!"<<endl<<endl;
                                break;
                            }else{
                                system("cls");
                                awalPesan:
                                do{
                                    cout<<setw(17)<<""<<"> Menu Makanan <"<<endl;
                                    cout << setfill('=') << setw(50) << "" << setfill(' ') << endl;
                                    cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(10) << "Harga"<< endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    if(jmlMenu==0){

                                        cout<<setw(16)<<""<<"Menu Masih Kosong!"<<setw(20)<<""<<endl;
                                    }else{
                                        for(int i=1; i<=jmlMenu; i++){
                                            cout<<" "<<left<< setw(3) << i<<"| "<<left<< setw(30)<< namaMenu[i]<< "| Rp. "<<hargaMenu[i]<<endl;
                                        }
                                    }
                                    cout << setfill('=') << setw(50) << "" << setfill(' ') << endl<<endl;

                                    cout<<setw(16)<<""<<"< Daftar Pesanan >"<<endl;
                                    if(menuPesanan==0){
                                        cout<<setw(15)<<""<<"Pesanan Masih Kosong!"<<setw(20)<<""<<endl;
                                    }else{
                                        totalHarga=0;
                                        for(int i=0; i<menuPesanan;i++){
                                            totalHarga+=(hargaPesanan[i]*jmlPesanan[i]);
                                        }
                                        cout << setfill('=') << setw(60) << "" << setfill(' ') << endl;
                                        cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(12) << "Harga"<<"| "<< left << setw(10) << "Jumlah "<< endl;
                                        cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
                                        for(int i=0;i<menuPesanan;i++){
                                            cout<<" "<<left<< setw(3) << i+1<<"| "<<left<< setw(30)<< namaPesanan[i]<< "| Rp. "<<setw(8)<< hargaPesanan[i]<<"| "<<left<<setw(10)<<jmlPesanan[i]<<endl;
                                        }
                                        cout << setfill('=') << setw(60) << "" << setfill(' ') << endl;
                                        cout <<" Total Harga :"<<right<<setw(36)<<"Rp. "<< totalHarga<<endl;
                                        cout << setfill('=') << setw(60) << "" << setfill(' ') << endl;
                                    }
                                    cout<<endl;
                                    cout<<"1. Tambah Pesanan"<<endl;
                                    cout<<"2. Batalkan Pesanan"<<endl;
                                    cout<<"3. Konfirmasi Pesanan"<<endl;
                                    cout<<"Pilihan : ";
                                    if(!(cin>>pilPesanan)){
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        system("cls");
                                        cout <<endl<< "Pilihan tidak valid!" << endl <<endl;
                                        goto awalPesan;
                                    }
                                    cout<<endl;

                                    switch(pilPesanan){
                                    case 1:// tambah pesanan
                                        cout<<"Pilih Nomor Menu Makanan"<<endl;
                                        cout<<"Pilih 0 untuk membatalkan"<<endl;
                                        cout<<"Pilihan : ";
                                        while(!(cin>>pilMakan) || pilMakan<0 || pilMakan>jmlMenu){
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cout<<"Menu Tidak Ditemukan"<<endl<<endl;
                                            cout<<"Pilih Ulang Nomor Menu Makanan"<<endl;
                                            cout<<"Pilih 0 untuk membatalkan"<<endl;
                                            cout<<"Pilihan : ";
                                        }
                                        if(pilMakan==0){
                                            system("cls");
                                            cout<<"Tambah Pesanan dibatalkan!"<<endl<<endl;
                                            goto awalPesan;
                                        }else{
                                            cout <<"Masukan Jumlah Pembelian"<<endl;
                                            cout << "Jumlah : ";
                                            while(!(cin>>jmlPembelian) || jmlPembelian < 0){
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                                cout << "Jumlah tidak valid!" << endl<<endl;
                                                cout << "Masukan Ulang Jumlah Pembelian" << endl;
                                                cout << "Jumlah : ";
                                            }
                                            // int jmlPesanan[maxMenu], namaPesanan[maxMenu], hargaPesanan[maxMenu], menuPesanan;
                                            if(menuPesanan==0){
                                                namaPesanan[menuPesanan]=namaMenu[pilMakan];
                                                hargaPesanan[menuPesanan]=hargaMenu[pilMakan];
                                                jmlPesanan[menuPesanan]=jmlPembelian;
                                                //totalHarga+=(hargaPesanan[pilMakan]*jmlPembelian);
                                                menuPesanan++;

                                            }else{
                                                int i;
                                                for( i=0;i<menuPesanan;i++){
                                                    if(namaPesanan[i]==namaMenu[pilMakan] && hargaPesanan[i]==hargaMenu[pilMakan]){
                                                        jmlPesanan[i]+=jmlPembelian;
                                                        //totalHarga+=(hargaPesanan[i]*jmlPembelian);
                                                        break;
                                                    }
                                                }
                                                if(i==menuPesanan){
                                                    namaPesanan[menuPesanan]=namaMenu[pilMakan];
                                                    hargaPesanan[menuPesanan]=hargaMenu[pilMakan];
                                                    jmlPesanan[menuPesanan]=jmlPembelian;
                                                    menuPesanan++;
                                                }
                                            }
                                            system("cls");
                                            cout<<"Berhasil menambahkan pesanan!"<<endl;
                                            cout <<endl;
                                            goto awalPesan;
                                        }

                                        break;
                                    case 2:// batalkan pesanan
                                        konfPembatalan:
                                        do{
                                        cout<<"Yakin ingin membatalkan pesanan? (y/n)"<<endl;
                                        cout<<"Jawaban : ";
                                        if(!(cin>>konfBatal)){
                                            cin.clear();
                                            cin.ignore(numeric_limits<char>::max(), '\n');
                                            cout<<"Jawaban tidak valid!"<<endl<<endl;
                                            cout<<"Konfirmasi Ulang"<<endl;
                                            break;
                                        }
                                        switch(konfBatal){
                                        case 'y':
                                            for(int i; i<=menuPesanan;i++){
                                                namaPesanan[i]="";
                                                hargaPesanan[i]=NULL;
                                                jmlPesanan[i]=NULL;
                                            }
                                            menuPesanan=0;

                                            system("cls");
                                            cout<<"Pesanan Dibatalkan!"<<endl<<endl;
                                            goto menuPembeli;
                                            break;
                                        case 'n':
                                            system("cls");
                                            cout<<"Pembatalan Dibatalkan!"<<endl<<endl;
                                            goto awalPesan;
                                            break;
                                        default:
                                            cout<<"Jawaban tidak valid!"<<endl<<endl;
                                            cout<<"Konfirmasi Ulang"<<endl;
                                            break;
                                        }

                                        }while(konfBatal!='y' || konfBatal!='n');


                                        break;
                                    case 3:// konfirmasi pesanan
                                        konfPembelian :
                                        if(menuPesanan==0){
                                            system("cls");
                                            cout<<"Belum menambahkan pesanan!"<<endl<<endl;
                                            break;
                                        }
                                        do{

                                            cout <<"konfirmasi pembelian? (y/n)"<<endl;
                                            cout <<"Jawaban : ";
                                            if(!(cin>>konf)){
                                                cin.clear();
                                                cin.ignore(numeric_limits<char>::max(), '\n');
                                                cout<<"Jawaban tidak valid!"<<endl<<endl;
                                                cout<<"Konfirmasi Ulang"<<endl;
                                                break;
                                            }

                                            switch(konf){
                                                case 'y':

                                                    if (jmlLap==0){
                                                        for(int i=0; i<menuPesanan;i++){
                                                            lapNama[i]=namaPesanan[i];
                                                            lapHarga[i]=hargaPesanan[i];
                                                            lapTotal[i]=jmlPesanan[i];
                                                            jmlLap++;
                                                        }
                                                    }else{
                                                        int i;
                                                        int j;
                                                        for( i=0;i<menuPesanan;i++){
                                                                for(j=0;j<jmlLap;j++){
                                                                    if(namaPesanan[i]==lapNama[j] && hargaPesanan[i]==lapHarga[j]){
                                                                        lapTotal[j]+=jmlPesanan[i];
                                                                        break;
                                                                    }
                                                                }
                                                            if(j<jmlLap){
                                                                continue;
                                                            }
                                                            //cout<<"sebelum if i"<<i<<" j"<<j<<" jl"<<jmlLap<<endl;
                                                            if(j==jmlLap){
                                                                lapNama[jmlLap]=namaPesanan[i];
                                                                lapHarga[jmlLap]=hargaPesanan[i];
                                                                lapTotal[jmlLap]=jmlPesanan[i];
                                                                jmlLap++;
                                                            }
                                                        }
                                                    }
                                                    for(int i; i<=menuPesanan;i++){
                                                        namaPesanan[i]="";
                                                        hargaPesanan[i]=NULL;
                                                        jmlPesanan[i]=NULL;
                                                    }
                                                    menuPesanan=0;
                                                    system("cls");
                                                    cout <<"Pembelian berhasil!"<<endl<<endl;
                                                    goto menuPembeli;
                                                    break;

                                                case 'n':
                                                    system("cls");
                                                    cout <<"Konfirmasi dibatalkan!"<<endl<<endl;
                                                    goto awalPesan;
                                                    break;
                                                default:
                                                    cout<<"Jawaban tidak valid!"<<endl<<endl;
                                                    cout<<"Konfirmasi Ulang"<<endl;
                                                    break;
                                            }
                                        }while(konf!='y'||konf!='n');

                                        //cout <<"Total harga : Rp. "<<hargaMenu[pilMakan]*jmlPembelian<<endl;
                                        break;
                                    default:
                                        system("cls");
                                        cout<<"Pilihan tidak valid!"<<endl<<endl;
                                        break;
                                    }
                                }while(konf!='y');
                            }
                            break;
                        case 2:
                            system("cls");
                            cout<<"Kembali ke Menu Awal"<<endl<<endl;
                            break;
                        default:
                            system("cls");
                            cout<<"Pilihan tidak valid!"<<endl<<endl;
                        break;
                        }
                    }while(pilPembeli!=2);

                    break;
                    // Akhir Menu Pembelian

                case 3:
                    cout << "!! Menghentikan aplikasi akan menghapus semua data !!" <<endl;

                    cout<<"Aplikasi Dihentikan"<<endl;
                    exit(1);
                default:
                    system("cls");
                    cout<<"Pilihan tidak tersedia!"<<endl<<endl;
                    break;
            }
           }while (pilihan !=3);
            // END MENU AWAL
         return 0;
        }

