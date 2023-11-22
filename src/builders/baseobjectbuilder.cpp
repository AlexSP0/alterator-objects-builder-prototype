#include "baseobjectbuilder.h"
#include "constants.h"
#include "parsers/objectparserinterface.h"

namespace ao_builder
{
BaseObjectBuilder::BaseObjectBuilder() {}

BaseObjectBuilder::~BaseObjectBuilder() {}

std::unique_ptr<Object> BaseObjectBuilder::buildObject(ObjectParserInterface *parser)
{
    return nullptr;
}

bool BaseObjectBuilder::buildFieldWithLocale(ObjectParserInterface *parser,
                                             ObjectParserInterface::Section &section,
                                             QString entryName,
                                             QString &field,
                                             QMap<QString, QString> &localeStorage)
{
    auto nameIt = section.find(entryName);

    if (nameIt == section.end())
    {
        return false;
    }

    QList<ObjectParserInterface::IniFileKey> listOfKeys = section.values(entryName);

    QString defaultName = parser->getDefaultValue(listOfKeys);

    if (defaultName.isEmpty())
    {
        return false;
    }

    field = defaultName;

    for (ObjectParserInterface::IniFileKey &currentIniFileKey : listOfKeys)
    {
        localeStorage.insert(currentIniFileKey.keyLocale, currentIniFileKey.value.toString());
    }

    return true;
}

bool BaseObjectBuilder::buildNames(ObjectParserInterface *parser,
                                   ObjectParserInterface::Section &section,
                                   Object *localAppObject)
{
    auto nameIt = section.find(OBJECT_KEY_NAME);

    if (nameIt == section.end())
    {
        return false;
    }

    QList<ObjectParserInterface::IniFileKey> listOfKeys = section.values(OBJECT_KEY_NAME);

    QString defaultName = parser->getDefaultValue(listOfKeys);

    if (defaultName.isEmpty())
    {
        return false;
    }

    localAppObject->m_id = defaultName;

    for (ObjectParserInterface::IniFileKey &currentIniFileKey : listOfKeys)
    {
        localAppObject->m_nameLocaleStorage.insert(currentIniFileKey.keyLocale, currentIniFileKey.value.toString());
    }

    return true;
}

std::vector<QString> BaseObjectBuilder::parseValuesFromKey(ObjectParserInterface *parser,
                                                           QString section,
                                                           QString key,
                                                           QString delimiter)
{
    QString values = parser->getValue(section, key);
    if (values.isEmpty())
    {
        return {};
    }

    if (values.back() == delimiter)
    {
        values.truncate(values.size() - 1);
    }

    QStringList valuesList = values.split(delimiter);

    std::vector<QString> result;
    for (QString &currentValue : valuesList)
    {
        if (!currentValue.isEmpty())
        {
            result.push_back(currentValue);
        }
    }

    return result;
}

} // namespace ao_builder
