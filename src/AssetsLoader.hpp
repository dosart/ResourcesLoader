#ifndef ASSETS_LOADER_H_
#define ASSETS_LOADER_H_

#include <unordered_map>
#include <vector>

#include <string>
#include <string_view>
#include <regex>

#include <algorithm>
#include <functional>
#include <filesystem>

namespace fs = std::filesystem;

namespace Loader {

template<typename T>
class AssetsLoader {
 public:
  AssetsLoader() = default;
  ~AssetsLoader() = default;

  AssetsLoader(const AssetsLoader<T> &other) = delete;
  AssetsLoader &operator=(const AssetsLoader<T> &other) = delete;

  AssetsLoader(const AssetsLoader<T> &&other) = delete;
  AssetsLoader &operator=(const AssetsLoader<T> &&other) = delete;

  void setSupportedFormats(std::string formats, std::string delim);
  void loadAssets(std::string_view folderPath,
                  std::function<void(T &item, const fs::path &itemPath)> loader);

 private:
  std::unordered_map<std::string, bool> m_supportedFormats;
  std::unordered_map<std::string, T> m_storage;
};
}

#include "AssetsLoader.inl"

#endif