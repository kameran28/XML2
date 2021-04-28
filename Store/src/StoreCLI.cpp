#include <iostream>
#include <map>
#include "Store.cpp"

using namespace std;

/*
 *  Provides the cli interface to interact with the system. Use Store.cpp functions under the hood
 */
class StoreCLI {
private:
    Store store; 
public:
    void process_commands(int argc, char** argv) {
        if (argc <= 1) {
            cout << "Enter an operation" << endl;
            cout << "You can do the below" << endl << endl;
            cout << "1. Add a new product" << endl;
            cout << "Usage: ./storecli add name=\"Fountain Pen\" ..." << endl << endl;
            cout << "2. Show a list of products" << endl;
            cout << "Usage: ./storecli show" << endl;
            cout << "Usage: ./storecli show id=\"1232\"" << endl;
            cout << "Usage: ./storecli show part_name=\"pen\"" << endl << endl;
            cout << "3. Edit a product" << endl;
            cout << "Usage: ./storecli edit name=\"The brand new InkPen\" " << endl << endl;
            cout << "4. Remove a product" << endl;
            cout << "Usage: ./storecli remove id=\"1232\"" << endl << endl;
        } else if (string(argv[1]) == "add") {
            vector<string> params;
            for (int i=2; i < argc; ++i) {
                params.push_back(string(argv[i]));
            }
            map<string, string> provided_values = Utils::get_value_map(params);
            if (!(provided_values.count("name") &&
                provided_values.count("price") &&
                provided_values.count("description") &&
                provided_values.count("image_url"))) {
                cout << "Error: Enter all the arguments of the product" << endl;
                return;
            }
            Product p(
                provided_values["name"],
                stod(provided_values["price"]),
                provided_values["description"],
                provided_values["image_url"]
            );
            store.add_product(p);
            cout << "Success: Product added to the store" << endl;
        } else if (string(argv[1]) == "remove") {
            vector<string> params;
            for (int i=2; i < argc; ++i) {
                params.push_back(string(argv[i]));
            }
            map<string, string> provided_values = Utils::get_value_map(params);
            if (!provided_values.count("id")) {
                cout << "Error: Enter id of the product to be removed" << endl;
                return;
            } else {
                store.remove_product(stoi(provided_values["id"]));
                cout << "Success: Product removed from the store" << endl;
            }
        } else if (string(argv[1]) == "edit") {
            vector<string> params;
            for (int i=2; i < argc; ++i) {
                params.push_back(string(argv[i]));
            }
            map<string, string> provided_values = Utils::get_value_map(params);
            store.edit_product(stoi(provided_values["id"]), provided_values);
            cout << "Success: Edited the product with given updated values" << endl;
        } else if (string(argv[1]) == "show") {
            if (argc == 2) {
                store.show_products();
            } else {
                vector<string> params;
                for (int i=2; i < argc; ++i) {
                    params.push_back(string(argv[i]));
                }
                map<string, string> provided_values = Utils::get_value_map(params);
                if (provided_values.count("id")) {
                    store.show_product(stoi(provided_values["id"]));
                } else {
                    store.show_products(provided_values["part_name"]);
                }
            }
        } else {
            cout << "Command/Format not supported :(" << endl;
        }
    }
};

int main(int argc, char** argv) {
    StoreCLI cli;
    cli.process_commands(argc, argv);
    return 0;
}