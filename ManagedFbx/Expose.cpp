#include "stdafx.h"

namespace FbxSdk
{
	public ref class Expose
	{
	public:
		static System::String ^ManagedTest()
		{
			auto test = "rawr";
			return gcnew System::String(test);
		}

		static void Load(System::String ^filepath)
		{
			auto manager = FbxManager::Create();
			auto scene = FbxScene::Create(manager, "Scene");
		}
	};
}