
#include "AssetsLoader.hpp"

namespace Loader {

template<typename T>
void AssetsLoader<T>::setSupportedFormats(std::string formats, std::string delim) {
  std::regex regex(delim);
  std::vector<std::string>
      lst(std::sregex_token_iterator(std::begin(formats), std::end(formats), regex, -1), std::sregex_token_iterator());

  for (auto &&format: lst)
    if (!format.empty())
      m_supportedFormats.emplace("." + format);
}

template<typename T>
void AssetsLoader<T>::loadAssets(std::string_view folderPath,
                                 std::function<void(T &, const std::filesystem::path &)> loader) {

  fs::recursive_directory_iterator begin(folderPath, std::filesystem::directory_options::skip_permission_denied);
  fs::recursive_directory_iterator end;

  std::vector<fs::path> pathFiles;
  std::copy(begin, end, std::back_inserter(pathFiles));

  for (const auto &path: pathFiles) {
    const auto &extension = path.extension().string();
    if (auto search = m_supportedFormats.find(extension); search!=std::end(m_supportedFormats)) {
      auto nameFile = path.stem().string();
      auto &ref = m_storage[nameFile];
      loader(ref, path);
    }
  }
}

template<typename T>
T *AssetsLoader<T>::operator[](std::string_view name) {
  return getPtr(name);
}

template<typename T>
const T *AssetsLoader<T>::getPtr(const std::string_view name) const {
  return getPtr(name);
}

template<typename T>
T *AssetsLoader<T>::getPtr(std::string_view name) {
  if (auto res = m_storage[name]; res!=std::end(m_storage))
    return m_storage[name];
}
}