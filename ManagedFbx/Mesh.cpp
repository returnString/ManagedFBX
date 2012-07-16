#include "stdafx.h"
#include "Mesh.h"
#include "Manager.h"

using namespace ManagedFbx;

Mesh::Mesh(FbxMesh *nativeMesh)
{
	m_nativeMesh = nativeMesh;
}

Mesh ^Mesh::Triangulate()
{
	return gcnew Mesh(Manager::GetGeomConverter()->TriangulateMesh(m_nativeMesh));
}

bool Mesh::HasOnlyTriangles::get()
{
	return m_nativeMesh->IsTriangleMesh();
}

array<ManagedFbx::Polygon> ^Mesh::Polygons::get()
{
	int count = m_nativeMesh->GetPolygonCount();
	auto list = gcnew array<Polygon>(count);

	for(int i = 0; i < count; i++)
	{
		auto poly = Polygon();

		int indexCount = m_nativeMesh->GetPolygonSize(i);
		poly.Indices = gcnew array<int>(indexCount);

		for(int j = 0; j < indexCount; j++)
			poly.Indices[j] = m_nativeMesh->GetPolygonVertex(i, j);

		list[i] = poly;
	}

	return list;
}

array<Vector3> ^Mesh::Vertices::get()
{
	int count = m_nativeMesh->GetControlPointsCount();
	auto list = gcnew array<Vector3>(count);

	for(int i = 0; i < count; i++)
	{
		auto point =  m_nativeMesh->GetControlPointAt(i);
		list[i] = Vector3(point);
	}

	return list;
}

array<Vector3> ^Mesh::Normals::get()
{
	auto normals = m_nativeMesh->GetLayer(0)->GetNormals();
	int count = normals->GetDirectArray().GetCount();
	auto list = gcnew array<Vector3>(count);

	for(int i = 0; i < count; i++)
	{
		list[i] = Vector3(normals->GetDirectArray().GetAt(i));
	}

	return list;
}

array<Vector2> ^Mesh::TextureCoords::get()
{
	auto coords = m_nativeMesh->GetLayer(0)->GetUVs();
	int count = coords->GetDirectArray().GetCount();
	auto list = gcnew array<Vector2>(count);

	for(int i = 0; i < count; i++)
	{
		list[i] = Vector2(coords->GetDirectArray().GetAt(i));
	}

	return list;
}

int Mesh::GetUVIndex(int polygon, int index)
{
	return m_nativeMesh->GetTextureUVIndex(polygon, index);
}