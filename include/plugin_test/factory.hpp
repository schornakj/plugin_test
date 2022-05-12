#pragma once

#include <plugin_test/my_class_base.hpp>

#include <map>
#include <memory>
#include <functional>

namespace plugin_test
{
typedef std::function<std::unique_ptr<MyClassBase>()> RegisterFn;
class Factory
{
public:
  void registerClass(const std::string& id, const RegisterFn& fn);

  int getSumFromRegistered() const;

private:
  std::map<std::string, RegisterFn> builders_;
};
}
