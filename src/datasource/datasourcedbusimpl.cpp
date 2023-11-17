#include "datasourcedbusimpl.h"

#include <QDBusConnection>
#include <QDBusInterface>
#include <QDBusReply>

namespace ao_builder
{
class DataSourseDbusImplPrivate
{
public:
    DataSourseDbusImplPrivate(QString serviceName)
        : m_serviceName(serviceName)
        , m_dbusConnection(QDBusConnection::systemBus())
    {}

    QString m_serviceName;
    QDBusConnection m_dbusConnection;
};

DataSourceDbusImpl::DataSourceDbusImpl(QString serviceName)
    : d(new DataSourseDbusImplPrivate(serviceName))
{}

DataSourceDbusImpl::~DataSourceDbusImpl()
{
    delete d;
}

QStringList DataSourceDbusImpl::getPathByInterface(QString iface)
{
    return QStringList{};
}

QByteArray DataSourceDbusImpl::getObjectInfo(QString iface, QString path, QString method)
{
    return QByteArray{};
}

} // namespace ao_builder
