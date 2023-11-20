#include "localapplicationobjectbuilder.h"

namespace ao_builder
{
LocalApplicationObjectBuilder::LocalApplicationObjectBuilder() {}

LocalApplicationObjectBuilder::~LocalApplicationObjectBuilder() {}

std::unique_ptr<ao_builder::Object> LocalApplicationObjectBuilder::buildObject(ObjectParserInterface *parser)
{
    return nullptr;
}
} // namespace ao_builder
