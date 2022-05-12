#include <plugin_test/loader_derived.hpp>

#include <plugin_test/my_class.hpp>
#include <pluginlib/class_list_macros.hpp>

namespace plugin_test {
void LoaderDerived::registerClasses(Factory& factory, const std::shared_ptr<int>& shared_resource)
{
  factory.registerClass("my_class", [=](){return std::make_unique<MyClass>(shared_resource); });

  // Doesn't work, presumably because the function I'm trying to call is uninstantiated here
//  registerClass<MyClass>("my_class", factory);
}
}

PLUGINLIB_EXPORT_CLASS(plugin_test::LoaderDerived, plugin_test::LoaderBase);
