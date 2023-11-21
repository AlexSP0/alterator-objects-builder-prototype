#ifndef AOB_LOCAL_APPLICATION_OBJECT_BUILDER_H
#define AOB_LOCAL_APPLICATION_OBJECT_BUILDER_H

#include "objectbulderinterface.h"

namespace ao_builder
{
class LocalApplicationObjectBuilder : public ObjectBuilderInterface
{
public:
    LocalApplicationObjectBuilder();
    ~LocalApplicationObjectBuilder();

    std::unique_ptr<Object> buildObject(ObjectParserInterface *parser) override;
};

} // namespace ao_builder

#endif // AOB_LOCAL_APPLICATION_OBJECT_BUILDER_H
