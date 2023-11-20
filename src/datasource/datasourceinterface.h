#ifndef AOB_DATA_SOURCE_INTERFACE_H
#define AOB_DATA_SOURCE_INTERFACE_H

#include <QByteArray>
#include <QString>

#include "constants.h"

namespace ao_builder
{
class DataSourceInterface
{
public:
    virtual ~DataSourceInterface() = default;

    virtual QStringList getLocalAppPaths()      = 0;
    virtual QStringList getCategoriesList()     = 0;
    virtual QStringList getLegacyObjectsPaths() = 0;
    virtual QStringList getObjectsPath()        = 0;

    virtual QByteArray getObjectInfo(QString iface, QString path, QString method) = 0;
};

} // namespace ao_builder
#endif // AOB_DATA_SOURCE_INTERFACE_H
