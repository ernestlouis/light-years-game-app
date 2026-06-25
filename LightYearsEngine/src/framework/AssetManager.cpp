#include "framework/AssetManager.h"

namespace ly
{

	AssetManager::AssetManager() : m_root_directory{}
	{

	}

	AssetManager& AssetManager::Get()
	{
		if (!asset_manager)
		{
			asset_manager = unique<AssetManager>{new AssetManager};
		}
		return *asset_manager;
	}

	shared<sf::Texture> AssetManager::Load_Texture(const std::string& path)
	{
		auto found = m_loaded_texture_map.find(path);
		if (found != m_loaded_texture_map.end())
		{
			return found->second;
		}

		shared<sf::Texture> new_texture{ new sf::Texture };
		if (new_texture->loadFromFile(m_root_directory + path))
		{
			m_loaded_texture_map.insert({ path,new_texture });
			return new_texture;
		}

		return shared<sf::Texture> {nullptr};
	}

	void AssetManager::Clean_Cycle()
	{
		for (auto iter = m_loaded_texture_map.begin(); iter != m_loaded_texture_map.end();)
		{
			if (iter->second.unique())
			{
				LOG("cleaning texture: %s", iter->first.c_str());
				iter = m_loaded_texture_map.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	void AssetManager::Set_Asset_Root_Directory(const std::string& directory)
	{
		m_root_directory = directory;
	}

	unique<AssetManager> AssetManager::asset_manager{nullptr};

}