#include <QtWidgets>
#include <QVideoWidget>
#include <videoplayer.h>

VideoPlayer::VideoPlayer(QWidget* wgt):SoundPlayer(wgt){
    
    QVideoWidget* pvw = new QVideoWidget;
    pvw->setMinimumSize(250,250);
    m_pvbxMainLayout->addWidget(pvw);
    m_pmp->setVideoOutput(pvw);   
}

