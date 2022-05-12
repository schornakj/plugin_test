#pragma once

#include <plugin_test/factory.hpp>

#include <string>

namespace plugin_test
{
class LoaderBase
{
public:
  virtual void registerClasses(Factory& factory, const std::shared_ptr<int>& shared_resource) = 0;

protected:
  template <typename T>
  RegisterFn makeRegisterFn(const std::shared_ptr<int>& shared_resource) const;

  template <typename T>
  void registerClass(const std::string& id, Factory& factory, const std::shared_ptr<int>& shared_resource);
};
}  // namespace moveit_studio::behaviors
