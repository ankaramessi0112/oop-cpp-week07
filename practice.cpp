#include <iostream>
#include <string>

using namespace std;

struct Credentials {
    string username;
    string password;
};

struct Computer {
    string id;
    string name;
    string os;
    string username;
    string pwd;
    string model;
    int year;

    Computer() {}

    Computer(string _id, string _name, string _os, string _username, string _pwd, string _model, int _year) {
        id = _id;
        name = _name;
        os = _os;
        username = _username;
        pwd = _pwd;
        model = _model;
        year = _year;
    }

    void print() {
        cout << "ID: " << id << " | Name: " << name << " | OS: " << os << endl;
    }
};

struct Lab {
    string roomId;
    string purpose;
    Computer computers[100]; 
    int count = 0;           

    Lab(string _roomId, string _purpose) {
        roomId = _roomId;
        purpose = _purpose;
    }

    void addComputer(Computer comp) {
        computers[count] = comp;
        count++;
    }

    void showLabInfo() {
        cout << "Lab Room: " << roomId << " - Purpose: " << purpose << endl;
    }

    void getComputerInfo(string searchId) {
        for (int i = 0; i < count; i++) {
            if (computers[i].id == searchId) {
                computers[i].print();
                return;
            }
        }
        cout << "Computer not found." << endl;
    }

    Computer getComputerById(string searchId) {
        for (int i = 0; i < count; i++) {
            if (computers[i].id == searchId) {
                return computers[i];
            }
        }
        return Computer(); 
    }

    Computer* getComputers() {
        return computers;
    }
    Credentials getUserAndPwd(string searchId) {
        for (int i = 0; i < count; i++) {
            if (computers[i].id == searchId) {
                return {computers[i].username, computers[i].pwd};
            }
        }
        return {"", ""};
    }
};

int main() {
    Lab myLab("A5-104", "Thuc hanh");

    Computer pc1("PC01", "May 1", "Win 11", "sv01", "123456", "Dell", 2023);
    Computer pc2("PC02", "May 2", "Ubuntu", "sv02", "password", "HP", 2022);
    
    myLab.addComputer(pc1);
    myLab.addComputer(pc2);

    myLab.showLabInfo();
    
    cout << "\n--- Search for PC01 ---" << endl;
    myLab.getComputerInfo("PC01");
    
    cout << "\n--- Get User and Pass for PC02 ---" << endl;
    Credentials creds = myLab.getUserAndPwd("PC02");
    
    if (creds.username != "") {
        cout << "Username: " << creds.username << " | Password: " << creds.password << endl;
    } else {
        cout << "Computer not found." << endl;
    }

    return 0;
}