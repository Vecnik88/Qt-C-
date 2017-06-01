#ifndef DOCWINDOW_H
#define DOCWINDOW_H

#include <QTextEdit>
#include <QFileDialog>
#include <QTextStream>

class QTextEdit;

class DocWindow: public QTextEdit{
    Q_OBJECT
private:
    QString m_strFileName;

public:
    DocWindow(QWidget* wg = 0);

signals:
    void changeWindowTitle(const QString&);

public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
};
#endif // DOCWINDOW_H
