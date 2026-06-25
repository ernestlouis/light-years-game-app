#pragma once

#include <SFML/Graphics.hpp>

#include "framework/Core.h"

namespace ly
{
	class AssetManager
	{
		protected:
			AssetManager();

		public:
			static AssetManager& Get();
			shared<sf::Texture> Load_Texture(const std::string& path);
			void Clean_Cycle();
			void Set_Asset_Root_Directory(const std::string& directory);

		private:
			static unique<AssetManager> asset_manager;
			Dictionary<std::string, shared<sf::Texture>> m_loaded_texture_map;
			std::string m_root_directory;

	};
}