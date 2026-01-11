#include "MediaPlayer.h"

ostream& operator <<(const MediaPlayer& player, const Media& media) {
    player.play(cout, media);
    return cout;
}

void AudioPlayer::play(ostream& ost, const Media& m) const {
    ost << m.getAudioContent() << endl;
}

void VideoPlayer::play(ostream& ost, const Media& m) const {
    // ost << m.getAudioContent() << endl;
    AudioPlayer::play(ost, m);

    ifstream infile(m.getVideoFile());
    if (!infile) {
        ost << "Error: could not open file" << endl;
        return;
      }
    
    string line;
    while (getline(infile, line)) {
        ost << line << endl;
    }

    infile.close();
}
