#pragma once

#include <fbxsdk.h>
#include "Properties.h"

using namespace System;

namespace ManagedFbx
{
	public value struct Vector3
	{
	public:
		Vector3(double x, double y, double z)
		{
			X = x;
			Y = y;
			Z = z;
		}

		property double X;
		property double Y;
		property double Z;

		operator FbxDouble3()
		{
			return FbxDouble3(X, Y, Z);
		}

		virtual String ^ToString() override
		{
			return String::Format("{0}, {1}, {2}", Math::Round(X, 3), Math::Round(Y, 3), Math::Round(Z, 3));
		}

	internal:
		Vector3(FbxDouble3 fbxDouble)
		{
			X = fbxDouble[0];
			Y = fbxDouble[1];
			Z = fbxDouble[2];
		}
	};
}