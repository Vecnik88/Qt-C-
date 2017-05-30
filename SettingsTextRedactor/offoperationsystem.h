// выключение операционной системы юез закрытия программы - предупредит

#ifndef OFFOPERATIONSYSTEM_H
#define OFFOPERATIONSYSTEM_H

#include <QtWidgets>
class QSessionManager;

class OffOperationSystem : public QApplication{
    Q_OBJECT
public:
    OffOperationSystem(int argc, char** argv);
    virtual ~OffOperationSystem();

    virtual void commitData(QSessionManager& sm);
    virtual void saveStateRequest(QSessionManager& sm);
};
#endif // OFFOPERATIONSYSTEM_H
