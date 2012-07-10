using System;
using System.Linq;
using System.Text;
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




	private void OnTreeSelect(object sender, TreeViewEventArgs e)
	{
		var node = e.Node.Tag as SceneNode;

		if(node == null)
			return;

		var builder = new StringBuilder();

		Action NewLine = () => builder.Append(Environment.NewLine);

		builder.Append("Position: {0}", node.Position);
		builder.Append("Rotation: {0}", node.Rotation);
		builder.Append("Scale: {0}", node.Scale);

		NewLine();

		builder.Append("Found {0} attribute(s)", node.Attributes.Count());

		foreach(var attr in node.Attributes)
		{
			NewLine();
			builder.Append("Attribute type: {0}", attr.AttributeType.ToString());

			switch(attr.AttributeType)
			{
				case NodeAttributeType.Mesh:
					{
						var mesh = node.Model;
						builder.Append("Found {0} polygons", mesh.Polygons.Length);
						NewLine();

						for(var i = 0; i < mesh.Polygons.Length; i++)
						{
							var str = string.Empty;
							foreach(var index in mesh.Polygons[i].Indices)
								str += "\t" + index;

							builder.Append("{0}:{1}", i, str);
						}

						NewLine();
						builder.Append("Found {0} vertices", mesh.Vertices.Length);
						NewLine();

						for(var i = 0; i < mesh.Vertices.Length; i++)
						{
							var vertex =  mesh.Vertices[i];
							builder.Append("{0}:\t{1}\t{2}\t{3}", i, Math.Round(vertex.X, 2), Math.Round(vertex.Y, 2), Math.Round(vertex.Z, 2));
						}
					}
					break;
			}
		}

		uxNodeInfo.Text = builder.ToString();
	}
}

public static class StringBuilderExtensions
{
	public static void Append(this StringBuilder builder, string format, params object[] args)
	{
		builder.AppendLine(string.Format(format, args));
	}
}