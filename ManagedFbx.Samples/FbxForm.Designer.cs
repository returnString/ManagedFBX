partial class FbxForm
{
	/// <summary>
	/// Required designer variable.
	/// </summary>
	private System.ComponentModel.IContainer components = null;

	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
	protected override void Dispose(bool disposing)
	{
		if(disposing && (components != null))
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	#region Windows Form Designer generated code

	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	private void InitializeComponent()
	{
			this.uxFbxTree = new System.Windows.Forms.TreeView();
			this.uxNodeInfo = new System.Windows.Forms.TextBox();
			this.SuspendLayout();
			// 
			// uxFbxTree
			// 
			this.uxFbxTree.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
			this.uxFbxTree.Location = new System.Drawing.Point(12, 12);
			this.uxFbxTree.Name = "uxFbxTree";
			this.uxFbxTree.Size = new System.Drawing.Size(403, 619);
			this.uxFbxTree.TabIndex = 0;
			this.uxFbxTree.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.OnTreeSelect);
			// 
			// uxNodeInfo
			// 
			this.uxNodeInfo.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.uxNodeInfo.Location = new System.Drawing.Point(421, 12);
			this.uxNodeInfo.Multiline = true;
			this.uxNodeInfo.Name = "uxNodeInfo";
			this.uxNodeInfo.ReadOnly = true;
			this.uxNodeInfo.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.uxNodeInfo.Size = new System.Drawing.Size(565, 619);
			this.uxNodeInfo.TabIndex = 3;
			this.uxNodeInfo.WordWrap = false;
			// 
			// FbxForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(998, 643);
			this.Controls.Add(this.uxNodeInfo);
			this.Controls.Add(this.uxFbxTree);
			this.Name = "FbxForm";
			this.Text = "FbxForm";
			this.ResumeLayout(false);
			this.PerformLayout();

	}

	#endregion

	private System.Windows.Forms.TreeView uxFbxTree;
	private System.Windows.Forms.TextBox uxNodeInfo;

}