#ifndef MEDIATUBE_H
#define MEDIATUBE_H

using namespace std;

#include "Array.h"
#include "Channel.h"
#include "Media.h"
#include "Search.h"

class MediaTube {
    public:
    ~MediaTube();

    void addChannel(Channel* channel);
    void addMedia(Media* media, const string& channelTitle);
    const Array<Channel*>& getChannels() const;

    Channel* getChannel(int index);
    Channel* getChannel(const string& title);

    void getMedia(const Search& search, Array<Media*>& mediaArr);

    private:
    Array<Channel*> channelArr;
};

#endif