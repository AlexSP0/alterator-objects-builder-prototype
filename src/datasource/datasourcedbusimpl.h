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

public:
    QStringList getPathByInterface(QString ifaceName);
    QByteArray getObjectInfo(QString ifaceName, QString path, QString methodName);

private:
    DataSourseDbusImplPrivate *d;

private:
    DataSourceDbusImpl(const DataSourceDbusImpl &) = delete;
    DataSourceDbusImpl(DataSourceDbusImpl &&)      = delete;
    DataSourceDbusImpl &operator=(const DataSourceDbusImpl &) = delete;
    DataSourceDbusImpl &operator=(DataSourceDbusImpl &&) = delete;
};

} // namespace ao_builder

#endif // DATASOURCEDBUSIMPL_H
