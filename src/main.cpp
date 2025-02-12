
#include <wx/wx.h>
#include "P4Projekt.h"  // Include your wxFormBuilder-generated header

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public MyFrame1 {  // ✅ Use MyFrame1 instead of MainFrame
public:
    MyFrame(wxWindow* parent) : MyFrame1(parent) {
        // Custom initialization if needed
    }
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame(nullptr);
    frame->Show();
    return true;
}
