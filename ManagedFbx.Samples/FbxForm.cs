using System.IO;
using System.Windows.Forms;
using ManagedFbx;

public partial class FbxForm : Form
{
	public FbxForm(Scene scene)
	{
		InitializeComponent();
		AllowDrop = true;
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

		uxTranslationLabel.Text = string.Format("Position: {0}\nRotation: {1}\nScale: {2}", node.Position, node.Rotation, node.Scale);
	}
}
