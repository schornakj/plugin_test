#include <plugin_test/factory.hpp>

namespace plugin_test
{
void Factory::registerClass(const std::string& id, const RegisterFn& fn)
{
  builders_.insert(std::make_pair(id, fn));
}

int Factory::getSumFromRegistered() const
{
  int sum = 0;
  for (const auto& builder : builders_)
  {
    const auto instance = builder.second();
    sum += instance->getValue();
  }
  return sum;
}
}
