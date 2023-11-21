#include "mainwindow.h"

#include <QApplication>

#include <src/aobuilderimpl.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    ao_builder::AOBuilderImpl b;

    b.buildLocalApps();

    b.buildCategories();

    b.buildLegacyObject();

    w.show();
    return a.exec();
}
