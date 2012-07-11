#include "stdafx.h"
#include "Manager.h"

using namespace ManagedFbx;

Manager::Manager()
{
	m_nativeManager = FbxManager::Create();
	m_nativeImporter = FbxImporter::Create(m_nativeManager, "Importer");
	m_nativeExporter = FbxExporter::Create(m_nativeManager, "Exporter");
}

FbxManager *Manager::GetInstance()
{
	return m_nativeManager;
}

FbxImporter *Manager::GetImporter()
{
	return m_nativeImporter;
}

FbxExporter *Manager::GetExporter()
{
	return m_nativeExporter;
}