#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "../tinyxml2/tinyxml2.h" 
#include "Product.cpp"
#include "UniqueRandomNumberGenerator.cpp"
#include "Utils.cpp"
using namespace tinyxml2;

/*
 *  Does the operations of add, remove, edit, show using tinyxml2 api and stores the data in data/store.xml
 */
class Store {
private:
    XMLDocument store;
    XMLNode* products;
    UniqueRandomNumberGenerator urng;
    void save_to_file() {
        store.SaveFile("../data/store.xml");
    }
public:
    Store() {
        // check if file is empty and add a <products/> tag
        ifstream infile("../data/store.xml");
        if (infile.peek() == std::ifstream::traits_type::eof()) {
            infile.close();
            ofstream outfile("../data/store.xml");
            outfile.write("<products/>", 12);
        }

        // now load the file
        store.LoadFile("../data/store.xml");
        products = store.FirstChild();
    }

    void add_product(Product p) {
        XMLElement* product = store.NewElement("product");

        XMLElement* id = product->InsertNewChildElement("id");
        id->SetText(urng.generate());

        XMLElement* name = product->InsertNewChildElement("name");
        name->SetText(p.name.c_str());

        XMLElement* price = product->InsertNewChildElement("price");
        price->SetText(p.price);

        XMLElement* description = product->InsertNewChildElement("description");
        description->SetText(p.description.c_str());
        
        XMLElement* image_url = product->InsertNewChildElement("image_url");
        image_url->SetText(p.image_url.c_str());

        products->InsertEndChild(product);

        save_to_file();
    }

    void remove_product(int id) {
        XMLElement* product = products->FirstChildElement();
        while (product != NULL) {
            if (product->FirstChildElement("id")->GetText() == to_string(id)) {
                products->DeleteChild(product);
                break;
            }
            product = product->NextSiblingElement();
        }

        save_to_file();
    }

    void show_products() {
        XMLElement* element = products->FirstChildElement();
        while (element != NULL) {
            Utils::print_product(
                stoi(element->FirstChildElement("id")->GetText()),
                element->FirstChildElement("name")->GetText(),
                stod(element->FirstChildElement("price")->GetText()),
                element->FirstChildElement("description")->GetText(),
                element->FirstChildElement("image_url")->GetText());

            element = element->NextSiblingElement();
        }
    }

    void show_product(int id) {
        XMLElement* element = products->FirstChildElement();
        while (element != NULL) {            
            if (stoi(element->FirstChildElement("id")->GetText()) == id) {
                Utils::print_product(
                    stoi(element->FirstChildElement("id")->GetText()),
                    element->FirstChildElement("name")->GetText(),
                    stod(element->FirstChildElement("price")->GetText()),
                    element->FirstChildElement("description")->GetText(),
                    element->FirstChildElement("image_url")->GetText());
                break; // Has only one element with given ID, so break
            }
            
            element = element->NextSiblingElement();
        }
    }

    void show_products(string part_name) {
        XMLElement* element = products->FirstChildElement();
        while (element != NULL) {            
            if (Utils::to_upper_case(element->FirstChildElement("name")->GetText()).find(Utils::to_upper_case(part_name)) != string::npos) {
                Utils::print_product(
                    stoi(element->FirstChildElement("id")->GetText()),
                    element->FirstChildElement("name")->GetText(),
                    stod(element->FirstChildElement("price")->GetText()),
                    element->FirstChildElement("description")->GetText(),
                    element->FirstChildElement("image_url")->GetText());
            }

            element = element->NextSiblingElement();
        }
    }

    void edit_product(int id, map<string, string> updates) {
        XMLElement* element = products->FirstChildElement();
        while (element != NULL) {            
            if (stoi(element->FirstChildElement("id")->GetText()) == id) {
                if (updates.count("name")) {
                    element->FirstChildElement("name")->SetText(updates["name"].c_str());
                }

                if (updates.count("price")) {
                    element->FirstChildElement("price")->SetText(updates["price"].c_str());
                }

                if (updates.count("description")) {
                    element->FirstChildElement("description")->SetText(updates["description"].c_str());
                }

                if (updates.count("image_url")) {
                    element->FirstChildElement("image_url")->SetText(updates["image_url"].c_str());
                }
            }

            element = element->NextSiblingElement();
        }

        save_to_file();
    }
};