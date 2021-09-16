# ResourcesLoader

Recursive Template Loader for simple loading any assets. Used for simple SFML games. 

#### Static lib version
```console
$ git clone https://github.com/dosart/ResourcesLoader.git
$ cd spdlog && mkdir build && cd build
$ cmake .. && make -j
```

#### Usage samples

```C++
#include <SFML/Graphics.hpp>
#include "AssetsLoader.hpp"

int main()
{
    ::Loader::AssetsLoader<sf::Texture> textureLoader;
    textureLoader.setSupportedFormats("png.jpg.bmp", "[.]");
    textureLoader.loadAssets("./resources", [](auto& item, auto path) {item.loadFromFile(path.string())});
    
     ::Loader::AssetsLoader<sf::Music> musicLoader;
    musicLoader.setSupportedFormats("waw,ogv", "[,]");
    musicLoader.loadAssets("./resources", [](auto& item, auto path) {item.loadAssets(path.string())});
}
```
