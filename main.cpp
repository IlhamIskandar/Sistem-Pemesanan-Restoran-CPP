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
        int jmlTambah,  jmlMenu=0, pilHapus, pilUbah;

        // variable data menu makanan
        string namaMenu[50];
        int hargaMenu[50];

        //variable menu pembelian
        int pilPembeli, pilMakan, jmlPembelian;
        char konf;

        menuAwal:
        do{
            cout<<"=======Pilih Pengguna=======\n";
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
                        cout<<"=======Menu Pengelola========="<<endl;
                        cout<<"1.Tambah Menu Makanan"<<endl;
                        cout<<"2.Ubah Nama/Harga Menu Makanan"<<endl;
                        cout<<"3.Hapus Menu Makanan"<<endl;
                        cout<<"4.Tampilkan Menu Makanan"<<endl;
                        cout<<"5.Log Out"<<endl;
                        cout<<"Masukan Pilihan : ";
                        while(!(cin>>pilPengelola)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout <<endl<< "Pilihan tidak valid!" << endl <<endl;
                            goto menuPengelola;
                        }

                        cout<<endl;
                        switch(pilPengelola){
                            case 1:
                                // Awal Fitur Tambah Menu Makanan
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
                                // Akhir Fitur Tambah Menu Makanan

                                break;
                            case 2: //ubah
                                system("cls");
                                menuUbah:
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
                                        cout<<"| "<<left<< setw(3) << i<<"| "<<left<< setw(30)<< namaMenu[i]<< "| Rp. "<<hargaMenu[i]<<endl;
                                    }
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    cout<<endl;
                                    cout<<"Pilih menu yang akan diubah"<<endl;
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
                                        while(!(cin>>hargaMenu[i])){
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
                                    cout<<"Pilih menu yang akan dihapus"<<endl;
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
                                            for(int j=i; j<=jmlMenu; j++){
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
                                cout << "Jumlah Menu : " << jmlMenu << endl;

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
                            case 5:
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
                    }while (pilPengelola !=5);

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
                                cout<<"Menu Masih Kosong!"<<endl<<endl;
                                break;
                            }else{
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
                                    cout<<"Pembelian dibatalkan!"<<endl<<endl;
                                    goto menuPembeli;
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

                                    cout <<endl;

                                    konfPembelian:

                                    cout <<"Beli "<<namaMenu[pilMakan]<< " sebanyak "<< jmlPembelian<<" buah"<<endl;
                                    cout <<"Total harga : Rp. "<<hargaMenu[pilMakan]*jmlPembelian<<endl;
                                    cout <<"konfirmasi pembelian? (y/n)"<<endl;
                                    cout <<"Jawaban : ";
                                    if(!(cin>>konf)){
                                        cin.clear();
                                        cin.ignore(numeric_limits<char>::max(), '\n');
                                        cout<<"Jawaban tidak valid!"<<endl<<endl;
                                        cout<<"Konfirmasi Ulang"<<endl;
                                        goto konfPembelian;
                                    }

                                    switch(konf){
                                        case 'y':
        //                                       pembelianMenu[pilMenu] += jmlPembelian;
                                            system("cls");
                                            cout << "Pembelian "<<namaMenu[pilMakan]<< " sebanyak "<< jmlPembelian<<" dengan harga Rp. "<<hargaMenu[pilMakan]*jmlPembelian<< " Berhasil!"<<endl<<endl;
                                            break;
                                        case 'n':
                                            system("cls");
                                            cout <<"Pembelian dibatalkan!"<<endl<<endl;
                                            break;
                                        default:
                                            cout<<"Jawaban tidak valid!"<<endl<<endl;
                                            cout<<"Konfirmasi Ulang"<<endl;
                                            goto konfPembelian;
                                            break;
                                    }
                                }
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

