#pragma once

#include "Scene.h"

namespace ManagedFbx
{
	ref class Manager abstract sealed
	{
	public:
		static Manager();
		static FbxManager *GetInstance();
		static FbxImporter *GetImporter();
		static FbxExporter *GetExporter();
		static FbxGeometryConverter *GetGeomConverter();

	private:
		static FbxManager *m_nativeManager;
		static FbxImporter *m_nativeImporter;
		static FbxExporter *m_nativeExporter;
		static FbxGeometryConverter *m_nativeGeomConv;
	};
}