#include "rs_demo_gdal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RS_DEMO_GDAL w;
    w.show();

    return a.exec();
}
