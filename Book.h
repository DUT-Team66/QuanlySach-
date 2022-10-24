#include <string>
using namespace std;
class Book {
    private:
        string bookID;
        string bookName;
        int publishingYear;
        int amount;
        bool status;
    public:
        Book();
        Book(string,string,int,int,bool);
        Book(const Book&);
        ~Book();
        const string& getBookID() const;
        void setBookID(const string&);
        const string& getBookName() const;
        void setBookName(const string&);
        const int& getPublishingYear() const;
        void setPublishingYear(const int&);
        const int& getAmount() const;
        void setAmount(const int&);
        const bool& getStatus() const;
        void setStatus(const bool&);
        friend istream& operator >> (istream&, Book&);
        friend ostream& operator << (ostream&, const Book&);
};

