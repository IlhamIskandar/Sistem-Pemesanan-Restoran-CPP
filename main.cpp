#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>

using namespace std;
    int main(){
        int pilihan, admin;
        string konfirmasiExit;

        // variable Login pengelola
        string username="kelompok4", password="pemesananmakanan", menu, inputUsername, inputPassword;
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
            switch (pilihan){ // switch pemilihan pada menu awal
                case 1: // pilihan 1, masuke ke login pengelola
                    // Input Login Pengelola
                    system("cls");
                    do{ // perulangan login, berulang ketika username dan password tdk sesuai
                        // reset input username dan password ketika login
                        inputUsername="";
                        inputPassword="";
                        cout<<"Silahkan Login Sebagai Pengelola!"<<endl;
                        cout<<"Username :";
                        getline(cin>>ws, inputUsername); // input username, getline & ws untuk membaca spasi dan lebih dari 1 kata
                        cout<<"Password :";
                        getline(cin>>ws, inputPassword);
                        cout << endl;

                        // kondisi ketika password atau username tidak sesuai
                        if (username!=inputUsername || password!=inputPassword){
                            cout<<"Username atau Password Salah! ["<<loginCounter+1<<"/3]"<<endl<<endl;
                            // ketika login tidak sesuai, akan menambah login counter, ketika salah 3 kali, program kembali ke menu awal
                            loginCounter++;
                            if(loginCounter==3){
                                system("cls");
                                cout<<"Login gagal!"<<endl;
                                cout << "Kembali ke Menu Awal"<<endl<<endl;
                                loginCounter=0;
                                goto menuAwal;
                            }

                        }else { // kondisi ketika login berhasil, ke
                            system("cls");
                            loginCounter=0;
                            cout<<"Login Berhasil!"<<endl << endl;
                        }
                    }while (username!=inputUsername || password!=inputPassword);
                    // Akhir Login Pengelola

                    // Awal Menu Pengelola
                    menuPengelola:
                    do{ // perulangan menu pengelola, berhenti ketika logout dikonfirmasi
                        cout<<"======= Menu Pengelola ========="<<endl;
                        cout<<"1.Tambah Menu Makanan (Maks."<<maxMenu<<", ["<<jmlMenu<<"/"<<maxMenu<<"])"<<endl;
                        cout<<"2.Ubah Nama/Harga Menu Makanan"<<endl;
                        cout<<"3.Hapus Menu Makanan"<<endl;
                        cout<<"4.Tampilkan Menu Makanan"<<endl;
                        cout<<"5.Tampilkan Laporan Pembelian"<<endl;
                        cout<<"6.Log Out"<<endl;
                        cout<<"Masukan Pilihan : ";
                        while(!(cin>>pilPengelola)){ // input & handling pilihan fitur menu pengelola
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            system("cls");
                            cout <<"Pilihan tidak valid!" << endl <<endl;
                            goto menuPengelola;
                        }

                        cout<<endl;
                        switch(pilPengelola){// switch pilihan fitur pengelolaan
                            case 1: //pilihan 1 tambah menu makanan
                                // Awal Fitur Tambah Menu Makanan
                                if (jmlMenu==maxMenu){ // kondisi ketika jumlah menu mencapai jumlah maksimal
                                    system("cls");
                                    cout <<"Jumlah Menu Sudah Maksimal ("<<jmlMenu<<"/"<<maxMenu<<")"<<endl;
                                    cout <<"Tidak Dapat Menambah Menu Lain!"<<endl<<endl;
                                    break;
                                }else{
                                    cout << "Masukan jumlah menu yang akan ditambahkan"<<endl;
                                    cout << "Masukan 0 untuk membatalkan"<<endl;
                                    cout << "Jumlah : ";
                                    while(!(cin>>jmlTambah) || jmlTambah < 0){ // input & handling jumlah menu yang ditambahkan
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        system("cls");
                                        cout << "Jumlah tidak valid!" << endl;
                                        cout << "Tambah menu dibatalkan!" << endl <<endl;
                                        goto menuPengelola;
                                    }
                                    cout <<endl;
                                    // kondisi ketika jumlah menu yang ditambahkan melebihi jumlah maksimal menu
                                    if(jmlMenu+jmlTambah>maxMenu){ //
                                        system("cls");
                                        cout<<"Jumlah menu tidak boleh melebihi "<<maxMenu<<"! ("<<jmlMenu<<"/"<<maxMenu<<")"<<endl;
                                        cout<<"Tambah menu dibatalkan!"<<endl<<endl;
                                        break;
                                    }else{
                                        // kondisi untuk cek jumlah menu
                                        if(jmlMenu==0){
                                            // perulangan input nama & harga menu sesuai jumlah yang akan ditambahkan
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
                                            // perulangan input nama & harga menu sesuai jumlah yang akan ditambahkan
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
                                if(jmlMenu==0){ // kondisi untuk cek jumlah daftar menu
                                    system("cls");
                                    cout << "Daftar Menu Makanan"<<endl;
                                    cout<<"Menu masih kosong!"<<endl<<endl;
                                    goto menuPengelola;
                                }else{
                                    cout << "Daftar Menu Makanan"<<endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(10) << "Harga"<< endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    for(int i=1; i<=jmlMenu; i++){ // perulangan untuk menampilkan menu makanan
                                        cout<<" "<<left<< setw(3) << i<<"| "<<left<< setw(30)<< namaMenu[i]<< "| Rp. "<<hargaMenu[i]<<endl;
                                    }
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    cout<<endl;
                                    cout<<"Pilih nomor menu yang akan diubah"<<endl;
                                    cout<<"Pilih 0 untuk kembali"<<endl;
                                    cout<<"Pilihan : ";
                                    while(!(cin>>pilUbah)){ //Input & handling pilih menu
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout <<endl<< "Pilihan tidak valid!" << endl <<endl;
                                        cout<<"Pilih Ulang Menu"<<endl;
                                        cout <<"Pilihan : ";
                                    }
                                    cout<<endl;
                                    // cek input pilihan menu
                                    if(pilUbah==0){ // pilihan 0, batalkan
                                        system("cls");
                                        cout<<"Ubah menu dibatalkan!"<<endl<<endl;
                                        goto menuPengelola;
                                    }else if(pilUbah>jmlMenu || pilUbah<0){ // kondisi pilihan>jumlah menu, pilihan<0
                                        system("cls");
                                        cout<<"Menu tidak ditemukan!"<<endl<<endl;
                                        goto menuUbah;
                                    }else{
                                        int i;
                                        // perulangan untuk mencari daftar menu yang dicari
                                        for(i=1; i<=jmlMenu; i++){
                                            if(pilUbah == i){
                                                break;
                                            }
                                        }
                                        // input nama & harga menu yang baru
                                        cout<<"Masukan Nama Baru : ";
                                        getline(cin>>ws, namaMenu[i]);
                                        cout<<"Masukan Harga Baru : ";
                                        while(!(cin>>hargaMenu[i]) || hargaMenu[i]<0){ // input
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
                                if(jmlMenu==0){ // cek jumlah daftar menu
                                    system("cls");
                                    cout << "Daftar Menu Makanan"<<endl;
                                    cout<<"Menu masih kosong!"<<endl<<endl;
                                    goto menuPengelola;
                                }else{
                                    cout << "Daftar Menu Makanan"<<endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(10) << "Harga"<< endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    for(int i=1; i<=jmlMenu; i++){ // perulangan untuk menampilkan daftar menu makanan
                                        cout<<" "<<left<< setw(3) << i<<"| "<<left<< setw(30)<< namaMenu[i]<< "| Rp. "<<hargaMenu[i]<<endl;
                                    }
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    cout<<endl;
                                    cout<<"Pilih nomor menu yang akan dihapus"<<endl;
                                    cout<<"Pilih 0 untuk kembali"<<endl;
                                    cout<<"Pilihan : ";
                                    while(!(cin>>pilHapus)){ // input & handling pilih menu
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout <<endl<< "Pilihan tidak valid!" << endl <<endl;
                                        cout<<"Pilih Ulang Menu"<<endl;
                                        cout <<"Pilihan : ";
                                    }
                                    // cek input pilihan
                                    if(pilHapus==0){
                                        system("cls");
                                        cout<<"Hapus menu dibatalkan!"<<endl<<endl;
                                        goto menuPengelola;
                                    }else if(pilHapus>jmlMenu || pilHapus<0){ //pilihan> jumlah menu atau pilihan<0
                                        system("cls");
                                        cout<<"Menu tidak ditemukan!"<<endl<<endl;
                                        goto menuHapus;
                                    }else{
                                        int i;
                                        //perulangan untuk mencari menu yang dipilih
                                        for(i=1; i<=jmlMenu; i++){
                                            if(pilHapus == i){
                                                break;
                                            }
                                        }
                                        // menimpa menu yang dipilih (ke-i), dengan menu selanjutnya
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
                            case 4 : // tampilkan menu makanan
                                system("cls");
                                menuTampilkan:
                                cout << "Jumlah Menu : ("<<jmlMenu<<"/"<<maxMenu<<")"<< endl;
                                // cek jumlah menu makanan
                                if(jmlMenu==0){
                                    cout<<"Menu masih kosong!"<<endl;
                                }else{
                                    cout << "Daftar Menu Makanan "<<endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(10) << "Harga"<< endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    for(int i=1; i<=jmlMenu; i++){ //perulangan untuk menampilkan menu makanan
                                        cout<<" "<<left<< setw(3) << i<<"| "<<left<< setw(30)<< namaMenu[i]<< "| Rp. "<<hargaMenu[i]<<endl;
                                    }
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                }
                                cout <<endl;
                                break;
                            case 5:// Laporan/riwayat pembelian
                                system("cls");
                                menuLaporan:
                                totalKeuntungan=0;
                                    if(jmlLap==0){ //cek jumlah laporan
                                        system("cls");
                                        cout<<"Laporan masih Kosong!"<<endl<<endl;
                                        break;
                                    }else{
                                        for(int i=0; i<jmlLap;i++){ // Perulangan untuk menghitung jumlah keuntungan
                                            totalKeuntungan+=(lapHarga[i]*lapTotal[i]);
                                        }
                                        cout<<setw(16)<<""<<"- Laporan Pembelian -"<<endl;
                                        cout << setfill('=') << setw(60) << "" << setfill(' ') << endl;
                                        cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(12) << "Harga"<<"| "<< left << setw(10) << "Jumlah "<< endl;
                                        cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
                                        for(int i=0;i<jmlLap;i++){ // perulangan untuk menampilkan data pembelian
                                            cout<<" "<<left<< setw(3) << i+1<<"| "<<left<< setw(30)<< lapNama[i]<< "| Rp. "<<setw(8)<< lapHarga[i]<<"| "<<left<<setw(10)<<lapTotal[i]<<endl;
                                        }
                                        cout << setfill('=') << setw(60) << "" << setfill(' ') << endl;
                                        cout <<" Total Pemasukan :"<<right<<setw(36)<<"Rp. "<< totalKeuntungan<<endl;
                                        cout << setfill('=') << setw(60) << "" << setfill(' ') << endl;
                                    }
                                    cout<<endl;

                                break;
                            case 6: // logout
                                char logout;
                                cout <<"Yakin akan logout? (y/n)"<<endl;
                                cout <<"Jawaban : ";
                                if(!(cin>>logout)){ // input & handling konfirmasi logout
                                        cin.clear();
                                        cin.ignore(numeric_limits<char>::max(),'\n');
                                        system("cls");
                                        cout << "Jawaban Tidak Valid"<<endl;
                                        cout << "Logout dibatalkan!"<< endl<<endl;
                                        goto menuPengelola;
                                    }

                                cout <<endl;
                                switch(logout){ // switch untuk cek input logout
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
                case 2: // pilihan 2 menu awal. pembelian
                    // Awal Menu Pembelian

                    system("cls");
                    menuPembeli:
                    do{ // perulangan menu pembelian
                        cout<<setw(17)<<""<<"> Menu Makanan <"<<endl;
                        cout << setfill('=') << setw(50) << "" << setfill(' ') << endl;
                        cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(10) << "Harga"<< endl;
                        cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;

                        if(jmlMenu==0){ // cek jumlah menu makanan

                        cout<<setw(16)<<""<<"Menu Masih Kosong!"<<setw(20)<<""<<endl;
                        }else{
                            for(int i=1; i<=jmlMenu; i++){ // perulangan utnuk menampilkan menu makanan
                                cout<<" "<<left<< setw(3) << i<<"| "<<left<< setw(30)<< namaMenu[i]<< "| Rp. "<<hargaMenu[i]<<endl;
                            }
                        }
                        cout << setfill('=') << setw(50) << "" << setfill(' ') << endl<<endl;
                        cout <<"Pilih Aksi"<<endl;
                        cout <<"1. Beli Makanan"<<endl;
                        cout <<"2. Kembali ke Menu Awal"<<endl;
                        cout <<"Pilihan :";
                        if(!(cin>>pilPembeli)){ //input & handling pilihan menu
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            system("cls");
                            cout<<"Pilihan tidak valid!"<<endl<<endl;
                            goto menuPembeli;
                        }

                        cout<<endl;
                        switch(pilPembeli){ // switch menu pembeli
                        case 1: //pemesanan makanan
                            if(jmlMenu==0){ // cek jumlah menu makanan, jika 0 kembali ke menu sebelumnya
                                system("cls");
                                cout<<"Menu belum ditambahkan"<<endl;
                                cout<<"Tidak dapat melakukan pembelian!"<<endl<<endl;
                                break;
                            }else{
                                system("cls");
                                awalPesan:
                                do{ // perulangan pemesanan makanan
                                    cout<<setw(17)<<""<<"> Menu Makanan <"<<endl;
                                    cout << setfill('=') << setw(50) << "" << setfill(' ') << endl;
                                    cout <<" "<<left<<setw(3)<<"No"<<"| "<< left << setw(30) << "Nama Menu" <<"| "<< left << setw(10) << "Harga"<< endl;
                                    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                                    if(jmlMenu==0){ // cek jumlah menu makanan
                                        cout<<setw(16)<<""<<"Menu Masih Kosong!"<<setw(20)<<""<<endl;
                                    }else{
                                        for(int i=1; i<=jmlMenu; i++){ // perulangan menampilkan
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
                                    cout<<"Pilih Aksi"<<endl;
                                    cout<<"1. Tambah Pesanan"<<endl;
                                    cout<<"2. Batalkan Pesanan"<<endl;
                                    cout<<"3. Konfirmasi Pesanan"<<endl;
                                    cout<<"Pilihan : ";
                                    if(!(cin>>pilPesanan)){ // imput & handling pilihan menu pemesanan
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        system("cls");
                                        cout <<endl<< "Pilihan tidak valid!" << endl <<endl;
                                        goto awalPesan;
                                    }
                                    cout<<endl;

                                    switch(pilPesanan){ // switch pilihan menu pemesanan
                                    case 1:// tambah pesanan
                                        cout<<"Pilih Nomor Menu Makanan"<<endl;
                                        cout<<"Pilih 0 untuk membatalkan"<<endl;
                                        cout<<"Pilihan : ";
                                        while(!(cin>>pilMakan) || pilMakan<0 || pilMakan>jmlMenu){ // input & handling tambah pesanan
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cout<<"Menu Tidak Ditemukan"<<endl<<endl;
                                            cout<<"Pilih Ulang Nomor Menu Makanan"<<endl;
                                            cout<<"Pilih 0 untuk membatalkan"<<endl;
                                            cout<<"Pilihan : ";
                                        }
                                        if(pilMakan==0){ // input 0, batalkan tambah pesanan
                                            system("cls");
                                            cout<<"Tambah Pesanan dibatalkan!"<<endl<<endl;
                                            goto awalPesan;
                                        }else{
                                            cout <<"Masukan Jumlah Pembelian"<<endl;
                                            cout << "Jumlah : ";
                                            while(!(cin>>jmlPembelian) || jmlPembelian < 0){ //input & handling jumlah pembelian
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                                cout << "Jumlah tidak valid!" << endl<<endl;
                                                cout << "Masukan Ulang Jumlah Pembelian" << endl;
                                                cout << "Jumlah : ";
                                            }
                                            // int jmlPesanan[maxMenu], namaPesanan[maxMenu], hargaPesanan[maxMenu], menuPesanan;
                                            if(menuPesanan==0){ // cek jumlah daftar pesanan
                                                // tambah ke daftar pesanan
                                                namaPesanan[menuPesanan]=namaMenu[pilMakan];
                                                hargaPesanan[menuPesanan]=hargaMenu[pilMakan];
                                                jmlPesanan[menuPesanan]=jmlPembelian;
                                                //totalHarga+=(hargaPesanan[pilMakan]*jmlPembelian);
                                                menuPesanan++;

                                            }else{
                                                int i;
                                                for( i=0;i<menuPesanan;i++){ // cek menu yang ditambahakan
                                                    // jika menu yng ditambahkan ada di daftar menu
                                                    // menambahkan jumlah pembelian
                                                    if(namaPesanan[i]==namaMenu[pilMakan] && hargaPesanan[i]==hargaMenu[pilMakan]){
                                                        jmlPesanan[i]+=jmlPembelian;
                                                        //totalHarga+=(hargaPesanan[i]*jmlPembelian);
                                                        break;
                                                    }
                                                }
                                                if(i==menuPesanan){
                                                    // jika menu yng ditambahkan tidak ada di daftar menu
                                                    // menambahkan daftar pembelian baru
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
                                            for(int i; i<=menuPesanan;i++){ // mengosongkan daftar pesanan
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
                                                    // kondisi input pemesanan ke laporan pembelian
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
                    cout<< "! PERINGATAN !"<<endl<<endl;
                    cout<<"Menghentikan aplikasi akan menghapus semua data!" <<endl;
                    cout<<"Ketik ulang \"HENTIKAN APLIKASI\" untuk menghentikan aplikasi"<<endl;
                    cout<<"Ketik apapun untuk membatalkan"<<endl;
                    cout<<"Jawaban: ";
                    getline(cin>>ws,konfirmasiExit);
                    cout<<endl;
                    if(konfirmasiExit=="HENTIKAN APLIKASI"){
                        cout<<"Aplikasi Dihentikan"<<endl<<endl;
                        exit(1);

                    }else{
                        system("cls");
                        cout<<"Penghentian Aplikasi Dibatalkan"<<endl<<endl;
                        break;
                    }

                default:
                    system("cls");
                    cout<<"Pilihan tidak tersedia!"<<endl<<endl;
                    break;
            }
           }while (konfirmasiExit!="HENTIKAN APLIKASI");
            // END MENU AWAL
         return 0;
        }

