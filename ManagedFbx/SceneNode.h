#pragma once

#include "NodeAttribute.h"
#include "Mesh.h"
#include "Light.h"

using namespace System::Collections::Generic;

namespace ManagedFbx
{
	/// <summary>
	/// Represents a single node in the FBX scene graph.
	/// </summary>
	public ref class SceneNode
	{
	public:
		/// <summary>
		/// Gets and sets the name of this node.
		/// </summary>
		property_rw(string^, Name);

		/// <summary>
		/// Gets the direct children of this node.
		/// </summary>
		property_r(IEnumerable<SceneNode^>^, ChildNodes);

		/// <summary>
		/// Gets a collection of FBX attributes for this node.
		/// </summary>
		property_r(IEnumerable<NodeAttribute^>^, Attributes);

		/// <summary>
		/// Gets and sets the position of this node.
		/// </summary>
		property_rw(Vector3, Position);

		/// <summary>
		/// Gets and sets the rotation of this node.
		/// </summary>
		property_rw(Vector3, Rotation);

		/// <summary>
		/// Gets and sets the scale of this node.
		/// </summary>
		property_rw(Vector3, Scale);

		/// <summary>
		/// Gets the first mesh attribute of this node if it exists, otherwise null.
		/// </summary>
		property_r(ManagedFbx::Mesh^, Mesh);

		/// <summary>
		/// Gets the first light attribute of this node if it exists, otherwise null.
		/// </summary>
		property_r(ManagedFbx::Light^, Light);

		/// <summary>
		/// Adds an existing node as a child of this node.
		/// </summary>
		void AddChild(SceneNode ^node);

	internal:
		SceneNode(FbxNode *node);

	private:
		FbxNode *m_nativeNode;
		List<SceneNode^> ^m_children;
		List<NodeAttribute^> ^m_attributes;
	};
}