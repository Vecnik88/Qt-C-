#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <soundplayer.h>

class VideoPlayer : public SoundPlayer{
    Q_OBJECT

public:
    VideoPlayer(QWidget* wgt = 0);
};
#endif // VIDEOPLAYER_H
