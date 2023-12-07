#include <iostream>
#include <conio.h>
#include<limits>

using namespace std;
    int main(){
        int pilihan, admin;

        string username="kelompok4", password="pemesananmenu", menu, inputUsername, inputPassword;
        int loginCounter=0;

        int pilPengelola ;
        string namaMakanan[20];
        int jmlTambah, hargaMakanan[20];

        menuAwal:
        do{
            cout<<"=======Pilih Pengguna=======\n";
            cout<<"1.Pengelola"<<endl;
            cout<<"2.Pembeli"<<endl;
            cout<<"3.Exit"<<endl;
            cout<<"Masukan Pilihan : ";
            while(!(cin>>pilihan)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Pilihan tidak valid" << endl;
                goto menuAwal;
            }
//            cin>>pilihan;

            switch (pilihan){
                case 1:
                    do{
                    cout<<"Silahkan Login Terlebih Dahulu"<<endl;
                    cout<<"Username :";
                    cin>>inputUsername;
                    cout<<"Password :";
                    cin>>inputPassword;
                    cout << endl;

                    if (username!=inputUsername || password!=inputPassword){
                        cout<<"Username atau Password Salah!"<<endl<<endl;
                        loginCounter++;
                        if(loginCounter==3){
                            goto menuAwal;
                        }
                    }else {
                        system("cls");
                        cout<<"Berhasil Login"<<endl << endl;
                    }
                    }while (username!=inputUsername || password!=inputPassword);

                    menuPengelola:
                    do{
                        cout<<"=======Menu Pengelola========="<<endl;
                        cout<<"1.Tambah Menu Makanan"<<endl;
                        cout<<"2.Cari dan  Ubah Menu Makanan"<<endl;
                        cout<<"3.Hapus Menu Makanan"<<endl;
                        cout<<"4.Log Out"<<endl;
                        cout<<"Masukan Pilihan : ";
                        while(!(cin>>pilPengelola)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "Pilihan tidak valid" << endl;
                            goto menuPengelola;
                        }

                        switch(pilPengelola){
                            case 1:
                                cout << "Masukan jumlah menu yang akan ditambahkan"<<endl;
                                cout << "Jumlah : ";
                                while(!(cin>>jmlTambah)){
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    cout << "Jumlah tidak valid" << endl;
                                }

                                for(int i=0; i<jmlTambah; i++){
                                    cout << "Masukan Nama Makanan : ";
                                    cin >> namaMakanan[i];
                                    cout << namaMakanan[i];
                                }
                                break;

                        }
                    }while (pilPengelola !=4);

                    break;
                case 2:
                    cout<<"Silahkan Pilih Menu"<<endl;
                    break;

                case 3:
                    cout << "!! Menghentikan aplikasi akan menghapus semua data !!";

                    cout<<"Aplikasi Dihentikan"<<endl;
                    exit(1);

                default:
                    cout<<"Pilihan Tidak Tersedia"<<endl;
                    break;
            }

           }while (pilihan !=4);

         return 0;
        }
