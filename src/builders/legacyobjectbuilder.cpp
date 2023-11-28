#include "legacyobjectbuilder.h"
namespace ao_builder
{
LegacyObjectBuilder::LegacyObjectBuilder() {}

LegacyObjectBuilder::~LegacyObjectBuilder() {}

std::unique_ptr<Object> LegacyObjectBuilder::buildObject(ObjectParserInterface *parser)
{
    return nullptr;
}
} // namespace ao_builder
