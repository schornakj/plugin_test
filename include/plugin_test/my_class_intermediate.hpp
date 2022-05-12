#pragma once

#include <plugin_test/my_class_base.hpp>

#include <memory>

namespace plugin_test
{
class MyClassIntermediate : public MyClassBase
{
public:
  MyClassIntermediate(const std::shared_ptr<int>& shared_resource);

protected:
  int some_value_;
};
}
