#ifndef AOB_BASE_OBJECT_BUILDER_H
#define AOB_BASE_OBJECT_BUILDER_H

#include "objectbulderinterface.h"

namespace ao_builder
{
class BaseObjectBuilder : public ObjectBuilderInterface
{
public:
    BaseObjectBuilder();
    ~BaseObjectBuilder();

public:
    std::unique_ptr<Object> buildObject(ObjectParserInterface *parser);

    bool buildFieldWithLocale(ObjectParserInterface *parser,
                              ObjectParserInterface::Section &section,
                              QString entryName,
                              QString &field,
                              QMap<QString, QString> &localeStorage);

    bool buildNames(ObjectParserInterface *parser, ObjectParserInterface::Section &section, Object *localAppObject);

    std::vector<QString> parseValuesFromKey(ObjectParserInterface *parser,
                                            QString section,
                                            QString key,
                                            QString delimiter);
};

} // namespace ao_builder

#endif // AOB_BASE_OBJECT_BUILDER_H
