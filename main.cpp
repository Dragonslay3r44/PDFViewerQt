#include "pdfviewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pdfviewer w;
    w.show();
    return a.exec();
}
