// Journal = Message Object + Storage Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Ralph Cange

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Message
{
    string title;
    vector<string> entries;
    Message(const string& title = " ") :title(title) { }
    void add(const string& entry);
};

void Message::add(const string& entry) { //scope resolution operator
    entries.push_back(entry);
}

struct FileManager {
    static void save(const Message& j, const string& filename) {
        ofstream ofs(filename);
        ofs << j.title << endl;
        for (auto& s : j.entries)
            ofs << s << endl;
    }

    static void load(Message& j, const string& filename) {
        ifstream ifs(filename);
        string line;
        getline(ifs, j.title, '\n');
        while (getline(ifs, line, '\n')) {
            j.add(line);
        }
    }
};

ostream& operator<<(ostream& out, const Message& j) {
    out << j.title << endl;
    for (const auto m : j.entries)
        out << m << endl;

    return out;

}

const string filename = "Office text";
void main1();
void main2();

int main(){
main1();
main2();
return 0;
}

void main1() {
    string myTitle = "DailyPhoneMessages";
    Message journal{ myTitle };

    journal.add("10am from AMGEN");
    journal.add("11:30 am lunch");
    journal.add("5:00pm Mac125");

    cout << "these me my messages:\n";
    cout << journal << endl;

    FileManager pm;
    pm.save(journal, filename);

    cout << " journal saved\n";
}

void main2() {

    Message journal;
    FileManager pm;

    pm.load(journal, filename);

    cout << "my old messages : " << endl;
    cout << journal << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
