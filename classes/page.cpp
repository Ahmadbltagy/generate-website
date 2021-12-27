#include <iostream>
#include <string>

using namespace std;

class Page
{
private:
    string htmlCode, cssCode;

public:
    void choosePage()
    {
        cout << "Page 1: \n"
                "------------------------------------------------\n"
                "|       Youtube Video   |      Youtube Video   |\n"
                "------------------------------------------------\n"
                "Page 2: \n"
                "------------------------------------------------\n"
                "|       Youtube Video      |      Text         |\n"
                "------------------------------------------------\n"
                "Chosse Number: ";
        int pageNumber;
        cin >> pageNumber;
        generateCode(pageNumber);
    }
    void generateCode(int pageNumber)
    {
        htmlCode = "<main> <center><table>  ";
        cssCode = "main {margin: 50px 0;}";

        string videoLink;
        more:
        cout << "Type the link of video: ";
        cin >> videoLink;
        htmlCode += "<tr> <td><iframe width=\"auto\" height=\"auto\" src=\"https://www.youtube.com/embed/" + videoLink + "\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe></td>";
        if (pageNumber == 1)
        {
            cout << "Type the link of second video: ";
            cin >> videoLink;
            htmlCode += "<td><iframe width=\"auto\" height=\"auto\" src=\"https://www.youtube.com/embed/" + videoLink + "\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe></td> </tr>";
            
            cout<<"Do you need to add more videos (y/n): ";
            string ans;
            cin >> ans;
            if(ans == "y"){
                goto more;
        }
        }
      
        else
        {
            string text;
            cout << "Type a text: ";
            getchar();
            getline(cin, text);
            htmlCode += "<td> <p> " + text + " </p> </td></tr>";
        }
        htmlCode += " </table> </center></main>";
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
