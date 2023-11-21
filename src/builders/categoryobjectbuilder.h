#ifndef AOB_CATEGORY_OBJECT_BUILDER_H
#define AOB_CATEGORY_OBJECT_BUILDER_H

#include "objectbulderinterface.h"

namespace ao_builder
{
class CategoryObjectBuilder : public ObjectBuilderInterface
{
public:
    CategoryObjectBuilder();
    ~CategoryObjectBuilder();

    std::unique_ptr<Object> buildObject(ObjectParserInterface *parser) override;
};

} // namespace ao_builder

#endif // AOB_CATEGORY_OBJECT_BUILDER_H
