#pragma once

#include "Scene.h"

namespace ManagedFbx
{
	ref class Manager abstract sealed
	{
	public:
		static Manager();
		static FbxManager *GetFbxManager();
		static FbxImporter *GetFbxImporter();

	private:
		static FbxManager *m_nativeManager;
		static FbxImporter *m_nativeImporter;
	};
}