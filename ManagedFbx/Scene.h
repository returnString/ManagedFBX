#pragma once

#include "SceneNode.h"

using namespace System::Collections::Generic;

namespace ManagedFbx
{
	public ref class Scene
	{
	public:
		Scene(string ^name);
		static Scene ^Import(string ^filepath);

		property_r(SceneNode^, RootNode);
		property_rw(string^, Name);

	private:
		FbxScene *m_nativeScene;
		SceneNode ^m_rootNode;
	};
}