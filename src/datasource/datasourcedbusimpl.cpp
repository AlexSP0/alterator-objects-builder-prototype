#include "datasourcedbusimpl.h"
#include "constants.h"

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

QStringList DataSourceDbusImpl::getPathByInterface(QString ifaceName)
{
    QDBusInterface iface(d->m_serviceName,
                         DBUS_ALTERATOR_MANAGER_PATH,
                         DBUS_MANAGER_INTERFACE_NAME,
                         d->m_dbusConnection);

    if (!iface.isValid())
    {
        return QStringList{};
    }

    QDBusReply<QStringList> reply = iface.call(DBUS_GET_OBJECTS_METHOD_NAME, ifaceName);

    if (!reply.isValid())
    {
        return QStringList{};
    }

    return reply.value();
}

QByteArray DataSourceDbusImpl::getObjectInfo(QString ifaceName, QString path, QString methodName)
{
    QDBusInterface iface(d->m_serviceName, path, ifaceName, d->m_dbusConnection);

    if (!iface.isValid())
    {
        return QByteArray{};
    }

    QDBusReply<QByteArray> reply = iface.call(methodName);

    if (!reply.isValid())
    {
        return QByteArray{};
    }

    return reply.value();
}

} // namespace ao_builder
