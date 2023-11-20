#ifndef LOCALAPPLICATIONOBJECTBUILDER_H
#define LOCALAPPLICATIONOBJECTBUILDER_H

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

#endif // LOCALAPPLICATIONOBJECTBUILDER_H
