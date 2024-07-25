# c++ conn db
1. install wsl 2

2. ke windows features, setelah itu nyalakan (hypervisor, virtual machine platform, windows subsystem linux)

3. setelah itu silahkan pada termainal powershell ketikan : 
```
wsl --install -d ubuntu
```
3. setelah selesai loading jika disuruh isi UNIX :
```
unix nya isi (nama anda)
```
```
password nya : 123
```
4. setelah berhasil ter install pastikan version yang terinstall version 2 : 
```
wsl -l -v 
```
5. misalkan setelah terinstall wsl nya belum version 2 
```
wsl --set-default-version 2
```
6. misalkan sudah berhasil ter install silahkan pada terminal powershell ketikan : 
```
ubuntu config --default-user root
```
7. setelah itu install docker, dan pada settings di reosource aktifkan wsl integration 
```
ubuntu
```
8. jika bisa install untuk tools db nya install navicat (gak usah di crack)

9. jika semuanya sudah berhasil, pada ubuntu ketik:
```
mkdir strukdat
```
10. setelah itu copy kan 
```
version: '3'

services:
  mysql_cpp:
    image: mariadb:10.2
    container_name: mysql_cpp
    restart: unless-stopped
    tty: true
    ports:
      - "31235:3306"
    volumes:
      - ./database/data:/var/lib/mysql
      - ./database/conf.d:/etc/mysql/conf.d:ro
    environment:
      MYSQL_USER: root
      MYSQL_PASSWORD: 123
      MYSQL_ROOT_PASSWORD: 123
      SERVICE_TAGS: dev
      SERVICE_NAME: mysql
    read_only: false

  # phpmyadmin:
  #   image: phpmyadmin:latest
  #   container_name: phpmyadmin
  #   restart: always
  #   ports:
  #     - 9100:80
  #   environment:
  #     - PMA_ARBITRARY=1

```
10. setelah itu di dalam file strukdat ketikan : 
```
docker compose up -d --build
```
11. setelah itu silahkan pada navicat 
```
create new connection (pilih mysql)
```
12. set : 
```
connection name: mysql_cpp
host : 127.0.0.1
port: 31235
username: root
password : 123

TOLONG PASTIKAN CONTAINER MYSQL BERJALAN !!!, cek nya ketikan : docker ps 
```
13. setelah itu klik dibagian connection yang bernama mysql_cpp setelah itu :
```
create new database
```

14. bikin database dengan format seperti ini : 
```
id          tipe datanya : int lengh 12 (auto increment)
name        tipe datanya : string (VARCHAR) lengh 255 
nim         tipe datanya : bigint (bigint)  lengh 20
asal_kampus tipe datanya : string (VARCHAR) lengh 255
jurusan     tipe datanya : string (VARCHAR) lengh 255
fakultas    tipe datanya : string (VARCHAR) lengh 255
```

15. setelah itu ctrl + s, lalu save dengan nama (cpp_crud)

16. setelah itu bikin codingan nya, ambil di github ini

17. sebelum connect to db, pada terminal silahkan ketikan : 
```
apt-get install libmysqlclient-dev
```
18. kita harus mengcompile code kita : 
```
g++ -o crud_simple crud.cc -lmysqlclient
```
19. running hasil compile nya : 
```
./crud_simple
```
- struktur folder yang benar : 
```plaintext
|-- database
|   |-- conf.d
|   |-- data
|-- crud.cc
|-- .env
|-- docker-compose.yml
|-- crud_simple.exe (hasil compile)
```


20. happy coding!!!

# tools db
navicat

https://shared.djncloud.my.id/tools_tempur

# perintah sederhana docker
1. masuk ke dalam suatu file yang terdapat docker-compose.yml
2. selanjutnya jika ingin membuild atau up si container tersebut silahkan ketikan 
```
docker compose up -d --build 
```

3. setelah itu silahkan cek container nya apakah sudah running apa belum, dengan lakukan perintah
```
docker ps 
```

4. setelah itu jika container nya sudah nyala dan ingin dibuat down silahkan ketikan 
```
docker compose down
```

# kenapa harus pake docker?
karena docker bagus buat production nantinya

# penjelasan sederhana docker 
1. Kontainer: Kontainer adalah unit kecil, ringan, dan terisolasi yang berisi aplikasi dan semua dependensinya. Kontainer memungkinkan aplikasi berjalan secara konsisten di berbagai lingkungan tanpa khawatir tentang perbedaan konfigurasi.

2. Gambar (Image): Gambar adalah cetak biru dari kontainer. Gambar berisi semua file sistem dan dependensi yang dibutuhkan oleh aplikasi. Kamu bisa membayangkan gambar sebagai resep yang digunakan untuk membuat kontainer.

3. Docker Engine: Ini adalah perangkat lunak yang menjalankan kontainer Docker. Docker Engine mengelola pembuatan dan eksekusi kontainer di mesin kamu.

4. Docker Hub: Ini adalah repositori online tempat kamu bisa menyimpan dan mendistribusikan gambar Docker. Kamu bisa mengunduh gambar yang sudah ada atau mengunggah gambar yang kamu buat.

5. Portabilitas: Karena kontainer berisi semua yang dibutuhkan aplikasi, mereka bisa berjalan di mana saja—di komputer lokal, server, atau cloud—tanpa perlu menyesuaikan lingkungan eksekusi.

6. Isolasi: Kontainer berjalan secara terpisah dari sistem utama dan kontainer lainnya. Ini membantu memastikan bahwa aplikasi di dalam kontainer tidak saling mengganggu.

7. Efisiensi: Kontainer lebih efisien dibandingkan mesin virtual (VM) karena mereka berbagi kernel sistem operasi yang sama dan hanya mengemas aplikasi dan dependensinya, bukan seluruh sistem operasi.
