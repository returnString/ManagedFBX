#pragma once

#include "Polygon.h"

namespace ManagedFbx
{
	public ref class Mesh
	{
	public:
		property_r(array<Polygon>^, Polygons);
		property_r(array<Vector3>^, Vertices);
		property_r(array<Vector3>^, Normals);

		property_r(bool, HasOnlyTriangles);

		Mesh ^Triangulate();

	internal:
		Mesh(FbxMesh *nativeMesh);

	private:
		FbxMesh *m_nativeMesh;
	};
}