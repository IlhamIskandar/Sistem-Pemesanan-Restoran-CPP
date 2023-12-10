#include <iostream>
#include <conio.h>
#include <limits>
#include <vector>

using namespace std;
    int main(){
        int pilihan, admin;

        // Login pengelola
        string username="1", password="1", menu, inputUsername, inputPassword;
        int loginCounter=0;

        // Menu Pengelola
        int pilPengelola ;
        string namaMenu[50];
        int jmlTambah, hargaMenu[50], jmlMenu=0, pilHapus;

        menuAwal:
        do{
            cout<<"=======Pilih Pengguna=======\n";
            cout<<"1.Pengelola"<<endl;
            cout<<"2.Pembeli"<<endl;
            cout<<"3.Exit"<<endl;
            cout<<"Masukan Pilihan : ";
            while(!(cin>>pilihan)){
                cin.clear();// buat ngeclear error, kalo ada error, erornya gak dianggap
                cin.ignore(numeric_limits<streamsize>::max(),'\n');//buat nge ignore/skip baris inputan
                cout << "Pilihan tidak valid" << endl;
                goto menuAwal;
            }
            cout <<endl;

            switch (pilihan){
                case 1:
                    do{
                    cout<<"Silahkan Login Terlebih Dahulu!"<<endl;
                    cout<<"Username :";
                    cin>>inputUsername;
                    cout<<"Password :";
                    cin>>inputPassword;
                    cout << endl;

                    if (username!=inputUsername || password!=inputPassword){
                        cout<<"Username atau Password Salah! ["<<loginCounter+1<<"/3]"<<endl<<endl;
                        loginCounter++;
                        if(loginCounter==3){
                            cout << "Kembali ke Menu Awal"<<endl<<endl;
                            goto menuAwal;
                        }
                    }else {
                        system("cls");
                        cout<<"Berhasil Login!"<<endl << endl;
                    }

                    }while (username!=inputUsername || password!=inputPassword);
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
                                cout << "Masukan jumlah menu yang akan ditambahkan"<<endl;
                                cout << "Masukan 0 untuk membatalkan"<<endl;
                                cout << "Jumlah : ";
                                while(!(cin>>jmlTambah)){
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    system("cls");
                                    cout << "Jumlah tidak valid" << endl;
                                    cout << "Tambah menu dibatalkan!" << endl <<endl;
                                    goto menuPengelola;
                                }

                                cout <<endl;

                                if(jmlMenu==0){
                                    for(int i=1; i<=jmlTambah; i++){
                                        cout << "Masukan Nama Menu : ";
                                        getline(cin>>ws, namaMenu[i]);
                                        cout<<"Masukan Harga Menu : ";
                                        while(!(cin>>hargaMenu[i])){
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
                                        while(!(cin>>hargaMenu[i])){
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
                                    cout << "== Daftar Menu Makanan =="<<endl;
                                    for(int i=1; i<=jmlMenu; i++){
                                        cout << i<<". "<< namaMenu[i]<< " (Rp. "<<hargaMenu[i]<<")"<<endl;
                                    }
                                }
                                cout <<endl;

                                break;
                            case 2: //ubah
                                break;
                            case 3 : //hapus
                                menuHapus:
                                if(jmlMenu==0){
                                    system("cls");
                                    cout << "== Daftar Menu Makanan =="<<endl;
                                    cout<<"Menu masih kosong!"<<endl<<endl;
                                goto menuPengelola;
                                }else{
                                    cout << "== Daftar Menu Makanan =="<<endl;
                                    for(int i=1; i<=jmlMenu; i++){
                                        cout << i<<". "<< namaMenu[i]<< " (Rp. "<<hargaMenu[i]<<")"<<endl;
                                    }
                                    cout<<"Pilih menu yang akan dihapus"<<endl;
                                    cout<<"Pilihan : ";
                                    if(!(cin>>pilHapus)){
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        system("cls");
                                        cout <<endl<< "Pilihan tidak valid!" << endl <<endl;
                                        goto menuHapus;
                                    }else if(pilHapus==0){

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

                                break;
                            case 4 : // tampilkan
                                system("cls");
                                cout << "== Daftar Menu Makanan =="<<endl;
                                if(jmlMenu==0){
                                    cout<<"Menu masih kosong!"<<endl;
                                }else{
                                    cout << "Jumlah Menu : " << jmlMenu << endl;
                                    for(int i=1; i<=jmlMenu; i++){
                                        cout << i<<". "<< namaMenu[i]<< " (Rp. "<<hargaMenu[i]<<")"<<endl;
                                    }
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
                                cout<<"Pilihan Tidak Tersedia"<<endl;
                                break;
                        }
                    }while (pilPengelola !=5);

                    break;
                case 2:
                    cout<<"Silahkan Pilih Menu"<<endl;
                    break;

                case 3:
                    cout << "!! Menghentikan aplikasi akan menghapus semua data !!" <<endl;

                    cout<<"Aplikasi Dihentikan"<<endl;
                    exit(1);
                default:
                    cout<<"Pilihan Tidak Tersedia"<<endl;
                    break;
            }
           }while (pilihan !=3);

         return 0;
        }

