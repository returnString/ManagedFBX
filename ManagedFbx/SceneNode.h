#pragma once

#include "NodeAttribute.h"
#include "Mesh.h"
#include "Light.h"

using namespace System::Collections::Generic;

namespace ManagedFbx
{
	public ref class SceneNode
	{
	public:
		property_rw(string^, Name);
		property_r(IEnumerable<SceneNode^>^, ChildNodes);
		property_r(IEnumerable<NodeAttribute^>^, Attributes);
		
		property_rw(Vector3, Position);
		property_rw(Vector3, Rotation);
		property_rw(Vector3, Scale);

		property_r(ManagedFbx::Mesh^, Mesh);
		property_r(ManagedFbx::Light^, Light);

		void AddChild(SceneNode ^node);

	internal:
		SceneNode(FbxNode *node);

	private:
		FbxNode *m_nativeNode;
		List<SceneNode^> ^m_children;
		List<NodeAttribute^> ^m_attributes;
	};
}