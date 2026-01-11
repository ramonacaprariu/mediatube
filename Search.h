#ifndef SEARCH_H
#define SEARCH_H

#include "Media.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Search {
    friend ostream& operator<<(ostream&, const Search&);
    
    //pure virtual functions
    public:
    virtual ~Search() {}
    
    virtual void print(ostream&) const = 0;
    virtual bool matches(const Media*) const = 0;
};

class O_Search : public virtual Search {
    public:
    O_Search(const string& owner);

    virtual bool matches(const Media*) const override;
    virtual void print(ostream&) const override;

    protected:
    string owner;
};

class C_Search : public virtual Search {
    public:
    C_Search(const string& category);

    virtual bool matches(const Media*) const override;
    virtual void print(ostream&) const override;

    protected:
    string category;
};

class OorC_Search : public O_Search, public C_Search {
    public:
    OorC_Search(const string& owner, const string& category);
    
    virtual bool matches(const Media*) const override;
    virtual void print(ostream&) const override;
};

#endif