#ifndef BASEOBJECTPARSER_H
#define BASEOBJECTPARSER_H

#include "objectparserinterface.h"

namespace ao_builder
{
class BaseObjectParser : public ObjectParserInterface
{
public:
    BaseObjectParser()  = default;
    ~BaseObjectParser() = default;

public:
    Sections getSections() override;
    bool parse(QString data) override;

    QString getKeyLocale(QString keyName) override;
    QString getKeyNameWithoutLocale(QString keyName) override;
    QString getDefaultValue(QList<IniFileKey> iniFileKey) override;
    QString getValue(QString section, QString key) override;

private:
    Sections m_sections{};
};

} // namespace ao_builder

#endif // BASEOBJECTPARSER_H
