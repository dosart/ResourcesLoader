namespace Loader {

template<typename T>
void AssetsLoader<T>::setSupportedFormats(std::string formats, std::string delim) {
  std::regex regex(delim);
  std::vector<std::string>
      lst(std::sregex_token_iterator(std::begin(formats), std::end(formats), regex, -1), std::sregex_token_iterator());

  for (auto &&format: lst)
    if (!format.empty())
      m_supportedFormats.emplace(std::move("." + format), true);
}

template<typename T>
void AssetsLoader<T>::loadAssets(std::string_view folderPath,
                                 std::function<void(T &, const std::filesystem::path &)> loader) {

  fs::recursive_directory_iterator begin(folderPath);
  fs::recursive_directory_iterator end;

  std::vector<fs::path> pathFiles;
  std::copy(std::make_move_iterator(begin),
            std::make_move_iterator(end),
            std::back_inserter(pathFiles));

  for (const auto &path: pathFiles) {
    const auto &extension = path.extension().string();
    if (m_supportedFormats[extension]) {
      auto nameFile = path.stem().string();
      auto &ref = m_storage[nameFile];
      loader(ref, path);
    }
  }
}
}