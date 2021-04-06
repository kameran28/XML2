#include <iostream>
#include "tinyxml2.h"
using namespace tinyxml2;
using namespace std;
int main() {
  std::cout << "learning\n";
  XMLDocument doc;

  doc.LoadFile("store.xml");
  //XMLNodeList mylist=doc.FirstChildElement("store")->ChildElement("item");
  XMLElement* item1=doc.FirstChildElement("store")->FirstChildElement("Item");
  string item1text = item1->GetText();
  int item1qty = stoi(item1->Attribute("quantity"));

  const XMLElement* item2=item1->NextSiblingElement("Item");
  string item2text = item2->GetText();
 int item2qty = stoi(item2->Attribute("quantity"));

 const XMLElement* item3=item2->NextSiblingElement("Item");
  string item3text = item3->GetText();
int item3qty = stoi(item3->Attribute("quantity"));

  cout<<"\nWelcome to the backpackstore\n";

  int choice;
  do {
    cout<<"please choose which item to buy or 0 to quit\n";
    cout<<"1:"<<item1text<< " Qty:" << item1qty<< endl;
    cout<<"2:"<<item1text<< " Qty:" << item2qty<< endl;
    cout<<"3:"<<item1text<< " Qty:" << item3qty<< endl;
    cout<<"0: quit\n";
    cin>>choice;
    if (choice == 1)
    {
      item1->set


    }
    else if (choice==2)
    {
      //
    }
    else if (choice ==3)
    {
      //
    }
    else if (choice !=0)
    {
      cout<<"Invalid option\n";
    }

  } while(choice!=0);

  //item2->SetText("new text");
  doc.SaveFile("updatedstore.xml");
}
/*
<ToDo>
    <!-- Do I need a secure PDA? -->
    <Item priority="1" distance="close">Go to the
        <bold>Toy store!</bold>
    </Item>
    <Item priority="2" distance="none">Do bills</Item>
    <Item priority="2" distance="far &amp; back">Look for Evil Dinosaurs!</Item>
</ToDo>
*/