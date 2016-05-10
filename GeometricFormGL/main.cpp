#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    my3Dscene w;
    w.show();

    return a.exec();
}
