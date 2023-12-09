#include <iostream>
#include <conio.h>
#include <limits>
#include <vector>

using namespace std;
    int main(){
        int pilihan, admin;

        string username="kelompok4", password="pemesananmenu", menu, inputUsername, inputPassword;
        int loginCounter=0;

        int pilPengelola ;
        string namaMenu[50];
        int jmlTambah, hargaMenu[50], jmlMenu=0;

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
                                cout << "Jumlah : ";
                                while(!(cin>>jmlTambah)){
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    cout << "Jumlah tidak valid" << endl;
                                }

                                cout <<endl;

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

                                jmlMenu += jmlTambah;
                                system("cls");
                                cout<<"Berhasil menambahkan menu!"<<endl;
                                cout << "== Daftar Menu Makanan =="<<endl;
                                for(int i=1; i<=jmlMenu; i++){
                                    cout << i<<". "<< namaMenu[i]<< " (Rp. "<<hargaMenu[i]<<")"<<endl;
                                }
                                cout <<endl;

                                break;
                            case 2: //ubah
                                break;
                            case 3 : //hapus
                                break;
                            case 4 : // tampilkan
                                system("cls");
                                cout << "== Daftar Menu Makanan =="<<endl;
                                for(int i=1; i<=jmlMenu; i++){
                                    cout << i<<". "<< namaMenu[i]<< " (Rp. "<<hargaMenu[i]<<")"<<endl;
                                }
                                cout <<endl;
                                break;
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

           }while (pilihan !=4);

         return 0;
        }
