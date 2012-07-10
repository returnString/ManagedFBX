using System;
using System.Windows.Forms;
using ManagedFbx;

public class Program
{
	[STAThread]
	public static void Main()
	{
		Application.EnableVisualStyles();
		Application.Run(new FbxForm());
	}
}