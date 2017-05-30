// класс отвечающий за сохранение настроек в текстовом редакторе

#ifndef MYPROGRAMM_H
#define MYPROGRAMM_H

#include <QWidget>
#include <QtWidgets>
#include <QSettings>

class QComboBox;
class QCheckBox;
class QTextEdit;
class QLabel;

class MyProgramm : public QWidget{
    Q_OBJECT

private:
    QSettings m_settings;
    QComboBox* m_pcbo;
    QCheckBox* m_pchk;
    QTextEdit* m_ptxt;
    QLabel* m_plbl;
    int m_nCounter;

public:
    MyProgramm(QWidget* wgt = 0);
    virtual ~MyProgramm();

    void writeSettings();
    void readSettings();

public slots:
    void slotCheckBoxClicked();
    void slotComboBoxActivated(int n);
};
#endif // MYPROGRAMM_H
