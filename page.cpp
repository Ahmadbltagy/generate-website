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
        string videoLink;
        cout << "Type the link of video: ";
        cin >> videoLink;
        htmlCode = "<main> <table> <tr> ";
        htmlCode += "<td><iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/" + videoLink + "\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe></td>";
        if (pageNumber == 1)
        {
            cout << "Type the link of second video: ";
            cin >> videoLink;
            htmlCode += "<td><iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/" + videoLink + "\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe></td>";
        }
        else
        {
            string text;
            cout << "Type a text: ";
            getchar();
            getline(cin, text);
            htmlCode += "<td> <p> " + text + " </p> </td>";
        }
        htmlCode += "</tr> </table> </main>";
    }
    string getHtml()
    {
        return htmlCode;
    }
};

int main()
{
    Page p;
    ofstream html("index.html");
    p.choosePage();
    html << p.getHtml();

    html.close();
}