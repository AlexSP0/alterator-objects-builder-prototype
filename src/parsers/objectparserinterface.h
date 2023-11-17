#ifndef AOB_OBJECT_PARSER_INTERFACE_H
#define AOB_OBJECT_PARSER_INTERFACE_H

#include <QMap>
#include <QMultiMap>
#include <QString>
#include <QVariant>

namespace ao_builder
{
class ObjectParserInterface
{
public:
    struct IniFileKey
    {
        QString keyName{};
        QString keyLocale{};
        QVariant value{};
    };

    using Section  = QMultiMap<QString, IniFileKey>;
    using Sections = QMap<QString, Section>;

public:
    virtual ~ObjectParserInterface() = default;

public:
    virtual Sections getSections() = 0;
};

} // namespace ao_builder

#endif
