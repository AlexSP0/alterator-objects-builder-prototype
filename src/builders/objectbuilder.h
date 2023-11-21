#ifndef AOB_OBJECT_BUILDER_H
#define AOB_OBJECT_BUILDER_H

#include "objectbulderinterface.h"

namespace ao_builder
{
class ObjectBuilder : public ObjectBuilderInterface
{
public:
    ObjectBuilder();
    ~ObjectBuilder();

    std::unique_ptr<Object> buildObject(ObjectParserInterface *parser) override;
};

} // namespace ao_builder

#endif // AOB_OBJECT_BUILDER_H
