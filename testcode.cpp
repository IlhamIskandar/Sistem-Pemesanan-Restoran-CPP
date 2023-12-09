#include <iostream>
#include <conio.h>
#include <limits>

using namespace std;
//std::vector<int> array;
// initialize array...

// delete element at index 2
//array.erase(array.begin() + 2);
int main(){
int pilihan, admin;

        string username="kelompok4", password="pemesananmenu", menu, inputUsername, inputPassword;
        int loginCounter=0;

        int pilPengelola ;
        string namaMenu[50];
        int jmlTambah, hargaMenu[50], jmlMenu=0;


        jmlMenu += jmlTambah;
                                for(int i=1; i<=jmlTambah; i++){
                                    cout << "Masukan Nama Menu : ";
                                    getline(cin>>ws, namaMenu[i]);
                                    cout<<"Masukan Harga Menu : ";
                                    while(!(cin>>hargaMenu[i])){
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout << "Harga tidak valid" << endl;
                                    }
                                }
}

