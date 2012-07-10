#include "stdafx.h"
#include "Scene.h"

using namespace ManagedFbx;

Scene::Scene(FbxScene *nativeScene)
{
	m_nativeScene = nativeScene;
	m_rootNode = gcnew SceneNode(m_nativeScene->GetRootNode());
}

void Scene::Name::set(string ^value)
{
	m_nativeScene->SetName(StringHelper::ToNative(value));
}

string ^Scene::Name::get()
{
	return gcnew string(m_nativeScene->GetName());
}

SceneNode ^Scene::RootNode::get()
{
	return m_rootNode;
}