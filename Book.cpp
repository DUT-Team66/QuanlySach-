#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() {
    this->bookID = "";
    this->bookName = "";
    this->publishingYear = 0;
    this->amount = 0;
    this->status = 0;
}
Book::Book(string id, string name, int pyear, int amt, bool sta) : bookID(id), bookName(name), publishingYear(pyear), amount(amt), status(sta) {

}
Book::Book(const Book& b) {
    this->bookID = b.bookID;
    this->bookName = b.bookName;
    this->publishingYear = b.publishingYear;
    this->amount = b.amount;
    this->status = b.status;
}
Book::~Book() {

}
const string& Book::getBookID() const {
    return this->bookID;
}
void Book::setBookID(const string& id) {
    this->bookID = id; 
}
const string& Book::getBookName() const {
    return this->bookName;
}
void Book::setBookName(const string& name) {
    this->bookName = name; 
}
const int& Book::getPublishingYear() const {
    return this->publishingYear;
}
void Book::setPublishingYear(const int& publishingYear) {
    this->publishingYear = publishingYear; 
}
const int& Book::getAmount() const {
    return this->amount;
}
void Book::setAmount(const int& amount) {
    this->amount = amount; 
}
const bool& Book::getStatus() const {
    return this->status;
}
void Book::setStatus(const bool& status) {
    this->status = status; 
}
istream& operator >> (istream& in, Book& s) {
    do {
        cout << "Nhap ma so sach: ";
        in >> s.bookID;
        bool check = true;
        for(int i = 0;i < s.bookID.length(); ++i) {
            if(s.bookID[i] < '0' || s.bookID[i] > '9') {
                check = false;
                break;
            }
        }
        if(check) {
            if(stoi(s.bookID) < 10000 || stoi(s.bookID) > 59999) {
                check = false;
            } 
        } 
        if(!check) {
            cout << "Ma so sach phai tu 10000 den 59999!" << endl;   
        } else break;
    } while(true);
    in.ignore();

    cout << "Nhap ten sach: ";
    getline(in, s.bookName);
    
    do{
        cout << "Nhap nam xuat ban: ";
        in >> s.publishingYear;
        if(s.publishingYear < 1000 || s.publishingYear > 9999) {
            cout << "Nam xuat ban phai co 4 chu so!" << endl;
            cin.clear();
        } else break;
    } while(true);

    cout << "Nhap so quyen: ";
    in >> s.amount;

    cout << "Nhap tinh trang sach: ";
    in >> s.status;
    return in;
}
ostream& operator << (ostream& out, const Book& s) {
    out << "Ma so sach: " << s.bookID << endl
    << "Ten sach: " << s.bookName << endl
    << "Nam xuat ban: " << s.publishingYear << endl
    << "So quyen: " << s.amount << endl
    << "Tinh trang sach: " << ((s.status == 1)? "co the muon" : "khong the muon") << endl; 
    return out;
}