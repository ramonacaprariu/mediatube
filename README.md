# MediaTube

C++ application model with Channels, Media, searchable playlists, and simulated audio/video playback

## Demo
- Channels host Media items (audio-only or audio+video).
- Searches build a “current playlist” by **owner**, **category**.
- Playback can be toggled between:
  - **AudioPlayer**: prints audio text.
  - **VideoPlayer**: prints audio text + ASCII art read from a .txt file at runtime.
  
### Requirements
- `make`
- C++ compiler (`g++` or `clang++`)

### Compile

```bash
make
# or
make all
```

### External Libraries Used
- iostream
- fstream
- string
- iomanip
- fstream
