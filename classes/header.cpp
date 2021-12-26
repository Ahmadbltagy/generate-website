#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Header
{
private:
    string htmlCode, cssCode;
    int headerNum;
    string intToString(int num)
    {
        switch (num)
        {
        case 1:
            return "1";
            break;
        case 2:
            return "2";
            break;
        case 3:
            return "3";
            break;
        case 4:
            return "4";
            break;
        }
        return "5";
    }

public:
    void chooseHeader(vector<string> pageName)
    {
        cout << "Header 1: \n"
                "---------------------------------------\n"
                "|                Picture              |\n"
                "---------------------------------------\n"
                "|  Home  |  Contact  | About  | Blog  |\n"
                "---------------------------------------\n"
                "Header 2: \n"
                "---------------------------------------\n"
                "|  Home  |  Contact  | About  | Blog  |\n"
                "---------------------------------------\n"
                "Please, enter header number: ";
        cin >> headerNum;
        while (headerNum != 1 && headerNum != 2)
        {
            cout << "Please enter correct header number: ";
            cin >> headerNum;
        }
        generateCode(pageName);
    }
    void generateCode(vector<string> pageName)
    {

        cssCode = ".header-table {width =80%; margin-left: auto; margin-right: auto;}";
        cssCode += ".header-td {border: 2px solid black; color: black; text-align: center; font-size: 20px;} .header-a{text-decoration: none; color: black;}";

        htmlCode = "<table class=\"header-table\">";
        if (headerNum == 1)
        {
            string imgFileName;
            cout << "Enter image file name: ";
            cin >> imgFileName;
            htmlCode += "<tr> <td class=\"header-td\" colspan=\" " + intToString(pageName.size()) + "\"> <img class=\"header-img\" src=\" " + imgFileName + " \">" + "</td>  </tr>";

            cssCode += ".header-img {width: 100%; height: auto;} ";
        }
        htmlCode += "<tr>";
        //table content
        htmlCode += "<td class=\"header-td\"> <a class=\"header-a\" href=\"index.html\">" + pageName[0] + "</a> </td>";
        for (int i = 1; i < pageName.size(); i++)
            htmlCode += "<td class=\"header-td\"> <a class=\"header-a\" href=\"" + pageName[i] + ".html\">" + pageName[i] + "</td>";
        htmlCode += "</tr></table>";
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
