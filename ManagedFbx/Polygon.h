#pragma once

namespace ManagedFbx
{
	/// <summary>
	/// Represents a polygon.
	/// </summary>
	public value struct Polygon
	{
	public:
		/// <summary>
		/// Gets the array of indices which make up this polygon.
		/// </summary>
		property_ri(array<int>^, Indices);

	private:
		array<int>^ m_indices;
	};
}