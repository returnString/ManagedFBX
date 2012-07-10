#pragma once

namespace ManagedFbx
{
	public value struct Polygon
	{
	public:
		property_ri(array<int>^, Indices);

	private:
		array<int>^ m_indices;
	};
}