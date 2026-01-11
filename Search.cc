#include "Search.h"

ostream& operator<<(ostream& output, const Search& s) {
    s.print(output);
    return output;
}

//constructors
O_Search::O_Search(const string& owner) {
    this->owner = owner;
}
C_Search::C_Search(const string& category) {
    this->category = category;
}
OorC_Search::OorC_Search(const string& owner, const string& category) 
    : O_Search(owner), C_Search(category) {}

//matches functions
bool O_Search::matches(const Media* m) const {
    return (m->getOwner() == this->owner);
}
bool C_Search::matches(const Media* m) const {
    return (m->getCategory() == this->category);
}
bool OorC_Search::matches(const Media* m) const {
    return (O_Search::matches(m) || C_Search::matches(m));
}

//print functions
void O_Search::print(ostream& output) const {
    output << "Match with Media owner: " << owner << endl;
}
void C_Search::print(ostream& output) const {
    output << "Match with Media category: " << category << endl;
}
void OorC_Search::print(ostream& output) const {
    output << "Match with Media owner: " << owner << " or category: " 
        << category << endl;
}

// virtual void print(ostream& os) const { 
//     os<< "-- chicken "<<name<<" says cluck-cluck!"<<endl; 
// }
// bool Book::operator!=(Book& b) {
//   return ( title != b.title || author != b.author );
// }