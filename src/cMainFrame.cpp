/*
 *  HomeAdmin - Home Linux server administration tool.
 *
 *  HomeAdmin is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  HomeAdmin is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with HomeAdmin.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "globalConst.h"
#include "cMainFrame.h"

enum
{
    ID_SERVER_LIST = 10001
};

wxBEGIN_EVENT_TABLE(cMainFrame, wxFrame)
    EVT_MENU(wxID_ADD, cMainFrame::OnServerAdd)
    EVT_MENU(wxID_EXIT, cMainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, cMainFrame::OnAbout)
    EVT_MENU(wxID_REMOVE, cMainFrame::OnServerRemove)
    EVT_TREE_SEL_CHANGED(ID_SERVER_LIST, cMainFrame::OnServerSelect)
wxEND_EVENT_TABLE()

cMainFrame::cMainFrame() : wxFrame(nullptr, wxID_ANY, "HomeAdmin")
{
    /*  
     *  Init cMainFrame Function
     */
    
    fileMenu = new wxMenu;
    fileMenu->Append(wxID_ADD, "Add Server\tCtrl+N");
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT);

    helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT);

    menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");

    SetMenuBar(menuBar);

    toolBar = this->CreateToolBar();
    toolBar->AddTool(wxID_ADD, "Add Server", wxArtProvider::GetBitmap(wxART_PLUS, wxART_TOOLBAR), "Add new server");
    toolBar->AddTool(wxID_REMOVE, "Delete Server", wxArtProvider::GetBitmap(wxART_MINUS, wxART_TOOLBAR), "Remove selected server");

    topSizer = new wxBoxSizer(wxHORIZONTAL);

    serverTree = new wxTreeCtrl(this, ID_SERVER_LIST, wxDefaultPosition, wxSize(250, 600));
    serverTree->AddRoot("Servers");
    serverTree->ExpandAll();
    topSizer->Add(serverTree, 0, wxEXPAND);
    contentSizer = new wxBoxSizer(wxVERTICAL);
    topSizer->Add(contentSizer, 1, wxEXPAND);
    button = new wxButton(this, wxID_ANY, "Test", wxDefaultPosition, wxSize(450, 500));
    contentSizer->Add(button, 1, wxEXPAND);

    this->SetSizerAndFit(topSizer);
}

void cMainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
    event.Skip();
}

void cMainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("HomeAdmin version " + VERSION_TYPE + " " + VERSION, "About", wxICON_INFORMATION | wxOK);
    event.Skip();
}

void cMainFrame::OnServerAdd(wxCommandEvent& event)
{
    wxTreeItemId newServer = serverTree->AppendItem(serverTree->GetRootItem(), "New Server");
    serverTree->Expand(serverTree->GetRootItem());
    serverTree->EditLabel(newServer);
    event.Skip();
}

void cMainFrame::OnServerRemove(wxCommandEvent& event)
{
    wxTreeItemId deleteServer = serverTree->GetSelection();
    if(serverTree->GetItemParent(deleteServer).IsOk())
    {
        wxMessageDialog confirm(this, "Do you really want to delete the server? This action will be irreversable!", "Attention", wxOK | wxCANCEL | wxCANCEL_DEFAULT | wxICON_QUESTION, wxDefaultPosition);
        if(confirm.ShowModal() == wxID_OK)
            serverTree->Delete(deleteServer);
    }
    event.Skip();
}

void cMainFrame::OnServerSelect(wxTreeEvent& event)
{
    if(serverTree->GetItemParent(event.GetItem()).IsOk())
    {
        button->SetLabel(serverTree->GetItemText(event.GetItem()));
    }
    event.Skip();
}
