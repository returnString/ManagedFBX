#pragma once

#include "SceneNode.h"

using namespace System::Collections::Generic;

namespace ManagedFbx
{
	/// <summary>
	/// Represents an FBX scene.
	/// </summary>
	public ref class Scene
	{
	public:
		/// <summary>
		/// Constructs a new empty scene with the given name.
		/// </summary>
		Scene(string ^name);

		/// <summary>
		/// Imports a scene from a file.
		/// </summary>
		static Scene ^Import(string ^filepath);

		/// <summary>
		/// Saves the scene to a file.
		/// </summary>
		void Save(string ^filepath);

		/// <summary>
		/// Gets the root node of this scene.
		/// </summary>
		property_r(SceneNode^, RootNode);

		/// <summary>
		/// Gets and sets the name of this scene.
		/// </summary>
		property_rw(string^, Name);

	private:
		FbxScene *m_nativeScene;
		SceneNode ^m_rootNode;
	};
}