#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <unistd.h>

#include "./classes/header.cpp"
#include "./classes/page.cpp"
#include "./classes/footer.cpp"

using namespace std;

int main(void){
    Header h;
    Page p;
    Footer f;

    char tmp[256];
    string path = getcwd(tmp, 256);
    ofstream html(path + "\\website\\index.html");
    ofstream css(path + "\\website\\style.css");
    
    h.chooseHeader({"Home", "Blog", "Contact"});
    p.choosePage();
    f.chooseFooter("Ahmad Tiga");

    css << "body {text-align: center; background-color: teal;}";
    css << h.getCss();
    css << p.getCss();
    css << f.getCss();
    html << "<!DOCTYPE html> <html lang=\"en\"> <head> <title>dots tech</title> <link rel=\"stylesheet\" href=\"style.css\"/> </head> <body>";
    
    html << h.getHtml();
    html << p.getHtml();
    html << f.getHtml();
    html << "</body></html>";

}