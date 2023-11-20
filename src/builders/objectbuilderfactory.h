#ifndef OBJECTBUILDERFACTORY_H
#define OBJECTBUILDERFACTORY_H

#include "objectbulderinterface.h"

namespace ao_builder
{
class ObjectBuilderFactory
{
public:
    ObjectBuilderFactory()  = default;
    ~ObjectBuilderFactory() = default;

    std::unique_ptr<ObjectBuilderInterface> getBuilder(ObjectParserInterface *parser);

private:
    std::unique_ptr<ObjectBuilderInterface> getObjectBuilder(ObjectParserInterface *parser);
};

} // namespace ao_builder

#endif // OBJECTBUILDERFACTORY_H
