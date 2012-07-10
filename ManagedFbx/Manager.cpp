#include "stdafx.h"
#include "Manager.h"

using namespace ManagedFbx;

Manager::Manager()
{
	m_pNativeManager = FbxManager::Create();
	m_pNativeImporter = FbxImporter::Create(m_pNativeManager, "Importer");
}

Scene ^Manager::CreateScene(string ^name)
{
	auto nativeScene = FbxScene::Create(m_pNativeManager, StringHelper::ToNative(name));
	return gcnew Scene(nativeScene);
}

Scene ^Manager::ImportScene(string ^filename)
{
	bool success = m_pNativeImporter->Initialize(StringHelper::ToNative(filename));

	if(!success)
		throw gcnew FbxException("Failed to initialise the FBX importer: " + gcnew string(m_pNativeImporter->GetLastErrorString()));

	auto nativeScene = FbxScene::Create(m_pNativeManager, "");
	m_pNativeImporter->Import(nativeScene);

	return gcnew Scene(nativeScene);
}