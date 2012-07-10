#pragma once

#include "SceneNode.h"

using namespace System::Collections::Generic;

namespace ManagedFbx
{
	public ref class Scene
	{
	public:
		property_r(SceneNode^, RootNode);
		property_rw(string^, Name);

	internal:
		Scene(FbxScene *nativeScene);

	private:
		FbxScene *m_nativeScene;
		SceneNode ^m_rootNode;
	};
}