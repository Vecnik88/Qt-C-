// created by Vecnik88
// Videoplayer

#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QMediaPlayer>
#include <QtWidgets>

class QPushButton;
class QSlider;
class QLabel;
class QVBOXLayout;
class QHBoxLayout;
class QWidget;

class SoundPlayer : public QWidget{
    Q_OBJECT
protected:
    QMediaPlayer* m_pmp;
    QVBoxLayout* m_pvbxMainLayout;
private:
    QPushButton* m_pcmdPlay;
    QPushButton* m_pcmdStop;
    QSlider* m_psldPosition;
    QLabel* m_plblCurrent;
    QLabel* m_plblRemain;
    QString msecsToString(qint64 n);
public:
    SoundPlayer(QWidget* pwgt = 0);
private slots:
    void slotOpen();
    void slotPlay();
    void slotSetSliderPosition(qint64);
    void slotSetMediaPosition(int);
    void slotSetDuration(qint64);
    void slotStatusChanged(QMediaPlayer::State);
};
#endif // SOUNDPLAYER_H
