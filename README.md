[![Codacy Badge](https://app.codacy.com/project/badge/Grade/38d4460ca69e4a8d8bf233e8af4a4631)](https://www.codacy.com/gh/dosart/ResourcesLoader/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=dosart/ResourcesLoader&amp;utm_campaign=Badge_Grade)

# ResourcesLoader

Recursive Template Loader for simple loading any assets. Used for simple SFML games. 

**Technology stack:** c++17, google test, sfml

#### Static lib version
```console
$ git clone https://github.com/dosart/ResourcesLoader.git
$ cd ResourcesLoader && mkdir build && cd build
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
    textureLoader.loadAssets("./resources", [](auto &item, auto path) { item.loadFromFile(path.string()); });
    
     ::Loader::AssetsLoader<sf::Music> musicLoader;
    musicLoader.setSupportedFormats("waw,ogv", "[,]");
    musicLoader.loadAssets(resourcesDirPath, [](auto &item, auto path) { item.openFromFile(path.string()); });
}
```
