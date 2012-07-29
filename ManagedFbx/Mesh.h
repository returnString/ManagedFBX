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
		property_r(array<Vector2>^, TextureCoords);
		property_r(array<Colour>^, VertexColours);
		property_r(array<int>^, MaterialIDs);
		property_r(bool, HasOnlyTriangles);
		property int UVLayer;

		Mesh ^Triangulate();

		int GetUVIndex(int polygon, int index);
		int GetMaterialId(int polygon);
		Vector3 GetVertexNormal(int polygon, int index);

	internal:
		Mesh(FbxMesh *nativeMesh);

	private:
		FbxMesh *m_nativeMesh;
	};
}