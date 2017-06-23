#include <qtestimage.h>

QTestImage::QTestImage(QWidget* wgt):QWidget(wgt){          // <---. Constructor
    pix = QPixmap("D://TestGit/untitled121/fr.png");

    pcmd1 = new QPushButton;
    pcmd1->setIcon(pix);
    pcmd1->setIconSize(pix.size());
    pcmd1->setStyleSheet("QPushButton:pressed {background-color: green; border:none;}");

    pcmd2 = new QPushButton;
    pcmd2->setIcon(pix);
    pcmd2->setIconSize(pix.size());
    pcmd2->setStyleSheet("QPushButton:hover{background: green; border:none;}");

    // Устанавливаем слои
    QVBoxLayout* vbxButton = new QVBoxLayout;
    vbxButton->addWidget(pcmd1);
    vbxButton->addWidget(pcmd2);
    setLayout(vbxButton);

    // соединяем кнопки со со слотами
   // connect(pcmd1, SIGNAL(clicked()), this, SLOT(slotButtonClickedGreen()));
}

QTestImage::~QTestImage(){}                                 // <---. Деструктор

/*void QTestImage::slotButtonClickedGreen(){
   //pcmd1->setStyleSheet("QPushButton:hover{background: green; border:none;}");
}*/
