#include "fileio.h"

FileIO::FileIO(QObject *parent)
    : QObject(parent),
      clr(0),
      sizeStr(0),
      sizeWords(0)
{
}

FileIO::~FileIO()
{
}

static void pause_one_second()
{
    // sleep one second
    QEventLoop loop;
    QTimer::singleShot(1000, &loop, SLOT(quit()));
    loop.exec();
}

void FileIO::clear()
{
    clr = 1;
}
void FileIO::read()
{
    if(m_source.isEmpty()) {
        return;
    }
    QFile file(m_source.toLocalFile());
    if(!file.exists()) {
        qWarning() << "Does not exits: " << m_source.toLocalFile();
        return;
    }
    if(file.open(QIODevice::ReadOnly)) {
        QString div = "(\\ |\\,|\\.|\\:|\\t|\\;|\\-)";
        QTextStream stream(&file);

        while(!stream.atEnd()) {
            if(clr) {
                uniqueWords.clear();
                setSizeWords(0);
                setSizeStr(0);
                clr = 0;
                file.close();
                break;
            }

            QStringList list = stream.readLine().split(QRegExp(div));
            ++sizeStr;
            emit strChanged(sizeStr);

            for (int i = 0; i < list.size(); ++i) {
                uniqueWords.insert(list.at(i));
                sizeWords = uniqueWords.size();
                emit wordsChanged(sizeWords);
            }
            pause_one_second();
        }
    }
    file.close();
}

QUrl FileIO::source() const
{
    return m_source;
}

void FileIO::setSource(QUrl source)
{
    if (m_source == source)
        return;

    m_source = source;
    emit sourceChanged(source);
}

int FileIO::words() const
{
    return sizeWords;
}

void FileIO::setSizeWords(int arg)
{
    sizeWords = arg;
    emit wordsChanged(sizeWords);
}

int FileIO::str() const
{
    return sizeStr;
}

void FileIO::setSizeStr(int val)
{
    sizeStr = val;
    emit strChanged(sizeStr);
}
