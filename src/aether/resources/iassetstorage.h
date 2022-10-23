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
		};


	}
}