using System;
using System.Linq;
using System.Windows.Forms;
using ManagedFbx;

public partial class FbxForm : Form
{
	public FbxForm(Scene scene)
	{
		InitializeComponent();
		Add(scene.RootNode, null);
	}

	public void Add(SceneNode node, TreeNode parentNode)
	{
		var item = new TreeNode(node.Name) { Tag = node };

		if(parentNode == null)
			uxFbxTree.Nodes.Add(item);
		else
			parentNode.Nodes.Add(item);

		foreach(var sub in node.ChildNodes)
		{
			var subitem = new TreeNode(sub.Name) { Tag = sub };
			Add(sub, item);
		}
	}

	private void Append(string format, params object[] args)
	{
		uxNodeInfo.AppendText(string.Format(format, args));
		Newline();
	}

	private void Newline(int count = 1)
	{
		for(var i = 0; i < count; i++)
			uxNodeInfo.AppendText(Environment.NewLine);
	}

	private void OnTreeSelect(object sender, TreeViewEventArgs e)
	{
		var node = e.Node.Tag as SceneNode;

		uxNodeInfo.Clear();

		if(node == null)
			return;

		var newline = Environment.NewLine;

		Append("Position: {0}", node.Position);
		Append("Rotation: {0}", node.Rotation);
		Append("Scale: {0}", node.Scale);

		Newline();

		Append("Found {0} attribute(s)", node.Attributes.Count());

		foreach(var attr in node.Attributes)
		{
			Append(attr.AttributeType.ToString());
			Newline();

			switch(attr.AttributeType)
			{
				case NodeAttributeType.Mesh:
					{
						var mesh = node.Model;
						Append("Found {0} polygons", mesh.Polygons.Length);
						Newline();

						foreach(var poly in mesh.Polygons)
						{
							foreach(var index in poly.Indices)
								uxNodeInfo.AppendText(index + " ");

							Newline();
						}

						Newline();
						Append("Found {0} vertices", mesh.Vertices.Length);
						Newline();

						foreach(var vertex in mesh.Vertices)
						{
							Append(vertex.ToString());
						}
					}
					break;
			}
		}
	}
}
