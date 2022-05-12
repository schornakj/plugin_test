#include <plugin_test/loader_base.hpp>
#include <memory>

namespace plugin_test
{
template <typename T>
RegisterFn LoaderBase::makeRegisterFn(const std::shared_ptr<int>& shared_resource) const
{
  return [=](){return std::make_unique<T>(shared_resource); };
}

template <typename T>
void LoaderBase::registerClass(const std::string& id, Factory& factory, const std::shared_ptr<int>& shared_resource)
{
  factory.registerClass(id, makeRegisterFn<T>(shared_resource));
}
}  // namespace moveit_studio::behaviors
