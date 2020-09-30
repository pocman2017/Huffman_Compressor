#pragma once

#include "Haffman.h"
#include "Container.h"
//#using <mscorlib.dll>
//#include "msclr\marshal_cppstd.h"

namespace Huf {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices; //Marshal здесь

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^  treeView;
	private: System::Windows::Forms::ComboBox^  comboBoxDrive;
	protected:

	private: System::Windows::Forms::MenuStrip^  menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  packToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  unpackToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  packToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  unpackToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tableToolStripMenuItem;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ToolStripMenuItem^ таблицаToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->treeView = (gcnew System::Windows::Forms::TreeView());
			this->contextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->packToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->unpackToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->comboBoxDrive = (gcnew System::Windows::Forms::ComboBox());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->packToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->unpackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->таблицаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip->SuspendLayout();
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// treeView
			// 
			this->treeView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->treeView->ContextMenuStrip = this->contextMenuStrip;
			this->treeView->Location = System::Drawing::Point(28, 54);
			this->treeView->Name = L"treeView";
			this->treeView->Size = System::Drawing::Size(409, 379);
			this->treeView->TabIndex = 0;
			this->treeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MyForm::treeView_AfterSelect);
			// 
			// contextMenuStrip
			// 
			this->contextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->packToolStripMenuItem1,
					this->unpackToolStripMenuItem1, this->deleteToolStripMenuItem, this->таблицаToolStripMenuItem
			});
			this->contextMenuStrip->Name = L"contextMenuStrip";
			this->contextMenuStrip->Size = System::Drawing::Size(140, 92);
			// 
			// packToolStripMenuItem1
			// 
			this->packToolStripMenuItem1->Name = L"packToolStripMenuItem1";
			this->packToolStripMenuItem1->Size = System::Drawing::Size(139, 22);
			this->packToolStripMenuItem1->Text = L"Упаковать";
			this->packToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::packToolStripMenuItem1_Click);
			// 
			// unpackToolStripMenuItem1
			// 
			this->unpackToolStripMenuItem1->Name = L"unpackToolStripMenuItem1";
			this->unpackToolStripMenuItem1->Size = System::Drawing::Size(139, 22);
			this->unpackToolStripMenuItem1->Text = L"Распаковать";
			this->unpackToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::unpackToolStripMenuItem1_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->deleteToolStripMenuItem->Text = L"Удалить";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deleteToolStripMenuItem_Click);
			// 
			// comboBoxDrive
			// 
			this->comboBoxDrive->FormattingEnabled = true;
			this->comboBoxDrive->Location = System::Drawing::Point(28, 27);
			this->comboBoxDrive->Name = L"comboBoxDrive";
			this->comboBoxDrive->Size = System::Drawing::Size(63, 21);
			this->comboBoxDrive->TabIndex = 1;
			this->comboBoxDrive->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxDrive_SelectedIndexChanged);
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(459, 24);
			this->menuStrip->TabIndex = 2;
			this->menuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->packToolStripMenuItem,
					this->unpackToolStripMenuItem, this->tableToolStripMenuItem, this->toolStripMenuItem1, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->fileToolStripMenuItem->Text = L"Файл";
			// 
			// packToolStripMenuItem
			// 
			this->packToolStripMenuItem->Name = L"packToolStripMenuItem";
			this->packToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->packToolStripMenuItem->Text = L"Упаковать";
			this->packToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::packToolStripMenuItem1_Click);
			// 
			// unpackToolStripMenuItem
			// 
			this->unpackToolStripMenuItem->Name = L"unpackToolStripMenuItem";
			this->unpackToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->unpackToolStripMenuItem->Text = L"Распаковать";
			this->unpackToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::unpackToolStripMenuItem1_Click);
			// 
			// tableToolStripMenuItem
			// 
			this->tableToolStripMenuItem->Name = L"tableToolStripMenuItem";
			this->tableToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->tableToolStripMenuItem->Text = L"Извлечь таблицу весов";
			this->tableToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tableToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(190, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->exitToolStripMenuItem->Text = L"Выход";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(101, 27);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Упаковать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::packToolStripMenuItem1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(183, 28);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(81, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Распаковать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::unpackToolStripMenuItem1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(271, 28);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Таблица весов";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::tableToolStripMenuItem_Click);
			// 
			// таблицаToolStripMenuItem
			// 
			this->таблицаToolStripMenuItem->Name = L"таблицаToolStripMenuItem";
			this->таблицаToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->таблицаToolStripMenuItem->Text = L"Таблица";
			this->таблицаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tableToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(459, 445);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBoxDrive);
			this->Controls->Add(this->treeView);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"MyForm";
			this->Text = L"Архиватор ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->contextMenuStrip->ResumeLayout(false);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//Заполнить текущую ветку дерева
		void fillSubTree(String^ root, TreeNode^ node)
		{
			node->Nodes->Clear();
			//Получить список каталогов
			try
			{
				for each(String^ dir in Directory::GetDirectories(root))
				{
					TreeNode^ newnode = node->Nodes->Add(dir, Path::GetFileName(dir));
					newnode->BackColor = Color::LightBlue;
				}
			}
			catch (...) {}; //Может и не получиться.

							 //Получить список файлов
			try
			{
				for each(String^ file in Directory::GetFiles(root))
				{
					TreeNode^ newnode = node->Nodes->Add(file, Path::GetFileName(file));
					newnode->BackColor = Color::White;
				}
			}
			catch (...) {}

		}

		//Выбрать укзанный файл
		void SetSelectedNode(String^ nodeName)
		{
			int p = nodeName->IndexOf("\\");
			nodeName = nodeName->Remove(0, p+1);
			if (nodeName == "") return; //Что то пошло немного не так и это - корень
			if (nodeName[0]=='\\') nodeName = nodeName->Remove(0, 1);
			p = nodeName->IndexOf("\\");
			if (p < 0) p = nodeName->Length;
			String^ text = nodeName->Substring(0, p);
			for each (TreeNode^ node in treeView->SelectedNode->Nodes)
			{
				if (node->Text == text)
				{
					treeView->SelectedNode = node;
					SetSelectedNode(nodeName);
					break;
				}
			}

		}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		String^ current = Application::ExecutablePath;
		String^ drive = current->Substring(0, 3);
		comboBoxDrive->Items->Clear();
		for each(auto d in Environment::GetLogicalDrives())
		{
			comboBoxDrive->Items->Add(d);
		}
		try
		{
			comboBoxDrive->SelectedIndex = comboBoxDrive->Items->IndexOf(drive);
			//Найти и сделать SelectedNode текущий каталог
			String^ currentFolder = Path::GetDirectoryName(current);
			treeView->SelectedNode = treeView->Nodes[0];
			SetSelectedNode(currentFolder);
		}
		catch (...)
		{
			comboBoxDrive->SelectedIndex = 0;
		}



	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Close();
	}
	private: System::Void comboBoxDrive_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		//Выбран диск. Заполнить.
		treeView->Nodes->Clear();
		TreeNode^ root = treeView->Nodes->Add(comboBoxDrive->Text, comboBoxDrive->Text);
		fillSubTree(comboBoxDrive->Text, root);
		root->Expand();
	}
	private: System::Void treeView_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e)
	{
		//Выбран узел в дереве, заполнить на один уровень вниз
		fillSubTree(treeView->SelectedNode->FullPath, treeView->SelectedNode);
		treeView->SelectedNode->Expand();
	}

			 Haffman * h;

	private: System::Void packToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Упаковать
		if (treeView->SelectedNode == nullptr) return; //Странное

		h = new Haffman();
		String^ fileName = treeView->SelectedNode->FullPath;

		//Если это каталог, то ничего не делать
		if (Directory::Exists(fileName))
		{
			MessageBox::Show("Только файлы!","Не могу");
			return;
		}

		char * fName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
		h->LoadSource(fName); //Загрузить исходный текст
		Marshal::FreeHGlobal((IntPtr)fName); //Освободить Маршала

		h->Pack(); //упаковать
		fileName += ".ha"; //Добавить расширение "архив huffman"
		fName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
		h->SaveTarget(fName);
		Marshal::FreeHGlobal((IntPtr)fName); //Освободить Маршала

		delete h;

		//Обновить содержимое каталога
		//fillSubTree(treeView->SelectedNode->Parent->FullPath, treeView->SelectedNode->Parent);
		treeView->SelectedNode = treeView->Nodes[0];
		SetSelectedNode(fileName);

	}
	private: System::Void unpackToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Распаковать
		//аналогично упаковке
		if (treeView->SelectedNode == nullptr) return; //Странное
		h = new Haffman();
		String^ fileName = treeView->SelectedNode->FullPath;

		//Если это каталог, то ничего не делать
		if (Directory::Exists(fileName))
		{
			MessageBox::Show("Только файлы!", "Не могу");
			return;
		}

		char * fName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
		int v = h->LoadTarget(fName); //Загрузить архив
		Marshal::FreeHGlobal((IntPtr)fName); //Освободить Маршала

		switch (v)
		{
		case 1:
			MessageBox::Show(fileName, "Проблемы");
			break;
		case 2:
			MessageBox::Show(fileName, "Это не архив");
			break;
		default:
			h->Unpack(); //распаковать
			fileName += ".unpack"; //Добавить расширение "распакован"
			fName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
			h->SaveSource(fName);
			Marshal::FreeHGlobal((IntPtr)fName); //Освободить Маршала
			break;
		} 

		delete h;
		//Обновить содержимое каталога
		//fillSubTree(treeView->SelectedNode->Parent->FullPath, treeView->SelectedNode->Parent);
		treeView->SelectedNode = treeView->Nodes[0];
		SetSelectedNode(fileName);

	}
	private: System::Void deleteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//Удалить файл под курсором
		String^ fileName = treeView->SelectedNode->FullPath;
		if (MessageBox::Show(fileName, "Удалить?", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
		{
			try
			{
				if (File::Exists(fileName)) File::Delete(fileName);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Не получилось", 
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
			}
		}
		//Обновить содержимое каталога
		//fillSubTree(treeView->SelectedNode->Parent->FullPath, treeView->SelectedNode->Parent);
		treeView->SelectedNode = treeView->Nodes[0];
		SetSelectedNode(Path::GetDirectoryName(fileName));

	}
private: System::Void tableToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Извлечь таблицу весов из выбранного файла
	if (treeView->SelectedNode == nullptr) return; //Странное
	h = new Haffman();
	String^ fileName = treeView->SelectedNode->FullPath;

	//Если это каталог, то ничего не делать
	if (Directory::Exists(fileName))
	{
		MessageBox::Show("Только файлы!", "Не могу");
		return;
	}

	char* fName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
	int v = h->LoadTarget(fName); //Загрузить архив
	Marshal::FreeHGlobal((IntPtr)fName); //Освободить Маршала

	switch (v)
	{
	case 1:
		MessageBox::Show(fileName, "Проблемы");
		break;
	case 2:
		MessageBox::Show(fileName, "Это не архив");
		break;
	default:

		//h->Unpack(); //распаковать

		fileName += ".table"; //Добавить расширение "таблица"
		fName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
		h->SaveTable(fName);
		Marshal::FreeHGlobal((IntPtr)fName); //Освободить Маршала
		break;
	}

	delete h;
	//Обновить содержимое каталога
	//fillSubTree(treeView->SelectedNode->Parent->FullPath, treeView->SelectedNode->Parent);
	treeView->SelectedNode = treeView->Nodes[0];
	SetSelectedNode(fileName);

}
};
}
