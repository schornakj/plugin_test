#include <plugin_test/my_class.hpp>

namespace plugin_test {

MyClass::MyClass(const std::shared_ptr<int>& shared_resource)
  : MyClassIntermediate (shared_resource)
{

}

int MyClass::getValue() const
{
  return 32 + some_value_;
}
}
