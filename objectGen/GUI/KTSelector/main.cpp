#include <QtGui/QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    if( argc > 1 )
      w.setInputFile(argv[1]);
    w.show();

    return a.exec();
}
