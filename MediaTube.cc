#include "MediaTube.h"


MediaTube::~MediaTube() {
    for (int i = 0; i < channelArr.getSize(); ++i) {
        delete channelArr[i];
    }
}

void MediaTube::addChannel(Channel* channel) {
    if (channelArr.isFull()) {
        return;
    }
    channelArr+=channel;
}

void MediaTube::addMedia(Media* media, const string& channelTitle) {
    for (int i = 0; i < channelArr.getSize(); i++) {
        if (channelArr[i]->equals(channelTitle)) {
            channelArr[i]->add(media);
            return;
        }
    }
    cout << "Error: Channel does not exist" << endl;
}

const Array<Channel*>& MediaTube::getChannels() const {
    return channelArr;
}

Channel* MediaTube::getChannel(int index) {
    if (index < 0 || index >= channelArr.getSize()) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
    return channelArr[index];
}
Channel* MediaTube::getChannel(const string& title) {
    for (int i = 0; i < channelArr.getSize(); i++) {
        if (channelArr[i]->equals(title)) {
            return channelArr[i];
        }
    }
    cout << "Error: Channel does not exist" << endl;
    exit(1);
}

void MediaTube::getMedia(const Search& search, Array<Media*>& mediaArr) {
    //for all the channels in channelArr:
    for (int i = 0; i < channelArr.getSize(); i++) {
        Channel* c = channelArr[i];
        //for all the media in each channel:
        for (int j = 0; j < c->getSize(); j++) {
            Media* m = c->get(j);
            if (search.matches(m)) {
                if (!mediaArr.isFull()) {
                    mediaArr+=m;
                }
            }
        }
    }
}
