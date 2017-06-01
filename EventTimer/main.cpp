// created by Vecnik88
// мигающая надпись, эксперименты с событиями таймера

#include <QApplication>
#include <QtWidgets>

class BlinkLabel : public QLabel{
private:
    bool m_bBlink;
    QString m_strText;
protected:
    virtual void timerEvent(QTimerEvent*){
        m_bBlink = !m_bBlink;
        setText(m_bBlink ? m_strText : "");
    }
public:
    BlinkLabel(const QString& strText, int nInterval = 200, QWidget* wgt = 0)
        :QLabel(strText, wgt), m_bBlink(true), m_strText(strText){
        startTimer(nInterval);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BlinkLabel lbl("Hello world");
    lbl.resize(200, 200);
    lbl.show();

    return a.exec();
}
