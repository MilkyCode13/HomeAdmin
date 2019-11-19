/*
 *  This file is part of HomeAdmin.
 *
 *  HomeAdmin is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Foobar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with HomeAdmin.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "globalConst.h"
#include "cMainFrame.h"

cMainFrame::cMainFrame() : wxFrame(nullptr, wxID_ANY, "HomeAdmin")
{
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(wxID_EXIT);

    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");

    SetMenuBar(menuBar);

    Bind(wxEVT_MENU, &cMainFrame::OnExit, this, wxID_EXIT);

    Bind(wxEVT_MENU, &cMainFrame::OnAboutMenuOptionClick, this, wxID_ABOUT);

    wxBoxSizer *topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(new wxTreeCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(250, 600)), 0, wxEXPAND);
    wxBoxSizer *inSizer = new wxBoxSizer(wxVERTICAL);
    topSizer->Add(inSizer, 1, wxEXPAND);
    inSizer->Add(new wxButton(this, wxID_ANY, "Test",wxDefaultPosition, wxSize(450, 500)), 1, wxEXPAND);

    this->SetSizerAndFit(topSizer);
}

void cMainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
    event.Skip();
}

void cMainFrame::OnAboutMenuOptionClick(wxCommandEvent& event)
{
    wxMessageBox("HomeAdmin version " + VERSION_TYPE + " " + VERSION, "About", wxICON_INFORMATION | wxOK);
    event.Skip();
}
