#pragma once

#include "Real/Core/Buffer.h"

namespace Real {

	class FileSystem
	{
	public:
		// TODO: move to FileSystem class
		static Buffer ReadFileBinary(const std::filesystem::path& filepath);
	};

}