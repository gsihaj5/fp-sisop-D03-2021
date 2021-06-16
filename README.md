# fp-sisop-D03-2021

# Soal
## Rincian Final Project
### :open_book: Sistem Database Sederhana :open_book:
#### **Bagaimana Program Diakses**
-	Program server berjalan sebagai daemon
-	Untuk bisa akses console database, perlu buka program client (kalau di linux seperti command mysql di bash)
-	Program client dan utama berinteraksi lewat socket
-	Program client bisa mengakses server dari mana aja

**Directory Structure**     
![Struktur repo](https://github.com/widigdacahya/gif/blob/main/struktur1.PNG?raw=true)

-	Penamaan dari program bebas         
![struktur server](https://github.com/widigdacahya/gif/blob/main/2_struktur_server.PNG?raw=true)
![contoh struktur server](https://github.com/widigdacahya/gif/blob/main/3_contohstrukturserver.PNG)
-	Bagaimana struktur data saat tersimpan di dalam file tabel dibebaskan.

#### **Bagaimana Database Digunakan**
:green_book: **Autentikasi**
-	Ada username dan password tertentu untuk bisa akses database yang dia punya hak. Jika root (sudo) bisa akses semua database (tidak perlu didefinisikan secara rinci haknya, hanya dia bisa akses atau nggak).
![autentikasi](https://github.com/widigdacahya/gif/blob/main/4_autentifikasi.PNG)

-	Username, password, dan hak akses db disimpan di suatu database juga, tapi tidak ada user yang bisa akses database tersebut kecuali mengakses menggunakan root.
-	User root sudah ada dari awal         
![root](https://github.com/widigdacahya/gif/blob/main/5_rootuser.PNG)
-	Menambahkan user (Hanya bisa dilakukan user root)       
![tambahuser](https://github.com/widigdacahya/gif/blob/main/6_menambahrootuser.PNG)

:green_book: **Authorisasi**
-	Untuk dapat mengakses database yang dia punya permission dengan command. Pembuatan tabel dan semua DML butuh untuk mengakses database terlebih dahulu.      
![autorasi](https://github.com/widigdacahya/gif/blob/main/7_authorisasi.PNG)
-	Yang bisa memberikan permission atas database untuk suatu user hanya root.
![grant](https://github.com/widigdacahya/gif/blob/main/8_grantpermission.PNG)
-	User hanya bisa mengakses database dimana dia diberi permission untuk database tersebut.

:green_book: **Data Definition Language**
-	Input penamaan database, tabel, dan kolom hanya angka dan huruf.
-	Semua user bisa membuat database, otomatis user tersebut memiliki permission untuk database tersebut.
![create syntax](https://github.com/widigdacahya/gif/blob/main/9_grant_permission.PNG)

-	Root dan user yang memiliki permission untuk suatu database untuk bisa membuat tabel untuk database tersebut, tentunya setelah mengakses database tersebut. Tipe data dari semua kolom adalah string atau integer. Jumlah kolom bebas.
![create table](https://github.com/widigdacahya/gif/blob/main/10_syntax.PNG)
-	Bisa melakukan DROP database, table (setelah mengakses database), dan kolom. Jika sasaran drop ada maka didrop, jika tidak ada maka biarkan.        
![drop table](https://github.com/widigdacahya/gif/blob/main/11_syntax_drop.PNG)

:green_book: **Data Manipulation Language**
-	INSERT
Hanya bisa insert satu row per satu command. Insert sesuai dengan jumlah dan urutan kolom.
![insert](https://github.com/widigdacahya/gif/blob/main/12_dml_insert.PNG)

-	UPDATE
Hanya bisa update satu kolom per satu command.
![update](https://github.com/widigdacahya/gif/blob/main/13_dml_update.PNG)

-	DELETE
Delete data yang ada di tabel.
![delete](https://github.com/widigdacahya/gif/blob/main/14_dml_Delete.PNG)

-	SELECT                                  
![select](https://github.com/widigdacahya/gif/blob/main/15_dml_select.PNG)

-	WHERE
Command UPDATE, SELECT, dan DELETE bisa dikombinasikan dengan WHERE. WHERE hanya untuk satu kondisi. Dan hanya ‘=’.
![combined](https://github.com/widigdacahya/gif/blob/main/16_combined.PNG)

:green_book: **Logging**
-	Setiap command yang dipakai harus dilakukan logging ke suatu file dengan format. Jika yang eksekusi root, maka username root.
![log format](https://github.com/widigdacahya/gif/blob/main/17_logging.PNG)

:green_book: **Reliability**
-	Harus membuat suatu program terpisah untuk dump database ke command-command yang akan di print ke layar. Untuk memasukkan ke file, gunakan redirection. Program ini tentunya harus melalui proses autentikasi terlebih dahulu. Ini sampai database level saja, tidak perlu sampai tabel.         
![reliability](https://github.com/widigdacahya/gif/blob/main/18_realibility.PNG)

Contoh hasil isi file database1.backup:             
![contoh hasil backup](https://github.com/widigdacahya/gif/blob/main/19_contoh.PNG)

-	Program dump database dijalankan tiap jam untuk semua database dan log, lalu di zip sesuai timestamp, lalu log dikosongkan kembali.

:green_book: **Tambahan**
-	Kita bisa memasukkan command lewat file dengan redirection di program client. 
![command](https://github.com/widigdacahya/gif/blob/main/20_cmd.PNG)

:green_book: **Error Handling**
-	Jika ada command yang tidak sesuai penggunaannya. Maka akan mengeluarkan pesan error tanpa keluar dari program client.

:green_book: **Extra**
-	Program client dan dump berkomunikasi dengan socket ke program utama dan tidak boleh langsung mengakses file-file di folder program utama.
-	Requirement disini adalah requirement minimum, jika Anda mengerjakan melebihi requirement disini, maka akan mendapat nilai tambah.
-	Terapkan apa saja yang sudah kalian pelajari di praktikum sistem operasi ini untuk mengerjakan final project.






