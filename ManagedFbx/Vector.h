#pragma once

#include <fbxsdk.h>
#include "Properties.h"

using namespace System;

namespace ManagedFbx
{
	public value struct Colour
	{
	public:
		Colour(double r, double g, double b, double a)
		{
			R = r;
			G = g;
			B = b;
			A = a;
		}

		property double R;
		property double G;
		property double B;
		property double A;

		operator FbxColor()
		{
			return FbxColor(R, G, B, A);
		}

		virtual String ^ToString() override
		{
			return String::Format("{0}, {1}, {2}, {3}", Math::Round(R, 3), Math::Round(G, 3), Math::Round(B, 3), Math::Round(A, 3));
		}

	internal:
		Colour(FbxColor fbxColour)
		{
			R = fbxColour.mRed;
			G = fbxColour.mGreen;
			B = fbxColour.mBlue;
			A = fbxColour.mAlpha;
		}
	};

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

	public value struct Vector2
	{
		Vector2(double x, double y)
		{
			X = x;
			Y = y;
		}

		operator FbxDouble2()
		{
			return FbxDouble2(X, Y);
		}

		virtual String ^ToString() override
		{
			return String::Format("{0}, {1}", Math::Round(X, 3), Math::Round(Y, 3));
		}

		property double X;
		property double Y;

	internal:
		Vector2(FbxVector2 vector)
		{
			X = vector[0];
			Y = vector[1];
		}
	};

	public value struct Vector4
	{
		Vector4(double w, double x, double y, double z)
		{
			W = w;
			X = x;
			Y = y;
			Z = z;
		}

		operator FbxDouble4()
		{
			return FbxDouble4(X, Y, Z, W);
		}

		virtual String ^ToString() override
		{
			return String::Format("{0}, {1}, {2}, {3}", Math::Round(W, 3), Math::Round(X, 3), Math::Round(Y, 3), Math::Round(Z, 3));
		}

		property double W;
		property double X;
		property double Y;
		property double Z;
	};
}