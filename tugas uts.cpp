#include <iostream>




using namespace std;

struct Barang {
    int id;
    char nama[25];
    long harga;
};

struct node {
    Barang barang;
    node* next;
};

node* head = nullptr;
node* last = nullptr;

bool isEmpty() {
    return head == nullptr;
}

char menu() {
    char choice;
    cout << "1. Input barang masuk\n";
    cout << "2. Keluar Barang\n";
    cout << "3. Cetak Barang\n";
    cout << "4. Cari Barang\n";
    cout << "5. Total Barang\n";
    cout << "6. Exit\n\n";
    cout << "Pilihan: ";
    cin >> choice;
    return choice;
}

void insert(Barang barang) {
    if (isEmpty()) {
        node* temp = new node;
        temp->barang = barang;
        temp->next = nullptr;
        head = temp;
        last = temp;
    } else {
        node* temp = new node;
        temp->barang = barang;
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

void displayList() {
    if (isEmpty()) {
        cout << "Data kosong";
    } else {
        node* current = head;
        cout << "|     Id|         Barang|Harga\n";
        cout << "-------------------------------------------------\n";
        while (current != nullptr) {
            cout << "|" << current->barang.id << "|       " << current->barang.nama << "|   " << current->barang.harga << "\n";
            current = current->next;
        }
    }
}

void searchId() {
    int tempId;
    if (!isEmpty()) {
        cout << "id barang yang dicari: ";
        cin >> tempId;
        node* temp = head;
        while (temp->next != nullptr) {
            if (temp->barang.id == tempId) {
                break;
            }
            temp = temp->next;
        }
        if (temp->barang.id == tempId) {
            cout << "Nama barang: " << temp->barang.nama << "\n";
            cout << "Harga barang: " << temp->barang.harga << "\n";
        } else {
            cout << "data id " << tempId << " gaada";
        }
    } else {
        cout << "Data kosong";
    }
}

void showTotal() {
    node* temp = head;
    int total = 0;
    while (temp != nullptr) {
        total += 1;
        temp = temp->next;
    }
    cout << "Total barang yang ada di gudang: " << total << "\n";
}

void barangKeluar() {
    int tempid;
    if (isEmpty()) {
        cout << "Data kosong";
    } else {
        cout << "id barang yang keluar: ";
        cin >> tempid;
        node* temp = head;
        while (temp->next != nullptr) {
            if (temp->barang.id == tempid) {
                break;
            }
            temp = temp->next;
        }
        if (temp->barang.id == tempid) {
            cout << "Barang " << temp->barang.id << " telah keluar gudang\n";
            cout << "Detail: \n";
            cout << "Id barang: " << temp->barang.id << "\n";
        } else {
            cout << "data id " << tempid << " gaada";
        }
    }
}

int main() {
    char choice;
    Barang barang;
    do {
        system("cls");
        choice = menu();
        switch (choice) {
            case '1':
                cout << "Id Barang: ";
                cin >> barang.id;
                cout << "Nama Barang: ";
                cin >> barang.nama;
                cout << "Harga Barang: ";
                cin >> barang.harga;
                insert(barang);
                break;
            case '2':
                barangKeluar();
                break;
            case '3':
                displayList();
                break;
            case '4':
                searchId();
                break;
            case '5':
                showTotal();
                break;
            case '6':
                cout << "Exit";
                break;
            default:
                cout << "Input salah";
                break;
        }
        cin.ignore();
        cin.get();
    } while (choice != '6');
    return 0;
}
