#include "mainwindow.h"

#include <QApplication>

#include <src/aobuilderimpl.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    ao_builder::AOBuilderImpl b;
    QStringList applications = b.getLocalAppsPaths();

    QStringList categories = b.getCategoriesList();

    QStringList legacyObject = b.getLegacyObjectsPaths();

    w.show();
    return a.exec();
}
