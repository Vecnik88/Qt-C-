#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QFileSystemModel model;
    QTreeView pTreeView;

    model.setRootPath(QDir::rootPath());
    pTreeView.setModel(&model);
    pTreeView.show();

    return app.exec();
}
