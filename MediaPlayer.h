#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include "Media.h"
#include <fstream>

using namespace std;

class MediaPlayer {
    friend ostream& operator<<(const MediaPlayer& player, const Media& media);

    public:
    virtual void play(ostream& ost, const Media& m) const = 0;
};

class AudioPlayer : public virtual MediaPlayer {
    public:
    virtual void play(ostream& ost, const Media& m) const override;
};

class VideoPlayer : public AudioPlayer {
    public:
    virtual void play(ostream& ost, const Media& m) const override;
};


#endif