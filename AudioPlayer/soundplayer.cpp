#include <soundplayer.h>

SoundPlayer::SoundPlayer(QWidget* pwgt) : QWidget(pwgt){
    QPushButton* pcmdOpen = new QPushButton("&Open");
    QSlider* psldVolume = new QSlider;

    m_pcmdPlay = new QPushButton;
    m_pcmdStop = new QPushButton;
    m_psldPosition = new QSlider;
    m_plblCurrent = new QLabel(msecsToString(0));
    m_plblRemain = new QLabel(msecsToString(0));
    m_pmp = new QMediaPlayer;
    m_pcmdPlay->setEnabled(false);
    m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    m_pcmdStop->setEnabled(false);
    m_pcmdStop->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    m_psldPosition->setRange(0,0);
    m_psldPosition->setOrientation(Qt::Horizontal);
    psldVolume->setRange(0,100);
    int nDefaultVolume = 50;
    m_pmp->setVolume(nDefaultVolume);

    // connect
    connect(pcmdOpen, SIGNAL(clicked()), SLOT(slotOpen()));
    connect(m_pcmdPlay, SIGNAL(clicked()), SLOT(slotPlay()));
    connect(m_pcmdStop, SIGNAL(clicked()), m_pmp, SLOT(stop()));
    connect(psldVolume, SIGNAL(valueChanged(int)), m_pmp, SLOT(setVolume(int)));
    connect(m_psldPosition, SIGNAL(sliderMoved(int)), SLOT(slotSetMediaPosition(int)));
    connect(m_pmp, SIGNAL(positionChanged(qint64)), SLOT(slotSetSliderPosition(qint64)));
    connect(m_pmp, SIGNAL(durationChanged(qint64)), SLOT(slotSetDuration(qint64)));
    connect(m_pmp, SIGNAL(stateChanged(QMediaPlayer::State)), SLOT(slotStatusChanged(QMediaPlayer::State)));

    // Layout
    QHBoxLayout* phbxPlayControls = new QHBoxLayout;
    phbxPlayControls->addWidget(pcmdOpen);
    phbxPlayControls->addWidget(m_pcmdPlay);
    phbxPlayControls->addWidget(m_pcmdStop);
    phbxPlayControls->addWidget(psldVolume);

    QHBoxLayout* phbxTimeControls = new QHBoxLayout;
    phbxTimeControls->addWidget(m_plblCurrent);
    phbxTimeControls->addWidget(m_psldPosition);
    phbxTimeControls->addWidget(m_plblRemain);

    m_pvbxMainLayout = new QVBoxLayout;
    m_pvbxMainLayout->addLayout(phbxPlayControls);
    m_pvbxMainLayout->addLayout(phbxTimeControls);

    setLayout(m_pvbxMainLayout);
}

void SoundPlayer::slotOpen(){// <---. открывает файл
    QString strFile = QFileDialog::getOpenFileName(this, "Open file");
    if(!strFile.isEmpty()){
        m_pmp->setMedia(QUrl::fromLocalFile(strFile));
        m_pcmdPlay->setEnabled(true);
        m_pcmdStop->setEnabled(true);
    }
}

void SoundPlayer::slotPlay(){// <---. играть
    switch(m_pmp->state()){
    case QMediaPlayer::PlayingState:
        m_pmp->pause();
        break;

    default:
        m_pmp->play();
        break;
    }
}

void SoundPlayer::slotStatusChanged(QMediaPlayer::State state){
    switch(state){
    case QMediaPlayer::PlayingState:
        m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;

    default:
        m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}

void SoundPlayer::slotSetMediaPosition(int n){
    m_pmp->setPosition(n);
}

QString SoundPlayer::msecsToString(qint64 n){
    int nHours = (n/(60*60*1000));
    int nMinute = ((n%(60*60*100))/(60*1000));
    int nSecond = (n%(60*1000))/1000;

    return QTime(nHours, nMinute, nSecond).toString("hh:mm:ss");
}

void SoundPlayer::slotSetDuration(qint64 n){
    m_psldPosition->setRange(0, n);
    m_plblCurrent->setText(msecsToString(0));
    m_plblRemain->setText(msecsToString(n));
}

void SoundPlayer::slotSetSliderPosition(qint64 n){
    m_psldPosition->setValue(n);
    m_plblCurrent->setText(msecsToString(n));
    int nDuration = m_psldPosition->maximum();
    m_plblRemain->setText(msecsToString(nDuration-n));
}
