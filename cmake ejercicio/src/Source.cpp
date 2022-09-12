#include "nlohmann/json.hpp"
#include <iostream>

using namespace std;
using json = nlohmann::json;

/*
 * Given a json object and an index reference
 * prints key value pair indexed. 
 * In case of nested objbects it´s indexed with a "." inbetween.
 */
void iterate_json(json myObject, string cur_index)
{
	//for each key in my json object
	for (auto& el : myObject.items())
	{
		//if my element is a json object, iterate throught it
		if (el.value().is_object())
		{
			//recursive call
			iterate_json(el.value(), cur_index + el.key() + ".");
		}
		else
			// show key value pair through command line
			cout << cur_index << el.key() << " = " << el.value() << endl;
	}
}

/*
 * Given text with JSON format 
 * it prints the key value pair 
 * concatenating the nested with "."
 */
void dictionary_of_JSON(string data)
{
	//parse json & start recursivity
	json myObject = json::parse(data);
	iterate_json(myObject, "");
}


int main() {
	string data = R"(
		{
			"a": true,
			"b": {
					"b1": "hello",
					"b2": 3.5
				 },
			"c": 3,
			"d": {
					"d1": "nice",
					"d2": {
								"d21": 546
						  }
				  }
		}
	)";

	dictionary_of_JSON(data);

}