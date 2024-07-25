#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct User {
    int id;
    string name;
    string nim;
    string asal_kampus;
    string jurusan;
    string fakultas;
};

vector<User> users;
int current_id = 1;

void create_user(const string& name, const string& nim, const string& asal_kampus, const string& jurusan, const string& fakultas) {
    User user = {current_id++, name, nim, asal_kampus, jurusan, fakultas};
    users.push_back(user);
    cout << "User Sudah Ditambahkan." << endl;
}

void get_users() {
    if (users.empty()) {
        cout << "User Tidak Ditemukan." << endl;
        return;
    }

    for (const auto& user : users) {
        cout << "ID: " << user.id << ", Name: " << user.name << ", NIM: " << user.nim 
             << ", Asal Kampus: " << user.asal_kampus << ", Jurusan: " << user.jurusan 
             << ", Fakultas: " << user.fakultas << endl;
    }
}

void update_user(int user_id, const string& name, const string& nim, const string& asal_kampus, const string& jurusan, const string& fakultas) {
    for (auto& user : users) {
        if (user.id == user_id) {
            user.name = name;
            user.nim = nim;
            user.asal_kampus = asal_kampus;
            user.jurusan = jurusan;
            user.fakultas = fakultas;
            cout << "User Sudah Diubah." << endl;
            return;
        }
    }
    cout << "User Tidak Ditemukan." << endl;
}

void delete_user(int user_id) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->id == user_id) {
            users.erase(it);
            cout << "User Sudah Dihapus." << endl;
            return;
        }
    }
    cout << "User Tidak Ditemukan." << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambah User\n";
        cout << "2. Tapilkan Semua Users\n";
        cout << "3. Update User\n";
        cout << "4. Hapus User\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, nim, asal_kampus, jurusan, fakultas;
            cout << "Input nama: ";
            cin.ignore();
            getline(cin, name);
            cout << "Input NIM: ";
            getline(cin, nim);
            cout << "Input Asal Kampus: ";
            getline(cin, asal_kampus);
            cout << "Input Jurusan: ";
            getline(cin, jurusan);
            cout << "Input Fakultas: ";
            getline(cin, fakultas);
            create_user(name, nim, asal_kampus, jurusan, fakultas);
        } else if (choice == 2) {
            get_users();
        } else if (choice == 3) {
            int user_id;
            string name, nim, asal_kampus, jurusan, fakultas;
            cout << "Input user ID untuk diubah: ";
            cin >> user_id;
            cin.ignore();
            cout << "Input Nama Baru: ";
            getline(cin, name);
            cout << "Input NIM Baru: ";
            getline(cin, nim);
            cout << "Input Asal Kampus Baru: ";
            getline(cin, asal_kampus);
            cout << "Input Jurusan Baru: ";
            getline(cin, jurusan);
            cout << "Input Fakultas Baru: ";
            getline(cin, fakultas);
            update_user(user_id, name, nim, asal_kampus, jurusan, fakultas);
        } else if (choice == 4) {
            int user_id;
            cout << "Input ID untuk Dihapus: ";
            cin >> user_id;
            delete_user(user_id);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Pilihan Tidak Valid!!! Silahkan Coba Lagi." << endl;
        }
    }
    return 0;
}
