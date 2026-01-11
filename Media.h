#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Media {

    friend ostream& operator<<(ostream&, const Media&);

    public:
    Media(string channelTitle, string owner, string mediaTitle, string category,
        string audioContent, string videoFile);
    
    string getChannelTitle() const;
    string getOwner() const;
    string getMediaTitle() const;
    string getCategory() const;
    string getAudioContent() const;
    string getVideoFile() const;

    private:
    string channelTitle;
    string owner;
    string mediaTitle;
    string category;
    string audioContent;
    string videoFile;

};

#endif