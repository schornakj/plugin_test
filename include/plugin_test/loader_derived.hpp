#pragma once

#include <plugin_test/loader_base.hpp>

namespace plugin_test {
class LoaderDerived : public LoaderBase
{
public:
  void registerClasses(Factory& factory, const std::shared_ptr<int>& shared_resource) override;
};
}
