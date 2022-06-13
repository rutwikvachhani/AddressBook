
#include <iostream>
#include <string>
#include <iterator>
#include <list>
#include <algorithm>

#pragma once

using namespace std;

class Node
{
public:
    //Node();
    Node(string f="", string l="", string p="")
    {
        fn = f;
        ln = l;
        pn = p;
    }
    ~Node(){}

    bool operator <(const Node & entry) const
    {
        return fn < entry.fn;
    }

    bool operator ==(const Node & entry) const
    {
        if(fn==entry.fn)
            if(ln==entry.ln)
                return true;
        return false;
    }

    void Print()
    {
        cout << fn << ", " << ln << " : " << pn << endl;
    }

    string fn;
    string ln;
    string pn;
};


class AddressBook
{
public:
    AddressBook(){}
    ~AddressBook(){}

    int Add(string, string, string);
    int Remove(string, string);
    int SortbyFn();
    int SortbyLn();
    void SearchbyFn(string);
    void SearchbyLn(string);
    int Print();

private:
    list<Node> AddBook;
};

