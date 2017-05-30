#include <myprogramm.h>

MyProgramm::MyProgramm(QWidget* wgt):QWidget(wgt), m_settings("BHV", "MyProgramm"){
    m_plbl = new QLabel;
    m_ptxt = new QTextEdit;
    m_pcbo = new QComboBox;
    m_pchk = new QCheckBox("Disable edit");

    m_pcbo->addItem("Classik");
    m_pcbo->addItem("Borland");

    connect(m_pchk, SIGNAL(clicked()), SLOT(slotCheckBoxClicked()));
    connect(m_pcbo, SIGNAL(activated(int)), SLOT(slotComboBoxActivated(int)));
    readSettings();

    // слои
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    pvbxLayout->setMargin(5);
    pvbxLayout->setSpacing(15);
    phbxLayout->setSpacing(15);

    pvbxLayout->addWidget(m_plbl);
    pvbxLayout->addWidget(m_ptxt);

    phbxLayout->addWidget(m_pcbo);
    phbxLayout->addWidget(m_pchk);

    pvbxLayout->addLayout(phbxLayout);
    setLayout(pvbxLayout);
}

void MyProgramm::readSettings(){
    m_settings.beginGroup("/Settings");

    QString strText = m_settings.value("/text", "").toString();
    int nWidth = m_settings.value("/width", width()).toInt();
    int nHeight = m_settings.value("/height", height()).toInt();
    int nComboItem = m_settings.value("/highlight", 0).toInt();
    bool bEdit = m_settings.value("/edit", false).toBool();

    m_nCounter = m_settings.value("/counter", 1).toInt();

    QString str = QString().setNum(m_nCounter++);
    m_plbl->setText("This programm has been started " + str + " times");
    m_ptxt->setPlainText(strText);
    resize(nWidth, nHeight);

    m_pchk->setChecked(bEdit);
    slotCheckBoxClicked();

    m_pcbo->setCurrentIndex(nComboItem);
    slotComboBoxActivated(nComboItem);

    m_settings.endGroup();
}

MyProgramm::~MyProgramm(){
    writeSettings();
}

void MyProgramm::writeSettings(){
    m_settings.beginGroup("Settings");
    m_settings.setValue("/counter", m_nCounter);
    m_settings.setValue("/text", m_ptxt->toPlainText());
    m_settings.setValue("/width", width());
    m_settings.setValue("/height", height());
    m_settings.setValue("/highlight", m_pcbo->currentIndex());
    m_settings.setValue("/edit", m_pchk->isChecked());
    m_settings.endGroup();
}

void MyProgramm::slotCheckBoxClicked(){
    m_ptxt->setEnabled(!m_pchk->isChecked());
}

void MyProgramm::slotComboBoxActivated(int n){
    QPalette pal = m_ptxt->palette();
    pal.setColor(QPalette::Active, QPalette::Base,
                 n ? Qt::darkBlue : Qt::white);
    pal.setColor(QPalette::Active, QPalette::Text,
                 n ? Qt::yellow : Qt::black);

    m_ptxt->setPalette(pal);
}
