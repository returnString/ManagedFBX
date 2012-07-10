#pragma once

#include "Scene.h"

namespace ManagedFbx
{
	public ref class Manager
	{
	public:
		Manager();

		Scene ^CreateScene(string ^name);
		Scene ^ImportScene(string ^filename);

	private:
		FbxManager *m_pNativeManager;
		FbxImporter *m_pNativeImporter;
	};
}