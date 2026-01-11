#ifndef CHANNEL_H
#define CHANNEL_H

#include "Array.h"
#include "Media.h"

using namespace std;

class Channel {
    friend ostream& operator<<(ostream&, const Channel&);

    public:
    Channel(const string& title, const string& owner);
    ~Channel();

    bool equals(const string& title) const;
    Media* get(int index);
    int getSize() const;
    void print(ostream&) const;
    void printWithMedia(ostream&) const;
    void add(Media*);


    private:
    Array<Media*> arr; //Array of Media pointers
    string title;
    string owner;
};

#endif