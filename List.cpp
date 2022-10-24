#include "List.h"
#include <iostream>
using namespace std;

List::List()
{
    this->p = nullptr;
    this->length = 0;
}
List::~List() {
    delete[] this->p;
}
const int &List::GetLength() const
{
    return this->length;
}
void List::SetLength(const int& n) {
    this->length = n;
}
void List::Show()
{
    for (int i = 0; i < this->length; ++i)
    {
        cout << this->p[i];
    }
}

void List::Add(const Book &b, int index)
{
    if(index < 0 || index > this->length) {
        cout << "Vi tri them khong hop le" << endl;
        return;
    }
    bool check = false;
    for (int i = 0; i < this->length; ++i)
    {
        if ((this->p+i)->getBookID() == b.getBookID())
        {
            (this->p+i)->setAmount((this->p+i)->getAmount() + b.getAmount());
            (this->p+i)->setStatus(1);
            check = true;
            break;
        }
    }
    if (!check)
    {
        if (this->p == nullptr)
        {
            this->p = new Book[1];
            *(this->p) = b;
            this->length++;
        }
        else
        {
            Book *tmp = new Book[this->length];
            for (int i = 0; i < this->length; ++i) {
                *(tmp + i) = *(this->p + i);
            }
            delete[] this->p;
            this->p = new Book[this->length + 1];
            for (int i = 0; i < index; ++i){
                *(this->p + i) = *(tmp + i);
            }
            *(this->p + index) = b;
            for (int i = index +1; i < this->length + 1; ++i) {
                *(this->p + i) = *(tmp + i - 1);
            }
            delete[] tmp;
            this->length++;
        }
    } 
}
void List::Update(string id) 
{
    bool check = false;
    for(int i = 0; i < this->length; ++i) {
        if((this->p + i)->getBookID() == id) {
            string name; 
            int publishingYear, amount,status;
            cout << "Neu khong muon cap nhat thi de rong doi voi ten sach, -1 voi thuoc tinh con lai\n";
            cout << "Nhap ten sach: ";
            getline(cin, name);
            cout << "Nhap nam xuat ban: ";
            cin >> publishingYear;
            cout << "Nhap so quyen: ";
            cin >> amount;
            cout << "Nhap tinh trang sach: ";
            cin >> status;
            if(name != "") {
                (this->p+i)->setBookName(name);
            } 
            if(publishingYear != -1) {
                (this->p+i)->setPublishingYear(publishingYear);
            }
            if(amount != -1) {
                (this->p+i)->setAmount(amount);
            }
            if(status != -1) {
                (this->p+i)->setStatus(status);
            }
            check = true;
            break;  
        }
    }
    if(!check) cout << "Khong ton tai ma sach" << endl;
}
void List::Delete(int index) {
    if(index < 0 || index >= this->length) {
        cout << "Vi tri khong hop le" << endl;
        return;
    }
    
    cout << "Nhap so luong sach can xoa: ";
    int amt; cin >> amt;
    (this->p + index)->setAmount((this->p + index)->getAmount() - amt);
    if((this->p + index)->getAmount() <=0) {
        Book *tmp = new Book[this->length];
    
        for(int i = 0; i < this->length; ++i) {
            *(tmp + i) = *(this->p +i);
        }
        delete[] this->p;
        this->p = new Book[this->length-1];
        for(int i = 0;i< index; ++i) {
            *(this->p + i) = *(tmp + i);
        }
        for(int i = index; i < this->length - 1; ++i) {
            *(this->p + i) = *(tmp + i + 1);
        }
        delete[] tmp;
        this->length--;
    } 

    
}
void List::Search(int year)
{
    bool check = false;
    int left = 0;
    int right = this->length - 1;
    if(left == right) {
        if((this->p)->getPublishingYear() == year) {
            cout << *(this->p);
        } else {
            cout << "Khong ton tai sach thoa man tieu chi" << endl;
        }
        return;
    }
    while(left <= right && year >= (this->p + left)->getPublishingYear() && year <= (this->p + right)->getPublishingYear()) {
        int val1 = (year - (this->p + left)->getPublishingYear()) / ((this->p + right)->getPublishingYear() - (this->p + left)->getPublishingYear());
        int val2 = right - left;
        int pos = left + val1*val2;
        if((this->p + pos)->getPublishingYear() == year) {
            cout << *(this->p + pos);
            check = true;
            break;
        } 
        if((this->p + pos)->getPublishingYear() < year) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    if(!check) cout << "Khong ton tai sach thoa man tieu chi" << endl;
}

void List::Sort(bool cmp(int,int)) {
    for(int gap = this->length/2; gap>0; gap/=2) {
        for(int i = gap; i < this->length; ++i) {
            Book tmp = *(this->p +i);
            int j;
            for(j = i; j >= gap && cmp((this->p+j-gap)->getPublishingYear(),tmp.getPublishingYear()); j -= gap){
                *(this->p + j) = *(this->p + j-gap);
            }
            *(this->p + j) = tmp;
        }
    } 
}
istream& operator >> (istream& in, List& bl) {
    cout << "Nhap so luong ma sach: "; 
    int n; cin >> n; bl.SetLength(n);
    for(int i = 0; i < bl.GetLength(); ++i) {
        cin >> bl[i];
        cin.clear();
    }
    return in;
}
ostream& operator << (ostream& out, const List& bl) {
    for(int i = 0;i < bl.GetLength(); ++i) {
        out << bl.p[i];
    }
    return out;
}
Book& List::operator[] (const int& index) {
    static Book data;
    if(index >=0 && index < this->length) {
        return *(this->p + index);
    } else {
        return data;
    }
}
