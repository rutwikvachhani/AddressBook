
#include "AddressBook.h"

int AddressBook::Add(string fn, string ln, string pn)
{
    Node* temp = new Node;
    temp->fn = fn;
    temp->ln = ln;
    temp->pn = pn;
    AddBook.push_back(*temp);
    cout << endl << fn << " " << ln << " Added" << endl;
    return 0;
}

int AddressBook::Remove(string f, string l)
{
    for (std::list<Node>::iterator itr = AddBook.begin(); itr != AddBook.end(); itr++)
    {
        if(!itr->fn.compare(f))
            if(!itr->ln.compare(l))
            {
                AddBook.erase(itr);
                cout << endl << f << " " << l << " Removed" << endl;
                return 0;
            }
    }
    return 1;
}

struct FnComparator
{
    // Compare 2 entries using First Name
    bool operator ()(const Node & entry1, const Node & entry2)
    {
        if( entry1.fn == entry2.fn )
            return entry1 < entry2;
        return entry1.fn < entry2.fn;
    }
};

int AddressBook::SortbyFn()
{
    AddBook.sort(FnComparator());
    cout << endl << "Sorted by First Name..." << endl;
    return 1;
}

struct LnComparator
{
    // Compare 2 entries using Last Name
    bool operator ()(const Node & entry1, const Node & entry2)
    {
        if( entry1.ln == entry2.ln )
            return entry1 < entry2;
        return entry1.ln < entry2.ln;
    }
};

int AddressBook::SortbyLn()
{
    AddBook.sort(LnComparator());
    cout << endl << "Sorted by Last Name..." << endl;
    return 1;
}

void AddressBook::SearchbyFn(string f)
{
    cout << endl << "=====START_OF_SEARCH====" << endl;
    string str = "";
    transform(f.begin(), f.end(), f.begin(), ::tolower);
    for (std::list<Node>::iterator itr = AddBook.begin(); itr != AddBook.end(); itr++)
    {
        str = itr->fn;
        transform(itr->fn.begin(), itr->fn.end(), str.begin(), ::tolower);
        if(str.rfind(f,0)==0)
            cout << itr->fn << ", " << itr->ln << " : " << itr->pn << endl;
    }
    cout << "======END_OF_SEARCH=====" << endl;
}

void AddressBook::SearchbyLn(string l)
{
    cout << endl << "=====START_OF_SEARCH====" << endl;
    string str = "";
    transform(l.begin(), l.end(), l.begin(), ::tolower);
    for (std::list<Node>::iterator itr = AddBook.begin(); itr != AddBook.end(); itr++)
    {
        str = itr->ln;
        transform(itr->ln.begin(), itr->ln.end(), str.begin(), ::tolower);
        if(str.rfind(l,0)==0)
            cout << itr->fn << ", " << itr->ln << " : " << itr->pn << endl;
    }
    cout << "======END_OF_SEARCH=====" << endl;
}

int AddressBook::Print()
{
    cout << endl << "=====START_OF_ADDRESSBOOK====" << endl;
    for (std::list<Node>::iterator itr = AddBook.begin(); itr != AddBook.end(); itr++)
    {
        cout << itr->fn << ", " << itr->ln << " : " << itr->pn << endl;
    }
    cout << "======START_OF_ADDRESSBOOK=====" << endl;
    return 1;
}

int main()
{
    //cout << "Address Book App Start" << endl;

    AddressBook AB;

    AB.Add("John","Smith","1111111111");
    AB.Add("Rutwik","Vachhani","2222222222");
    AB.Add("ABC","XYZ","3333333333");
    AB.Add("ABCD","DDD","5555555555");
    AB.Add("ABCDE","EEE","6666666666");
    AB.Add("PQR","STU","4444444444");
    AB.Add("PQR","","7777777777");      // Last Name not provided
    AB.Add("PQR","","");      // Phone Number not provided
    AB.Print();


    AB.SortbyFn();
    AB.Print();
    
    AB.SortbyLn();
    AB.Print();


    AB.SearchbyFn("P");      // Upper Case First Name
    AB.SearchbyFn("p");      // Lower Case First Name

    AB.SearchbyFn("pqr");
    AB.SearchbyFn("PQ");

    AB.SearchbyFn("a");
    AB.SearchbyFn("AB");

    AB.SearchbyFn("R");

    AB.SearchbyLn("S");      // Upper Case Last Name
    AB.SearchbyLn("s");      // Lower Case Last Name
    AB.SearchbyLn("v");
    
    AB.Remove("ABCDE","EEE");
    AB.Print();

    AB.Remove("PQR","");    //TODO : Which PQR will be removed? with number or without number, why not both ?
    AB.Print();

    AB.Remove("PQR","");
    AB.Print();

    //cout << "Address Book App End" << endl;
    return 0;
}