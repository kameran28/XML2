#include <iostream>
#include <algorithm> 
#include <vector>
#include <map>

using namespace std;

/*
 *  Provides some utility functions used by other classes
 */
class Utils {
public:
    static map<string, string> get_value_map(vector<string>& params) {
        map<string, string> provided_values;
        for (int i=0; i < params.size(); ++i) {
            vector<string> key_value = split(params[i], '=');
            string key = key_value[0], value = key_value[1];
            provided_values[key] = value;
        }
        return provided_values;
    }

    static void print_product(int id, string name, double price, string description, string image_url) {
        cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "Product" << endl;
        cout << "ID           :  " << id << endl;
        cout << "Name         :  " << name << endl;
        cout << "==========================================" << endl;
        cout << "Price        :  " << price << endl;
        cout << "Description  :  " << description << endl;
        cout << "Image URL    :  " << image_url << endl;
        cout << "------------------------------------------" << endl;
        cout << endl;
    }

    static void print_vector(vector<string>& v) {
        for (auto it=v.begin(); it < v.end(); it++) {
            cout << *it << " ";
        }
    }

    static vector<string> split(string str, char del) {
        vector<string> parts;
        int part_num = 0;
        parts.push_back("");
        for(int i=0; i < str.length(); ++i) {
            if (str[i] == del) {
                parts.push_back("");
                part_num += 1;
            } else {
                parts[part_num] = parts[part_num] + (str[i]);
            }
        }
        return parts;
    }

    static string to_upper_case(string input) {
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        return input;
    }
};