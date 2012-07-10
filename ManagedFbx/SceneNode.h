#pragma once

#include "Properties.h"

using namespace System::Collections::Generic;

namespace ManagedFbx
{
	public ref class SceneNode
	{
	public:
		property_rw(string^, Name);
		property_r(IEnumerable<SceneNode^>^, ChildNodes);
		
		property_rw(Vector3, Position);
		property_rw(Vector3, Rotation);
		property_rw(Vector3, Scale);

		void AddChild(SceneNode ^node);

	internal:
		SceneNode(FbxNode *node);

	private:
		FbxNode *m_nativeNode;
		List<SceneNode^> ^m_children;
	};
}