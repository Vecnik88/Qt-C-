#include "inputdialog.h"

InputDialog::InputDialog(QWidget* wgt):QDialog(wgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint){
    m_ptxtFirstName = new QLineEdit;
    m_ptxtLastName = new QLineEdit;

    QLabel* plblFirstName = new QLabel("First Name: ");
    QLabel* plblLastName = new QLabel("Last Name: ");

    plblFirstName->setBuddy(m_ptxtFirstName);
    plblLastName->setBuddy(m_ptxtLastName);

    QPushButton* pcmdOK = new QPushButton("&OK");
    QPushButton* pcmdCancel = new QPushButton("&Cancel");

    connect(pcmdOK, SIGNAL(clicked()), SLOT(accept()));
    connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));

    // слои
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblFirstName, 0, 0);
    ptopLayout->addWidget(plblLastName, 1, 0);
    ptopLayout->addWidget(m_ptxtFirstName, 0, 1);
    ptopLayout->addWidget(m_ptxtLastName, 1, 1);
    ptopLayout->addWidget(pcmdOK, 2, 0);
    ptopLayout->addWidget(pcmdCancel, 2, 1);
    setLayout(ptopLayout);
}

QString InputDialog::firstName() const{
    return m_ptxtFirstName->text();
}

QString InputDialog::lastName() const{
    return m_ptxtLastName->text();
}
