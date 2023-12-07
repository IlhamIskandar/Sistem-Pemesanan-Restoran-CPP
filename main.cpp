#include <iostream>
#include <conio.h>
using namespace std;
    int main(){
        int pilihan, admin;
        string username="kelompok4", password="pemesananmenu", menu, inputUsername, inputPassword;
        int loginCounter=0;
        string namaMakanan[20];
        int hargaMakanan[20];
        int menuPengelola;

        menuAwal:
        do{
            cout<<"=======Pilih Pengguna=======\n";
            cout<<"1.Pengelola"<<endl;
            cout<<"2.Pembeli"<<endl;
            cout<<"3.Exit"<<endl;
            cin>>pilihan;

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
                        cout<<"Berhasil Login"<<endl;
                    }
                    }while (username!=inputUsername || password!=inputPassword);

                    do{
                        cout<<"=======Menu Pengelola========="<<endl;
                        cout<<"1.Tambah Menu"<<endl;
                        cout<<"2.Cari dan  Ubah Menu"<<endl;
                        cout<<"3.Hapus Menu"<<endl;
                        cout<<"Log Out"<<endl;
                        cin>>menuPengelola;
                    }while (menuPengelola !=4);

                    break;
                case 2:
                    cout<<"Silahkan Pilih Menu"<<endl;
                    break;

                case 3:
                    cout<<"Aplikasi Dihentikan"<<endl;
                    exit(1);

                default:
                    cout<<"Pilihan Tidak Tersedia"<<endl;
                    break;
            }

           }while (pilihan !=4);
           getch();

         return 0;
        }
