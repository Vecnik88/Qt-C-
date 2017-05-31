#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QtWidgets>
#include "InputDialog.h"

class QPushButton;

class StartDialog : public QPushButton{
    Q_OBJECT
public:
    StartDialog(QWidget* wgt = 0):QPushButton("Press me", wgt){
        connect(this, SIGNAL(clicked()), SLOT(slotButtoClicked()));
    }
public slots:
    void slotButtoClicked(){
        InputDialog* pInputDialog = new InputDialog;
        if(pInputDialog->exec() == QDialog::Accepted){
            QMessageBox::information(0, "Information", "First name: " + \
                                     pInputDialog->firstName() + "\nLast name: " + pInputDialog->lastName());
        }
        delete pInputDialog;
    }
};
#endif // STARTDIALOG_H
