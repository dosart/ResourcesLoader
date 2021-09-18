#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

#include "AssetsLoader.hpp"

class BadLoadFixture : public ::testing::Test {
 protected:
  ::Loader::AssetsLoader<sf::Texture> *textureLoader;

  void SetUp() override {
    textureLoader = new ::Loader::AssetsLoader<sf::Texture>();
  }

  void TearDown() override {
    delete textureLoader;
  }

};

TEST_F(BadLoadFixture, DirectoryNotExist) {
  bool result =
      textureLoader->loadAssets("./resources", [](auto &item, auto path) { item.loadFromFile(path.string()); });

  ASSERT_EQ(result, false);
}

TEST_F(BadLoadFixture, LoaderIsNull) {
  bool result = textureLoader->loadAssets(".", nullptr);

  ASSERT_EQ(result, false);
}

TEST_F(BadLoadFixture, LoaderIsNullAndDirectoryNotExist) {
  bool result = textureLoader->loadAssets("./resources", nullptr);

  ASSERT_EQ(result, false);
}