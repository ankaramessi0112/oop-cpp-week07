#include <iostream>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    
    void inputInfo() {
        cout << "Nhap ID sach: ";
        cin >> id;
        cin.ignore(); 
        cout << "Nhap ten sach: ";
        getline(cin, title);
        cout << "Nhap tac gia: ";
        getline(cin, author);
    } 
    
    void outputInfo() {
        cout << "ID: " << id << " | Ten sach: " << title << " | Tac gia: " << author << endl;
    }
};

struct Library {
    int idLibrary;
    string nameLibrary;
    int numBooks = 0;
    Book books[100]; 

    void inputLibrary() {
        cout << "Nhap ID thu vien: ";
        cin >> idLibrary;
        cin.ignore();
        cout << "Nhap ten thu vien: ";
        getline(cin, nameLibrary);
        
        cout << "Nhap so luong sach ban dau: ";
        cin >> numBooks; 

        for (int i = 0; i < numBooks; i++) {
            cout << "--- Nhap thong tin sach thu " << i + 1 << " ---" << endl;
            books[i].inputInfo(); 
        } 
    } 

    void outputLibrary() {
        cout << "\n=== THONG TIN THU VIEN ===" << endl;
        cout << "ID Thu vien: " << idLibrary << " | Ten: " << nameLibrary << endl;
        cout << "Danh sach " << numBooks << " cuon sach hien co:" << endl;
        
        for (int i = 0; i < numBooks; i++) {
            books[i].outputInfo();
        } 
    } 	
    
    void addBook(Book b) {
        if (numBooks < 100) {
            books[numBooks] = b;
            numBooks++; 
        } else {
            cout << "Thu vien da day!" << endl;
        }
    } 

    void printBookInfo(int idBook) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) {
                books[i].outputInfo();
                return; 
            }
        }
        cout << "Khong tim thay sach!" << endl;
    }
    Book getBookById(int idBook) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) {
                return books[i];
            }
        }
        return Book();
    } 

    Book* getBooks() {
        return books; 
    }
}; 	

int main() {
    Library hcmuteLib; 
    
    hcmuteLib.inputLibrary();
    hcmuteLib.outputLibrary();
    
    int searchId;
    cout << "\n=== TIM KIEM SACH ===" << endl;
    cout << "Nhap ID sach ban muon tim: ";
    cin >> searchId;
    
    hcmuteLib.printBookInfo(searchId);

    return 0;
}