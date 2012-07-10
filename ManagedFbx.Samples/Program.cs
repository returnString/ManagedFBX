using System;
using System.Windows.Forms;
using ManagedFbx;

public class Program
{
	[STAThread]
	public static void Main()
	{
		var scene = Scene.Import("samplefile.fbx");

		Application.EnableVisualStyles();
		Application.Run(new FbxForm(scene));
	}
}