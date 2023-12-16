BEGIN
program pengelolaan_menu_dan_pemesanan_menu_makanan

    // variable menu awal
    int pilihan, admin
    string konfirmasiExit

    // variable Login pengelola
    string username="UsernameLogin", password="PasswordLogin", menu, inputUsername, inputPassword
    int loginCounter=0

    //  variable Fitur Pengelola
    int pilPengelola
    int jmlTambah,  jmlMenu=0, maxMenu=20, pilHapus, pilUbah


    // variable data menu makanan
    string namaMenu[(maxMenu+1)]
    int hargaMenu[maxMenu+1]

    //variable menu pembelian
    int pilPembeli, pilMakan, jmlPembelian
    int pilPesanan
    int jmlPesanan[maxMenu], hargaPesanan[maxMenu], menuPesanan=0, totalHarga=0
    string namaPesanan[maxMenu]
    char konf, konfBatal

    REPEAT{
        OUTPUT
        "
        Menu AWAL
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





    }UNTIL konfirmasiExit==true)


