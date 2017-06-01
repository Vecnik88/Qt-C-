#ifndef MDIPROGRAMM_H
#define MDIPROGRAMM_H

#include <docwindow.h>
#include <QMainWindow>
#include <QtWidgets>
#include <QWidget>
#include <QToolBar>
#include <QMdiArea>

class QMenu;
class QMdiArea;
class QSignalMapper;
class DocWindow;
class QAction;
class QToolBar;
class QMdiArea;

class MDIProgramm : public QMainWindow{
    Q_OBJECT
private:
    QMdiArea* m_pma;
    QMenu* m_pmnuWindows;
    QSignalMapper* m_psigMapper;

    DocWindow* createNewDoc();

public:
    MDIProgramm(QWidget* wgt = 0);

private slots:
    void slotChangeWindowTitle(const QString&);

public slots:
    void slotNewDoc();
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotAbout();
    void slotWindows();
    void slotSetActiveSubWindow(QWidget*);
};
#endif // MDIPROGRAMM_H
