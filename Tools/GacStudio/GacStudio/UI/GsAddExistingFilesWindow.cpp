﻿/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::AddExistingFilesWindow

This file is generated by: Vczh GacUI Resource Code Generator
***********************************************************************/

#include "GacStudioUI.h"

using namespace vl::reflection::description;

namespace ui
{
	// #region CLASS_MEMBER_GUIEVENT_HANDLER (DO NOT PUT OTHER CONTENT IN THIS #region.)

	void AddExistingFilesWindow::buttonAdd_Clicked(GuiGraphicsComposition* sender, vl::presentation::compositions::GuiEventArgs& arguments)
	{
		if (dialogOpen->ShowDialog())
		{
			GetOperationModel()->AddFiles(dialogOpen->GetFileNames());
		}
	}

	void AddExistingFilesWindow::buttonCancel_Clicked(GuiGraphicsComposition* sender, vl::presentation::compositions::GuiEventArgs& arguments)
	{
		Close();
	}

	void AddExistingFilesWindow::buttonOK_Clicked(GuiGraphicsComposition* sender, vl::presentation::compositions::GuiEventArgs& arguments)
	{
		auto model = GetViewModel();
		auto action = GetAction();
		auto files = GetLazyList<Ptr<vm::StudioFileReference>>(GetOperationModel()->GetSelectedFiles());
		if (model->SafeExecute([=]()
			{
				model->AddExistingFiles(action, files);
			}))
		{
			Close();
		}
	}

	void AddExistingFilesWindow::buttonRemove_Clicked(GuiGraphicsComposition* sender, vl::presentation::compositions::GuiEventArgs& arguments)
	{
		GetOperationModel()->RemoveFiles(dataGridFiles->GetSelectedItems());
	}

	// #endregion CLASS_MEMBER_GUIEVENT_HANDLER

	AddExistingFilesWindow::AddExistingFilesWindow(Ptr<vm::IStudioModel> ViewModel, Ptr<vm::IStudioAddExistingFilesModel> OperationModel, Ptr<vm::IAddFileItemAction> Action)
	{
		InitializeComponents(ViewModel, OperationModel, Action);
	}
}
