#pragma once

#include "SceneNode.h"
#include "ConversionTypes.h"

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
		/// Converts the scene to a given unit system.
		/// </summary>
		void ConvertUnits(Unit units);

		/// <summary>
		/// Converts the scene to a given orientation.
		/// </summary>
		void ConvertAxes(AxisSystem axis);

		/// <summary>
		/// Bakes node transforms into vertex positions.
		/// </summary>
		void BakeTransform(SceneNode ^node);

		/// <summary>
		/// Gets the root node of this scene.
		/// </summary>
		property_r(SceneNode^, RootNode);

		/// <summary>
		/// Gets and sets the name of this scene.
		/// </summary>
		property_rw(string^, Name);

		/// <summary>
		/// Gets and sets the name of the application used to create this scene.
		/// </summary>
		property_rw(string^, Application);

		property_r(string^, UnitType);

	private:
		FbxScene *m_nativeScene;
		SceneNode ^m_rootNode;
		FbxManager *m_manager;
	};
}