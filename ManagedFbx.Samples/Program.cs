using System;
using System.Windows.Forms;
using ManagedFbx;

public class Program
{
	[STAThread]
	public static void Main()
	{
		var manager = new Manager();
		var scene = manager.ImportScene("samplefile.fbx");

		Application.EnableVisualStyles();
		Application.Run(new FbxForm(scene));
	}
}