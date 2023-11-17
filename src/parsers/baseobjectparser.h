#ifndef BASEOBJECTPARSER_H
#define BASEOBJECTPARSER_H

#include "objectparserinterface.h"

namespace ao_builder
{
class BaseObjectParser : public ObjectParserInterface
{
public:
    BaseObjectParser(QString data);
    ~BaseObjectParser() = default;

public:
    Sections getSections();

private:
    QString getKeyLocale(QString keyName);
    QString getKeyNameWithoutLocale(QString keyName);

private:
    Sections m_sections;
};

} // namespace ao_builder

#endif // BASEOBJECTPARSER_H
