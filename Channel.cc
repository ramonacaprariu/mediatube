#include "Channel.h"

ostream& operator<<(ostream& output, const Channel& c) {
    c.print(output);
    return output;
}

Channel::Channel(const string& title, const string& owner) {
    this->title = title;
    this->owner = owner;
}

Channel::~Channel() {
    for (int i = 0; i < arr.getSize(); ++i) {
        delete arr[i];
    }
}

bool Channel::equals(const string& title) const {
    return (this->title == title); 
}

Media* Channel::get(int index) {
    if (index < 0 || index >= arr.getSize()) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}

    return arr[index];
}

int Channel::getSize() const {
    return arr.getSize();
}

void Channel::print(ostream& output) const {
    output << "Title:   " << title << endl;
    output << "Owner:   " << owner << endl;
}
void Channel::printWithMedia(ostream& output) const {
    print(output);
    for (int i = 0; i < arr.getSize(); i++) {
        // output << arr[i] << endl; 
        output << *arr[i] << endl; 
    }
}

void Channel::add(Media* m) {
    if (arr.isFull()) {
        return;
    }
    arr+=m;
}
