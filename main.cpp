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
    char sp[256] = "\website\index.html";
    string path = getcwd(tmp, 256) ;
    
    ofstream html("index.html");
    cout<< path;
    // h.chooseHeader();
    // p.choosePage();
    // f.chooseFooter();

}