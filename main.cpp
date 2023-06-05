#include "QtWidgetsCarsPropViewer.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsCarsPropViewer w;
    w.show();
    return a.exec();
}
