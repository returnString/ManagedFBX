#pragma once

#include "Polygon.h"

namespace ManagedFbx
{
	public ref class Mesh
	{
	public:
		property_r(array<Polygon>^, Polygons);
		property_r(array<Vector3>^, Vertices);

	internal:
		Mesh(FbxMesh *nativeMesh);

	private:
		FbxMesh *m_nativeMesh;
	};
}