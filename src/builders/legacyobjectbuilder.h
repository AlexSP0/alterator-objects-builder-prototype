#ifndef AOB_LEGACY_OBJECT_BUILDER_H
#define AOB_LEGACY_OBJECT_BUILDER_H

#include "objectbulderinterface.h"

namespace ao_builder
{
class LegacyObjectBuilder : public ObjectBuilderInterface
{
public:
    LegacyObjectBuilder();
    ~LegacyObjectBuilder();

    std::unique_ptr<Object> buildObject(ObjectParserInterface *parser) override;
};

} // namespace ao_builder
#endif // AOB_LEGACY_OBJECT_BUILDER_H
