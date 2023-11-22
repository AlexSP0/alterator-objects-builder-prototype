#include "categoryobjectbuilder.h"

namespace ao_builder
{
CategoryObjectBuilder::CategoryObjectBuilder() {}

CategoryObjectBuilder::~CategoryObjectBuilder() {}

std::unique_ptr<Object> CategoryObjectBuilder::buildObject(ObjectParserInterface *parser)
{
    return nullptr;
}
} // namespace ao_builder
