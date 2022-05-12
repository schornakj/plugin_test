#include <plugin_test/my_class_intermediate.hpp>

namespace plugin_test {
MyClassIntermediate::MyClassIntermediate(const std::shared_ptr<int>& shared_resource)
  : MyClassBase ()
  , some_value_{ *shared_resource }
{

}
}
