#pragma once

#include <plugin_test/my_class_intermediate.hpp>

namespace plugin_test
{
class MyClass : public MyClassIntermediate
{
public:
  MyClass(const std::shared_ptr<int>& shared_resource);

  int getValue() const override;
};
}
