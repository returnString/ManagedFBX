#include "stdafx.h"
#include "Manager.h"

using namespace ManagedFbx;

static Manager::Manager()
{
	m_nativeManager = FbxManager::Create();
	m_nativeImporter = FbxImporter::Create(m_nativeManager, "Importer");
}

FbxManager *Manager::GetFbxManager()
{
	return m_nativeManager;
}

FbxImporter *Manager::GetFbxImporter()
{
	return m_nativeImporter;
}