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
			this.uxTranslationLabel = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// uxFbxTree
			// 
			this.uxFbxTree.Location = new System.Drawing.Point(12, 12);
			this.uxFbxTree.Name = "uxFbxTree";
			this.uxFbxTree.Size = new System.Drawing.Size(403, 490);
			this.uxFbxTree.TabIndex = 0;
			this.uxFbxTree.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.OnTreeSelect);
			// 
			// uxTranslationLabel
			// 
			this.uxTranslationLabel.AutoSize = true;
			this.uxTranslationLabel.Location = new System.Drawing.Point(421, 12);
			this.uxTranslationLabel.Name = "uxTranslationLabel";
			this.uxTranslationLabel.Size = new System.Drawing.Size(24, 13);
			this.uxTranslationLabel.TabIndex = 1;
			this.uxTranslationLabel.Text = "pos";
			// 
			// FbxForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(839, 514);
			this.Controls.Add(this.uxTranslationLabel);
			this.Controls.Add(this.uxFbxTree);
			this.Name = "FbxForm";
			this.Text = "FbxForm";
			this.ResumeLayout(false);
			this.PerformLayout();

	}

	#endregion

	private System.Windows.Forms.TreeView uxFbxTree;
	private System.Windows.Forms.Label uxTranslationLabel;

}