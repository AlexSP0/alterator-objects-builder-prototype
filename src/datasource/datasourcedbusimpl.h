#ifndef DATASOURCEDBUSIMPL_H
#define DATASOURCEDBUSIMPL_H

#include "datasourceinterface.h"

#include <QString>

namespace ao_builder
{
class DataSourseDbusImplPrivate;

class DataSourceDBusImpl : public DataSourceInterface
{
public:
    DataSourceDBusImpl(QString serviceName);
    ~DataSourceDBusImpl();

public:
    QStringList getLocalAppPaths() override;
    QStringList getCategoriesList() override;
    QStringList getLegacyObjectsPaths() override;
    QStringList getObjectsPath() override;

    QByteArray getObjectInfo(QString ifaceName, QString path, QString methodName) override;

private:
    QStringList getPathsByInterface(QString ifaceName);
    QStringList getObjectsList(QString listMethodName, QString path, QString interfaceName);

private:
    DataSourseDbusImplPrivate *d;

private:
    DataSourceDBusImpl(const DataSourceDBusImpl &) = delete;
    DataSourceDBusImpl(DataSourceDBusImpl &&)      = delete;
    DataSourceDBusImpl &operator=(const DataSourceDBusImpl &) = delete;
    DataSourceDBusImpl &operator=(DataSourceDBusImpl &&) = delete;
};

} // namespace ao_builder

#endif // DATASOURCEDBUSIMPL_H
