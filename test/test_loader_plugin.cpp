#include <gtest/gtest.h>

#include <pluginlib/class_loader.hpp>

#include <plugin_test/loader_base.hpp>

TEST(MockNodeLoader, load_mock_behavior_loader_plugin)
{
  pluginlib::ClassLoader<plugin_test::LoaderBase> class_loader("plugin_test", "plugin_test::LoaderBase");
  auto plugin_instance = class_loader.createUniqueInstance("plugin_test::LoaderDerived");

  plugin_test::Factory factory;

  const auto shared_resources = std::make_shared<int>(10);

  ASSERT_NO_THROW(plugin_instance->registerClasses(factory, shared_resources));
  EXPECT_EQ(factory.getSumFromRegistered(), 42);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
