#include <iostream>
#include <iomanip>
#include "List.h"
using namespace std;
bool ascending(int x, int y) {
    return x > y;
}
bool descending(int x, int y) {
    return x < y;
}
int main()
{
    List bookList;
    while(true) {
        system("cls");
        
        cout << setw(25) << "" << "QUAN LY SACH\n"
        << setw(15) << "" << "1. Hien thi danh sach sach\n"
        << setw(15) << "" << "2. Them sach\n"
        << setw(15) << "" << "3. Cap nhat sach\n"
        << setw(15) << "" << "4. Xoa sach\n"
        << setw(15) << "" << "5. Tim kiem sach\n"
        << setw(15) << "" << "6. Sap xep theo ngay xuat ban\n"
        << setw(15) << "" << "7. Thoat\n";
        cout << "Nhap lua chon: ";
        int choice; cin >> choice;
        switch (choice)
        {
            //Show
            case 1: { 
                bookList.Show();
                break;
            }

            //Add
            case 2 :{
                Book b;
                cin >> b;
                cin.clear();
                cout << "Nhap vi tri can them: ";
                int index; cin >> index;
                bookList.Add(b,index);
                break;
            }

            //Update
            case 3: {
                cout << "Nhap ma sach can cap nhat: ";
                string id; cin >> id; cin.ignore();   
                bookList.Update(id);
                break;    
            }

            //Delete
            case 4 : {
                cout << "Nhap vi tri can xoa: ";
                int index; cin >> index;
                bookList.Delete(index);
                break;
            }

            //Search
            case 5: {
                cout << "Nhap nam xuat ban sach can tim kiem: ";
                int year; cin >> year;
                bookList.Search(year);
                break;
            }

            //Sort
            case 6 : {
                cout << "1. Cu nhat\n2. Moi nhat\n";
                cout << "Nhap lua chon: ";
                int t; cin >> t;
                if(t == 1) bookList.Sort(ascending);
                else if(t == 2) bookList.Sort(descending);
                else cout << "Lua chon khong hop le" << endl;
                break;
            }
            default:
                return 0;
        }
        system("pause");
    }
    

}