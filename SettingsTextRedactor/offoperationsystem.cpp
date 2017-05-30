#include <offoperationsystem.h>

OffOperationSystem::OffOperationSystem(int argc, char** argv):QApplication(argc, argv){}

OffOperationSystem::~OffOperationSystem(){}

void OffOperationSystem::commitData(QSessionManager& sm){
    QMessageBox::information(0, "Dialog", "You are exiting operating system");
}

void OffOperationSystem::saveStateRequest(QSessionManager &sm){}
