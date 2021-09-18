/*!
\file
\brief Header file for resources loader for SFML of games.
\defgroup loader
 Resources:
    - musics;
    - textures;
    - images.
*/
#ifndef ASSETS_LOADER_H_
#define ASSETS_LOADER_H_

#include <unordered_map>
#include <vector>
#include <set>

#include <string>
#include <string_view>
#include <regex>

#include <algorithm>
#include <functional>
#include <filesystem>

namespace fs = std::filesystem;

namespace Loader {

 /*!
	\brief Resources loader class for SFML of games.
	\author Dosart
    \ingroup loader
	\version 1.0
*/
template<typename T>
class AssetsLoader {
 public:
  AssetsLoader() = default;
  ~AssetsLoader() = default;

  AssetsLoader(const AssetsLoader<T> &other) = delete;
  AssetsLoader &operator=(const AssetsLoader<T> &other) = delete;

  AssetsLoader(const AssetsLoader<T> &&other) = delete;
  AssetsLoader &operator=(const AssetsLoader<T> &&other) = delete;

  /**
   * @brief Set formats for correct load Assets.
   *
   * @param formats ".png.jpg.bmp" or "|png|jpg|bmp" etc...
   * @param delim "[.]" because regex etc....
 */
  void setSupportedFormats(std::string formats, std::string delim);
  
   /**
   * @brief  Load assets with users functor.
   *
   * @param folderPath path to folder with assets.
   * @param loader itetm.loadFromFile(path) u get only path with your formats.
*/
  void loadAssets(std::string_view folderPath,
                  std::function<void(T &item, const fs::path &itemPath)> loader);

  T* operator[](std::string_view name);
  T* getPtr(std::string_view name);
  const T* getPtr(const std::string_view name) const;

 private:
  std::set<std::string> m_supportedFormats;
  std::unordered_map<std::string, T> m_storage;
};
}

#include "AssetsLoader.inl"

#endif
