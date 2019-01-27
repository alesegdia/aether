#pragma once

#include "../aether.h"

#include <unordered_map>
#include <vector>

namespace aether {
namespace map {


struct TileSet
{
    graphics::Spritesheet::SharedPtr sheet;
    int lastIndex = 0;
};

using LayerShared = math::Matrix2Di::SharedPtr;

class TileMap
{
public:
    void addLayer(const std::string& name, const LayerShared& layer, int order)
    {
        m_layersOrdered.emplace_back(layer);
        m_layersByName[name] = layer;
    }

    void render(float offx, float offy)
    {

    }

    const math::Matrix2Di::SharedPtr& layer(const std::string& name)
    {
        assert(m_layersByName.count(name) == 1);
        return m_layersByName[name];
    }

private:

    const TileSet& tileSetForIndex(int index)
    {
        const TileSet* ts;
        for( const auto& tileset : m_tilesets )
        {
            if( tileset.lastIndex <= index ) {
                ts = &tileset;
            }
        }
    }

    std::unordered_map<std::string, LayerShared> m_layersByName;
    std::vector<LayerShared> m_layersOrdered;
    std::vector<TileSet> m_tilesets;

};


}
}
