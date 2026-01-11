#include "Media.h" 

Media::Media(string channelTitle, string owner, string mediaTitle, string category,
    string audioContent, string videoFile) {
    this->channelTitle = channelTitle;
    this->owner = owner;
    this->mediaTitle = mediaTitle;
    this->category = category;
    this->audioContent = audioContent;
    this->videoFile = videoFile;
}

string Media::getChannelTitle() const {
    return channelTitle;
}
string Media::getOwner() const {
    return owner;
}
string Media::getMediaTitle() const {
    return mediaTitle;
}
string Media::getCategory() const {
    return category;
}
string Media::getAudioContent() const {
    return audioContent;
}
string Media::getVideoFile() const {
    return videoFile;
}

ostream& operator<<(ostream& output, const Media& m) {
  output<< "Title:       " << m.channelTitle << endl
        << "Owner:       " << m.owner << endl
        << "Category:    " << m.category << endl
        << "Media Title: " << m.mediaTitle << endl;
  return output;
}