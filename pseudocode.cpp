BEGIN
JUDUl
    program pengelolaan_menu_dan_pemesanan_menu_makanan
DEKLARASI
    //menu awal
    int pilihan, admin
    string konfirmasiExit

    //Login pengelola
    string username="UsernameLogin", password="PasswordLogin", inputUsername, inputPassword

    //Fitur Pengelola
    int pilPengelola
    int jmlTambah,  jmlMenu=0, maxMenu=20, pilHapus, pilUbah

    //data menu makanan
    string namaMenu[(maxMenu+1)]
    int hargaMenu[maxMenu+1]

    //menu pembelian
    int pilPembeli, pilMakan, jmlPembelian
    int pilPesanan
    int jmlPesanan[maxMenu], hargaPesanan[maxMenu], menuPesanan=0, totalHarga=0
    string namaPesanan[maxMenu]
    char konf, konfBatal

    //laporan pembelian
    string lapNama[100];
    int lapHarga[100],lapTotal[100], jmlLap=0, totalKeuntungan=0;

IMPLEMENTASI
    REPEAT{
        OUTPUT
        "
        Menu Awal
        1. Pengelola
        2. Pembeli
        3. Exit
        Pilihan :
        "
        INPUT pilihan

        IF pilihan== 1
            THEN
            OUTPUT
            "
            Login Pengelola
            Username:
            "
            INPUT inputUsername
            OUTPUT
            "Password: "
            INPUT inputPassword

            IF inputUsername!=username && inputPassword != pasword
            THEN
                OUTPUT "Login Gagal"
                GOTO Menu Awal
            ELSE
                OUTPUT "Login Berhasil"
            ENDIF

            REPEAT{
                LOOP OUTPUT namaMenu, hargaMenu
                OUTPUT
                "
                Menu Pengelola
                1. Tambah menu
                2. Ubah menu
                3. Hapus menu
                4. Lihat daftar menu
                5. Lihat laporan pembelian
                6. Logout
                Pilihan:
                "
                INPUT pilpengelola
                IF pilPengelola == 1
                THEN
                    OUTPUT "Masukan Jumlah Makanan yang akan ditambahkan : "
                    INPUT jmlTambah
                    FOR loop<jmlTambah{
                        OUTPUT "Masukan Nama"
                        INPUT namaMenu[i]
                        OUTPUT "Masukan Harga"
                        INPUT hargaMenu[i]
                        jmlmenu++
                    }
                    OUTPUT "Berhasil menambah Menu"
                ELSEIF pilPengelola == 2
                THEN
                    OUTPUT "Pilih menu yang akan diubah : "
                    INPUT pilUbah
                    OUTPUT "Masukan Nama Baru"
                    INPUT namaMenu[pilUbah]
                    OUTPUT "Masukan Harga Baru"
                    INPUT hargaMenu[pilUbah]
                ELSEIF pilPengelola == 3
                THEN
                    OUTPUT "Pilih menu yang akan dihapus : "
                    INPUT pilHapus
                    int i
                    FOR i<jmlMenu, i++{
                        IF i==pilHapus
                        THEN
                            BREAK;
                        ENDIF
                    }
                    IF i<=jmlMenu
                    THEN
                        FOR int j=i, j<jmlMenu,i++{
                            namaMenu[j]= namaMenu[j+1];
                            hargaMenu[j]= hargaMenu[j+1];
                        }
                         jmlMenu--;
                    ENDIF
                ELSEIF pilPengelola == 4
                THEN
                    OUTPUT "Daftar Menu Makanan"
                    OUTPUT "No | Nama Menu    | Harga"
                    FOR int i=0, i<jmlMenu, i++{
                        OUTPUT i+1 | namaMenu     | hargaMenu
                    }
                ELSEIF pilPengelola == 5
                THEN
                    OUTPUT "Laporan Pembelian"
                    OUTPUT "No | Nama Menu    | Harga | Jumlah"
                    FOR int i=0, i<lap, i++{
                        OUTPUT i+1 | namaMenu | hargaMenu | Jumlah
                    }
                    OUTPUT totalKeuntungan
                ELSEIF pilPengelola == 6
                THEN
                    OUTPUT "Konfirmasi Logout"
                    INPUT logout
                    IF logout == true
                    THEN
                        OUTPUT "Berhasi Logout"
                        GOTO MenuAwal
                    ELSEIF logout == false
                    THEN
                        OUTPUT "Logout Dibatalkan"
                ELSE
                    OUTPUT "Input Tidak Valid"
                ENDIF
            }UNTIL logout==true

        ELSEIF pilihan == 2
        THEN
            OUTPUT
            "
            1. Beli Makanan
            2. Kembali
            Pilihan :
            "
            INPUT menuPembeli
            IF menuPembeli == 1
            THEN
                OUTPUT "Daftar Menu"
                OUTPUT " No | Nama Menu | Harga"
                FOR int i=1, i<jmlMenu, i++{
                    OUTPUT i | namaMenu[i] | hargaMenu[i]
                }
                OUTPUT "Daftar Pesanan"
                OUTPUT " No | Nama Menu | Harga | Jumlah"
                FOR int i=1, i<jmlMenu, i++{
                    OUTPUT i | namaMenu[i] | hargaMenu[i] | jmlPesanan[i]
                }
                OUTPUT
                "Total Harga : " totalHarga
                "
                1. Tambah Pesanan
                2. Batalkan Pesanan
                3. Konfirmasi Pesanan
                Pilihan :
                "
                INPUT pilPesanan
                IF pilPesanan == 1
                THEN
                    OUTPUT "Pilih Nomor Menu Makanan: "
                    INPUT pilMakan
                    OUTPUT "Masukan Jumlah Pembelian: "
                    INPUT jmlPembelian
                    namaPesanan[menuPesanan]=namaMenu[pilMakan]
                    hargaPesanan[menuPesanan]=hargaMenu[pilMakan]
                    jmlPesanan[menuPesanan]=jmlPembelian
                    menuPesanan++
                ELSEIF pilPesanan == 2
                THEN
                    OUTPUT "Konfirmasi Pembatalan Pesanan"
                    INPUT konfBatal
                    IF konfBatal == true
                    THEN
                        LOOP setiap daftar pesanan{
                            namaPesanan[i]="";
                            hargaPesanan[i]=NULL;
                            jmlPesanan[i]=NULL;
                        }
                        menuPesanan=0
                        OUTPUT "Pesanan Dibatalkan"
                        BREAK pemesanan;
                    ELSEIF konfBatal == false
                        OUTPUT "Pembatalan Dibatalkan"
                    ENDIF
                ELSEIF pilPesanan == 3
                THEN
                    OUTPUT "Konfirmasi Pembelian"
                    INPUT konf
                    IF konf == true
                    THEN
                        tambah_pesanan_ke_laporan(namaPesanan, hargaPesanan, jmlPesanan)
                        LOOP setiap daftar pesanan{
                            namaPesanan[i]="";
                            hargaPesanan[i]=NULL;
                            jmlPesanan[i]=NULL;
                        }
                        jmlLap++
                        menuPesanan=0;
                        OUTPUT "Pembelian Berhasil"
                    ELSEIF konf == false
                    THEN
                        OUTPUT "Konfirmasi Dibatalkan"
                    ENDIF
                ELSE
                    OUTPUT "Input tidak Valid"
                ENDIF
            ELSEIF menuPembeli== 2
            THEN
                OUTPUT "Kembali ke Menu Awal"
                GOTO MenuAwal
            ENDIF
        ELSEIF pilihan == 3
        THEN
            OUTPUT "Konfirmasi Exit"
            INPUT konfirmasiExit
            IF konfirmasiExit == true
            THEN
                OUTPUT "Aplikasi Dihentikan"
                exitProgram()
            ELSE
                OUTPUT "Exit Dibatalkan"
            ENDIF
        ELSE
            OUTPUT "Pilihan Tidak Valid"
        ENDIF
    }UNTIL konfirmasiExit==true)
END
