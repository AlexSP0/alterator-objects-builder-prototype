#include "constants.h"

#include "aobuilderimpl.h"

#include "builders/localapplicationobjectbuilder.h"
#include "builders/objectbulderinterface.h"
#include <builders/objectbuilderfactory.h>

#include "datasource/datasourcedbusimpl.h"
#include "datasource/datasourceinterface.h"

#include <parsers/baseobjectparser.h>

namespace ao_builder
{
class AOBuilderImplPrivate
{
public:
    AOBuilderImplPrivate()
        : m_localAppBuilder(new LocalApplicationObjectBuilder())
        , m_dataSource(new DataSourceDBusImpl(DBUS_SERVICE_NAME))
        , m_parser(new BaseObjectParser())
    {}

public:
    std::unique_ptr<ObjectBuilderInterface> m_localAppBuilder;
    std::unique_ptr<DataSourceInterface> m_dataSource;
    std::unique_ptr<ObjectParserInterface> m_parser;
};

AOBuilderImpl::AOBuilderImpl()
    : d(new AOBuilderImplPrivate())
{}

AOBuilderImpl::~AOBuilderImpl()
{
    delete d;
}

QStringList AOBuilderImpl::getLegacyObjectsPaths()
{
    return d->m_dataSource->getLegacyObjectsPaths();
}

QStringList AOBuilderImpl::getLocalAppsPaths()
{
    return d->m_dataSource->getLocalAppPaths();
}

QStringList AOBuilderImpl::getCategoriesList()
{
    return d->m_dataSource->getCategoriesList();
}

QStringList AOBuilderImpl::getObjectsPaths()
{
    return d->m_dataSource->getObjectsPath();
}

std::unique_ptr<Object> AOBuilderImpl::buildObject(QString path, QString interface)
{
    QString objectInfo = d->m_dataSource->getObjectInfo(interface, path, DBUS_OBJECT_METHOD_INFO_DEFAULT_NAME);

    if (objectInfo.isEmpty())
    {
        return nullptr;
    }

    if (!d->m_parser->parse(objectInfo))
    {
        return nullptr;
    }

    ObjectBuilderFactory factory;

    std::unique_ptr<ObjectBuilderInterface> objectBuilder = factory.getBuilder(d->m_parser.get());

    if (!objectBuilder)
    {
        return nullptr;
    }

    return objectBuilder->buildObject(d->m_parser.get());
}
} // namespace ao_builder
