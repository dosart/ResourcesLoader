#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <filesystem>
#include <iostream>

#include "AssetsLoader.hpp"

namespace fs = std::filesystem;

class GoodLoadFixture : public ::testing::Test {
 protected:
  ::Loader::AssetsLoader<sf::Texture> *textureLoader;
  ::Loader::AssetsLoader<sf::Music> *musicLoader;
  std::string resourcesDirPath;

  void SetUp() override {
    textureLoader = new ::Loader::AssetsLoader<sf::Texture>();
    musicLoader = new ::Loader::AssetsLoader<sf::Music>();
    resourcesDirPath = getResourcesDirPath();
  }

  void TearDown() override {
    delete textureLoader;
  }

  std::string getResourcesDirPath() {
    fs::path working_dir(fs::current_path());
    auto srcPath = working_dir.parent_path().parent_path();

    auto resourcesDir = srcPath/"test"/"loader_tests"/"resources";
    return resourcesDir.string();
  }

};

TEST_F(GoodLoadFixture, TextureLoad) {
  textureLoader->setSupportedFormats("png.jpg.bmp", "[.]");
  textureLoader->loadAssets(resourcesDirPath, [](auto &item, auto path) { item.loadFromFile(path.string()); });

  ASSERT_NE(textureLoader->getPtr("background"), nullptr);
  ASSERT_NE(textureLoader->getPtr("asd"), nullptr);
}

TEST_F(GoodLoadFixture, MusicLoad) {
  musicLoader->setSupportedFormats("wav", "[]");
  musicLoader->loadAssets(resourcesDirPath, [](auto &item, auto path) { item.openFromFile(path.string()); });

  ASSERT_NE(musicLoader->getPtr("meow"), nullptr);
}