#pragma once

#include "aether/core/ModuleObject.h"
#include "aether/math/vec.h"
#include <vector>

#include <algorithm>
namespace aether::render {

    class IRenderModule;

    class Texture : public core::ModuleObject
    {
    protected:
        Texture(ModuleObject* o) : ModuleObject(o) {}

    public:
        IRenderModule* GetRenderer() const;

        virtual math::Vec2i GetSize() const = 0;

    };

    class TextureConfigEntry
    {
    public:
		TextureConfigEntry(int slot, Texture* texture)
			: m_slot(slot)
			, m_texture(texture)
		{
		}

        int GetSlot() const
        {
            return m_slot;
        }

		Texture* GetTexture() const
		{
			return m_texture;
		}

		bool operator==(const TextureConfigEntry& other) const
		{
			return m_slot == other.m_slot && m_texture == other.m_texture;
		}

    private:
        int m_slot = -1;
        Texture* m_texture;

    };

    class TextureConfig
    {
    public:
		void AddEntrySorted(int slot, Texture* texture)
		{
			m_entries.push_back(TextureConfigEntry(slot, texture));
			std::sort(m_entries.begin(), m_entries.end(), [](const TextureConfigEntry& a, const TextureConfigEntry& b) { return a.GetSlot() < b.GetSlot(); });
		}

		bool operator==(const TextureConfig& other) const
		{
			for (int i = 0; i < m_entries.size(); i++)
			{
				if (m_entries[i] != other.m_entries[i])
					return false;
			}
			return true;
		}

		uint64_t GetOrder() const
		{
			uint64_t order = 0;
			for (int i = 0; i < m_entries.size(); i++)
			{
				order |= (uint64_t)m_entries[i].GetTexture() << (i * 8);
			}
			return order;
		}

		const std::vector<TextureConfigEntry>& GetEntries() const
		{
			return m_entries;
		}

    private:
		std::vector<TextureConfigEntry> m_entries;

    };

	TextureConfig CreateSingleTextureConfig(Texture* texture, int slot = 0);

}
