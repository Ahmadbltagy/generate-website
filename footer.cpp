#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Footer
{
private:
    string htmlCode, cssCode;

public:
    void chooseFooter(string websiteName)
    {
        cout << "Footer 1: \n"
                "---------------------------------------------------\n"
                "         (websiteName) all rights reserved         \n"
                "---------------------------------------------------\n"
                "Footer 2: \n"
                "---------------------------------------------------\n"
                "             (Footer background color)             \n"
                "         (websiteName) all rights reserved         \n"
                "---------------------------------------------------\n";

        int footerNumber;
        cout << "Choose your prefered footer: ";
        cin >> footerNumber;
        generateCode(footerNumber, websiteName);
    }
    void generateCode(int footerNumber, string websiteName)
    {
        htmlCode = "<footer> <p>";
        htmlCode += websiteName;
        htmlCode += " all rights reserved </p> </footer>";                  
        cssCode = "<head><style>footer{text-align: center; font-size: 60px;   border-radius: 10px; ";
        if (footerNumber == 2)
        {
            string backFooterColor, textFooterColor;
            cout << "Footer background-color: ";
            cin >> backFooterColor;
            cout << "Footer text color: ";
            cin >> textFooterColor;
            cssCode += "background-color: " + backFooterColor;
            cssCode += "; color: " + textFooterColor + ";";
        }
        cssCode += "}</style></head>";
    }
    string getHtml()
    {
        return htmlCode;
    }
    string getCss()
    {
        return cssCode;
    }
};

    