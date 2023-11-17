#ifndef DATASOURCEDBUSIMPL_H
#define DATASOURCEDBUSIMPL_H

#include "datasourceinterface.h"

#include <QString>

namespace ao_builder
{
class DataSourseDbusImplPrivate;

class DataSourceDbusImpl : public DataSourceInterface
{
public:
    DataSourceDbusImpl(QString serviceName);
    ~DataSourceDbusImpl();

private:
    DataSourseDbusImplPrivate *d;

private:
    DataSourceDbusImpl(const DataSourceDbusImpl &) = delete;
    DataSourceDbusImpl(DataSourceDbusImpl &&)      = delete;
    DataSourceDbusImpl &operator=(const DataSourceDbusImpl &) = delete;
    DataSourceDbusImpl &operator=(DataSourceDbusImpl &&) = delete;

    // DataSourceInterface interface
public:
    QStringList getPathByInterface(QString iface);
    QByteArray getObjectInfo(QString iface, QString path, QString method);
};

} // namespace ao_builder

#endif // DATASOURCEDBUSIMPL_H
