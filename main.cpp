#include "AssetsLoader.hpp"

int main() {

  ::Loader::AssetsLoader<int> loader;
  loader.setSupportedFormats(".png.jpg.bmp", "[.]");
}
