#include "Book.h"  

class List {
    private:
        Book* p;
        int length;
    public:
        List();
        ~List();
        const int& GetLength() const;
        void SetLength(const int&);
        void Show();
        void Add(const Book&,int);
        void Update(string);
        void Delete(int);
        void Search(int); // Search by publishing year
        void Sort(bool(int,int)); // Sort by publishing year

        friend istream& operator >> (istream&, List&);
        friend ostream& operator << (ostream&, const List&);
        Book& operator [] (const int&);
        
};