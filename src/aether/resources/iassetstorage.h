#pragma once

#include <string>


namespace aether
{
	namespace resources
	{

		class IAssetStorage
		{
		public:
			virtual ~IAssetStorage() = default;

			virtual void Load(std::string path) = 0;
			virtual std::string GetLoadMessage() = 0;

			void SetBasePath(std::string basePath)
			{
				m_basePath = basePath;
			}

		protected:
			std::string GetPath(std::string path)
			{
				return m_basePath + "/" + path;
			}

		private:
			std::string m_basePath;

		};


	}
}