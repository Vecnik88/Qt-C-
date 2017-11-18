#ifndef FILEIO_H
#define FILEIO_H

#include <QtCore>

class FileIO : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(FileIO)

    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(int str READ str WRITE setSizeStr NOTIFY strChanged)
    Q_PROPERTY(int words READ words WRITE setSizeWords NOTIFY wordsChanged)
public:
    FileIO(QObject *parent = 0);
    ~FileIO();

    Q_INVOKABLE void read();
    Q_INVOKABLE void clear();

    QUrl source() const;
    int str() const;
    int words() const;

public slots:
    void setSource(QUrl source);
    void setSizeStr(int arg);
    void setSizeWords(int arg);

signals:
    void sourceChanged(QUrl arg);
    void wordsChanged(int arg);
    void strChanged(int arg);

private:
    QUrl m_source;
    QSet<QString> uniqueWords;
    int sizeStr;
    int sizeWords;
    int clr;
};

#endif // FILEIO_H
